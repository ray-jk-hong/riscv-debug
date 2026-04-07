# SPDX-License-Identifier: GPL-2.0
# 本目录 out-of-tree 内核模块构建
#
# 本机当前运行内核：
#   make
#   make clean
#
# 指定内核源码/构建目录（交叉编译或自定义树常用）：
#   make KDIR=/path/to/linux-source
#
# RISC-V 交叉编译示例：
#   make ARCH=riscv CROSS_COMPILE=riscv64-linux-gnu- KDIR=/path/to/linux

obj-m += rvd.o

KDIR ?= /Users/hong/study/codes/riscv-debug/kheaders
PWD  := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

.PHONY: all clean
