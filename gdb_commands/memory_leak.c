#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *create_buffer()
{
    char *p = malloc(64);
    strcpy(p, "Diagnostics buffer");
    return p;
}

void leak_memory()
{
    char *a = malloc(128);
    strcpy(a, "this memory is never freed");
}

void use_after_free()
{
    int *x = malloc(sizeof(int));
    *x = 99;
    free(x);
    *x = 42;
}

void crash()
{
    int *p = NULL;
    *p = 10;
}

int main()
{
    char *buf = create_buffer();
    leak_memory();
    use_after_free();
    crash();
    printf("%s\n", buf);
    free(buf);
    return 0;
}



/* Inference that I did:
I executed the program inside GDB using run.
The program crashed with a segmentation fault, which indicated an invalid memory access. (As I already did in line 12)

To determine where the crash occurred, I used bt to view the backtrace.
This showed the function call stack and helped me identify the exact function responsible for the crash.

Next, I used list to display the source code around the crashing line so I could visually inspect the suspicious statement.

To analyze execution, I set a breakpoint using break main so the program would pause at the beginning.
From there, I progressed sequentially using next to observe normal flow.

When the code approached functions related to memory handling, I used step to enter inside those functions and monitor their behavior more closely.

I knew pointer misuse, so I checked variable values using print ptr and print *p.
This revealed that the pointer contained NULL, that confirmed an invalid dereference as the cause of the crash. 

Then I used info locals to inspect all local variables and verify whether any memory looked uninitialized or corrupted.

After inspection, I continued execution using continue until the next breakpoint or crash.

To monitor suspicious variables automatically, I used watch ptr command. 

This helped track when the pointer changed value, letting me to pinpoint exactly where memory became invalid.

Finally, after identifying the faulty dereference and memory leak locations, I exited GDB using quit.
  */
