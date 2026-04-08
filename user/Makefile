# SPDX-License-Identifier: GPL-2.0
#
# Copyright (C) 2026 Jk Hong <zaiguang.hong@riscv-computing.com>
#

CROSS_COMPILE := riscv64-linux-gnu-
CC            := $(CROSS_COMPILE)gcc
CFLAGS        := -Wall -Wextra -O2 -g -march=rv64gc -mabi=lp64d
LDFLAGS       ?=

TARGET  := rvd
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
CFLAGS += -D__EXPORTED_HEADERS__
LINUX_INCLUDES := \
	-Iinclude \
	-I../kmodule \
	-I$(KDIR)/include/uapi \
	-I$(KDIR)/include \
	-I$(KDIR)/arch/$(KERNEL_ARCH)/include/uapi

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
