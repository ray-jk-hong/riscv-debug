# SPDX-License-Identifier: GPL-2.0
#
# Copyright (C) 2026 Jk Hong <zaiguang.hong@riscv-computing.com>
#
# 使用 KDIR 指向内核源码树时，已加 -D__EXPORTED_HEADERS__（见 types.h 里 #warning 说明）。
# 更稳妥的用户态头文件来源：linux-libc-dev，或 make headers_install + HDR_INSTALL。

CC      ?= gcc
CFLAGS  ?= -Wall -Wextra -O2 -g
LDFLAGS ?=

TARGET  := rvd_user
SRCS    := $(wildcard *.c)
OBJS    := $(SRCS:.c=.o)

KDIR        ?= /Users/hong/study/codes/linux/linux
HDR_INSTALL ?=

# uname -m -> 内核 arch/ 目录名（按需可 make KERNEL_ARCH=xxx 覆盖）
KERNEL_ARCH ?= $(shell uname -m | sed \
	-e 's/riscv64/riscv/' \
	-e 's/aarch64/arm64/' \
	-e 's/x86_64/x86/' \
	-e 's/armv7l/arm/' \
	-e 's/i[3456]86/x86/')

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
