# SPDX-License-Identifier: GPL-2.0
#
# Copyright (C) 2026 Jk Hong <zaiguang.hong@riscv-computing.com>
#

obj-m += rvd.o

ARCH            ?= riscv
CROSS_COMPILE   ?= riscv-linux-gnu-
KDIR            ?= /Users/hong/study/codes/linux/linux
PWD             := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) M=$(PWD) clean

.PHONY: all clean
