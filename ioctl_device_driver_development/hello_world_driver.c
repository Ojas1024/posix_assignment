#include <linux/module.h>
#include <linux/fs.h>

#define DEVICE "helloioctl"
#define HELLO_CMD _IO('a','a')

static int major;

static long device_ioctl(struct file *f, unsigned int cmd, unsigned long arg)
{
    if(cmd == HELLO_CMD)
        printk("Hello from kernel\n");
    return 0;
}

static struct file_operations fops =
{
    .unlocked_ioctl = device_ioctl
};

static int __init start(void)
{
    major = register_chrdev(0, DEVICE, &fops);
    return 0;
}

static void __exit end(void)
{
    unregister_chrdev(major, DEVICE);
}

module_init(start);
module_exit(end);
MODULE_LICENSE("GPL");
