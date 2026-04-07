// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2026 Jk Hong <zaiguang.hong@riscv-computing.com>
 */
#include <linux/module.h>
#include <linux/printk.h>

#include "rvd.h"

static int __init rvd_mod_init(void)
{
    printk(KERN_INFO "RISC-V Debug Module Initialized\n");
    return 0;
}

static void __exit rvd_mod_exit(void)
{
    printk(KERN_INFO "RISC-V Debug Module Exited\n");
}

module_init(rvd_mod_init);
module_exit(rvd_mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jk Hong <zaiguang.hong@riscv-computing.com>");
MODULE_DESCRIPTION("RISC-V Debug Module");
MODULE_VERSION("0.1");