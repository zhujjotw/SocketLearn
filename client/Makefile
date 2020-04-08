PRO_DIR         = $(shell pwd)
USER_OBJS_DIR   = $(PRO_DIR)
OBJS            = client
TARGET          =
TARGET_CC       = $(TARGET)gcc

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

USER_PUBLIC_INC = $(PRO_DIR)/../include
USER_INCS       = -I$(USER_PUBLIC_INC)
USER_CFLAGS     += -Wall -g
USER_CFLAGS     += $(USER_INCS)
SOURCE_FILE     = client.c    

$(OBJS): $(USER_OBJS_DIR)/client.c
	$(TARGET_CC) $(USER_CFLAGS) -o $@ $<
	
clean:
	@$(RM) *.a *.so.1.0