#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include"header.h"
static int a = 3300;
static int b = 1;

static int __init calc_entry(void){
	printk(KERN_ALERT "sum of %d and %d is %d\n",a,b,sum(a,b));
	printk(KERN_ALERT "sub of %d and %d is %d\n",a,b,sub(a,b));
	printk(KERN_ALERT "mult of %d and %d is %d\n",a,b,mult(a,b));
	printk(KERN_ALERT "div of %d and %d is %d\n",a,b,div(a,b));
	return 0;
}

static void __exit calc_exit(void){
	printk(KERN_INFO "Module detached\n");
}
module_init(calc_entry);
module_exit(calc_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1");
MODULE_AUTHOR("ASHWIN");
