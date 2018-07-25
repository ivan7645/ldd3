#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

MODULE_LICENSE("Dual BSD/GPL");

static char *whom = "world_p";
static uint howmany = 1;
module_param(howmany, uint, S_IRUGO);
module_param(whom, charp, S_IRUGO);

static int hello_init(void)
{
	u32 i;

	for (i = 0; i < howmany; i++)
		printk(KERN_ALERT "Hello, %s\n", whom);

	printk(KERN_INFO "The current precess is \"%s\" (pid %i)\n",
	       current->comm, current->pid);

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "Goodbye, cruel world_p\n");
}

MODULE_LICENSE("Dual BSD/GPL");

module_init(hello_init);
module_exit(hello_exit);
