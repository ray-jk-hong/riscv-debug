// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2026 Jk Hong <zaiguang.hong@riscv-computing.com>
 */
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/printk.h>

#include "rvd.h"

static ssize_t rvd_read(struct file *file, char __user *buf,
	size_t count, loff_t *ppos)
{
	return 0;
}

static ssize_t rvd_write(struct file *file, const char __user *buf,
	size_t count, loff_t *ppos)
{
	return count;
}

static int rvd_open(struct inode *inode, struct file *file)
{
	return 0;
}

static const struct file_operations rvd_fops = {
	.owner = THIS_MODULE,
	.open = rvd_open,
	.read = rvd_read,
	.write = rvd_write,
	.llseek = noop_llseek,
};

static struct miscdevice rvd_miscdev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "rvd",
	.fops = &rvd_fops,
	.mode = 0666,
};

static int __init rvd_mod_init(void)
{
	int ret;

	ret = misc_register(&rvd_miscdev);
	if (ret)
		return ret;

	return 0;
}

static void __exit rvd_mod_exit(void)
{
	misc_deregister(&rvd_miscdev);
}

module_init(rvd_mod_init);
module_exit(rvd_mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jk Hong <zaiguang.hong@riscv-computing.com>");
MODULE_DESCRIPTION("RISC-V Debug Module");
MODULE_VERSION("0.1");
