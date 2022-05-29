TARGET := iphone:clang:latest:7.0
ARCHS := arm64

include $(THEOS)/makefiles/common.mk


TOOL_NAME = xnuspy_syscall_logger

xnuspy_syscall_logger_FILES = main.c symbolicate.c
xnuspy_syscall_logger_CFLAGS = -fno-stack-protector -D_FORTIFY_SOURCE=0 -Wno-deprecated-declarations -Wno-unused-variable -Wno-unused-function
xnuspy_syscall_logger_CODESIGN_FLAGS = -Sentitlements.plist
xnuspy_syscall_logger_INSTALL_PATH = /usr/local/bin

include $(THEOS_MAKE_PATH)/tool.mk
