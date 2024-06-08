#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include "header.h"
static int c = 0;
extern int count(void){
	return c++;
}
EXPORT_SYMBOL(count);
static int __init exp_entry(void){
	printk(KERN_INFO "Exp Module initialized\n");
	return 0;
}
static void __exit exp_exit(void){
	printk(KERN_INFO "Exp module detached\n");
}

module_init(exp_entry);
module_exit(exp_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1");
MODULE_AUTHOR("ASHWIN");

