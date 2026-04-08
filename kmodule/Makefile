# SPDX-License-Identifier: GPL-2.0
# 本目录 out-of-tree 内核模块构建（默认 riscv64：ARCH=riscv + riscv-linux-gnu-）
#
#   make
#   make clean
#
# 指定内核树：make KDIR=/path/to/linux-source
# 本机原生编译模块（不推荐与本仓库 riscv 用户态混用）：make ARCH= CROSS_COMPILE=

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
