# SPDX-License-Identifier: GPL-2.0
#
# Copyright (C) 2026 Jk Hong <zaiguang.hong@riscv-computing.com>
#
# 使用 KDIR 指向内核源码树时，已加 -D__EXPORTED_HEADERS__（见 types.h 里 #warning 说明）。
# 更稳妥的用户态头文件来源：linux-libc-dev，或 make headers_install + HDR_INSTALL。
#
# 本工程用户态为 riscv64，固定 riscv-linux-gnu- 交叉编译。
# 注意：若写 CC ?= / CROSS_COMPILE ?=，环境变量里的 CC 会覆盖 Makefile，在 macOS 上容易仍用
# arm64/clang。此处用 := 覆盖环境；仅当本机 gcc 时用：make CROSS_COMPILE= CC=gcc
# 若系统只有 riscv64-linux-gnu-gcc：make CROSS_COMPILE=riscv64-linux-gnu-

CROSS_COMPILE := riscv64-linux-gnu-
CC            := $(CROSS_COMPILE)gcc
CFLAGS        := -Wall -Wextra -O2 -g -march=rv64gc -mabi=lp64d
LDFLAGS       ?=

TARGET  := rvd_user
SRCS    := $(wildcard *.c)
OBJS    := $(SRCS:.c=.o)

KDIR        ?= /Users/hong/study/codes/linux/linux
HDR_INSTALL ?=

# 内核 arch/ 目录名（本工程固定为 riscv；需要时可 make KERNEL_ARCH=arm64 等覆盖）
KERNEL_ARCH ?= riscv

ifneq ($(strip $(HDR_INSTALL)),)
CFLAGS += -I$(HDR_INSTALL)/include
endif

ifneq ($(strip $(KDIR)),)
# 与「导出的」用户态头文件约定一致，消除 types.h 里对未导出头文件的 #warning
CFLAGS += -D__EXPORTED_HEADERS__
LINUX_INCLUDES := \
	-I$(KDIR)/include/uapi \
	-I$(KDIR)/include \
	-I$(KDIR)/arch/$(KERNEL_ARCH)/include/uapi
# 配置/编译过内核树后通常存在；若不存在，个别 gcc 可能对「不存在的 -I」告警，可忽略或先在内核树做 modules_prepare
LINUX_INCLUDES += -I$(KDIR)/arch/$(KERNEL_ARCH)/include/generated/uapi
CFLAGS += $(LINUX_INCLUDES)
endif

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJS)
