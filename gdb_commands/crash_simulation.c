#include <stdio.h>
#include <stdlib.h>

void level3(int *p)
{
    *p = 42;
}

void level2(int *p)
{
    level3(p);
}

void level1()
{
    int *ptr = NULL;
    level2(ptr);
}

int main()
{
    printf("Starting program\n");
    level1();
    printf("Done\n");
    return 0;
}


/*I've used commands like:
  run
  bt -> For backtrace
  list
  break main -> Break point setting
  next
  step
  print ptr
  print *p
  info locals -> For local variables
  continue
  watch ptr -> To keep a track on a specific variable. In my case, I did using ptr
  quit*/
