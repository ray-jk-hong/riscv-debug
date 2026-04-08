// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2026 Jk Hong <zaiguang.hong@riscv-computing.com>
 */
#ifndef RVD_H
#define RVD_H

#include <linux/types.h>
#include <linux/ioctl.h>

#define RVD_IOC_MAGIC 'R'
#define RVD_IOC_GET_VERSION _IOR(RVD_IOC_MAGIC, 0, int)
#define RVD_IOC_GET_INFO    _IOR(RVD_IOC_MAGIC, 1, int)
#define RVD_IOC_GET_STATUS  _IOR(RVD_IOC_MAGIC, 2, int)
#define RVD_IOC_GET_CONFIG  _IOR(RVD_IOC_MAGIC, 3, int)
#define RVD_IOC_GET_DATA    _IOR(RVD_IOC_MAGIC, 4, int)

struct rvd_cmd {
    u32 cmd;
    u32 arg;
    void *data;
};

#endif