# Tools on build host
MAKE        = make
RM          = rm -f
RMDIR       = rm -rf
MKDIR       = mkdir -p
CP          = cp -f
MV          = mv -f
INSTALL     = install
LN          = ln -s
TOUCH       = touch
XARGS       = xargs -r

# Cross compile tools
TARGET_CC       = $(TARGET)gcc
TARGET_CXX      = $(TARGET)c++
TARGET_LD       = $(TARGET)ld
TARGET_AR       = $(TARGET)ar
TARGET_RANLIB   = $(TARGET)ranlib
TARGET_STRIP    = $(TARGET)strip
TARGET_OBJCOPY  = $(TARGET)objcopy
TARGET_OBJDUMP  = $(TARGET)objdump
TARGET_NM       = $(TARGET)NM
TARGET_SIZE     = $(TARGET)size
HOST_CC         = gcc

BOARD_ARCH_FULL = x86

#当前目录
PRO_DIR         =  $(shell pwd）

#
BUILD_CXX       = n

#库文件路径
USER_PUBLIC_INC = $(PRO_DIR)/include
USER_INCS       = -I. -I$(USER_PUBLIC_INC)

#编译选项
USER_CFLAGS     += -Wall -g -I
USER_CFLAGS     += $(USER_INCS)

#存放中间文件
USER_OBJS_DIR   = $(PRO_DIR)/client
OBJS            = client

SUBDIRS = bsi epi log bso mng bm_mod

#build subdirs
define MkSubDirs
for dir in $(SUBDIRS); do \
	if [ -f $$dir/Makefile ]; then \
	echo "$(MAKE) -C $$dir $@"; \
	$(MAKE) -C $$dir $@ || exit 1; \
	fi; \
	done
endef

ifeq ($(BUILD_CXX), y)  # Cxx
$(OBJS): $(USER_OBJS_DIR)/%.o:%.cpp
	$(TARGET_CXX) $(USER_CFLAGS) -c -o $@ $<
else # C
$(OBJS): $(USER_OBJS_DIR)/%.o:%.c
	$(TARGET_CC) $(USER_CFLAGS) -c -o $@ $<
endif

clean:
	@$(RM) *.a *.so.1.0
