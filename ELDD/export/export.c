#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include"header.h"

extern int sum(int a,int b){
	return a+b;
}
EXPORT_SYMBOL(sum);

extern int sub(int a,int b){
        return a-b;
}
EXPORT_SYMBOL(sub);

extern int mult(int a,int b){
        return a*b;
}
EXPORT_SYMBOL(mult);

extern int div(int a,int b){
	if(b==0){
	printk(KERN_ALERT "Floating point exception");
	return 1;
	}
	else
        return a/b;
}

EXPORT_SYMBOL(div);

static int __init fn_entry(void){
	printk(KERN_INFO "Export module attached\n");
	return 0;
}

static void __exit fn_exit(void){
        printk(KERN_INFO "Export module detached\n");
}

module_init(fn_entry);
module_exit(fn_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1");
MODULE_AUTHOR("ASHWIN");
