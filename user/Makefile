# SPDX-License-Identifier: GPL-2.0
#
# Copyright (C) 2026 Jk Hong <zaiguang.hong@riscv-computing.com>
#

CROSS_COMPILE := riscv64-linux-gnu-
CC            := $(CROSS_COMPILE)gcc
CFLAGS        := -Wall -Wextra -O2 -g -march=rv64gc -mabi=lp64d
LDFLAGS       ?=

TARGET   := rvd
LIB_SO   := librvd.so
SONAME   := librvd.so

MAIN_SRC := main.c
MAIN_OBJ := main.o

LIB_SRC  := urvd.c
LIB_PIC  := urvd.pic.o

KDIR        ?= /Users/hong/study/codes/linux/linux
HDR_INSTALL ?=

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

all: $(TARGET) $(LIB_SO)

$(LIB_PIC): $(LIB_SRC)
	$(CC) $(CFLAGS) -fPIC -c -o $@ $<

$(LIB_SO): $(LIB_PIC)
	$(CC) -shared -Wl,-soname,$(SONAME) -o $@ $< $(LDFLAGS)

$(MAIN_OBJ): $(MAIN_SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

# 与可执行同目录加载 .so（运行时需在含 librvd.so 的目录下执行，或设置 LD_LIBRARY_PATH）
$(TARGET): $(MAIN_OBJ) $(LIB_SO)
	$(CC) $(LDFLAGS) -o $@ $(MAIN_OBJ) -L. -lrvd -Wl,-rpath,'$$ORIGIN'

clean:
	rm -f $(TARGET) $(MAIN_OBJ) $(LIB_PIC) $(LIB_SO)
