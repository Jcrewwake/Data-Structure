# 定义编译器
CC = gcc

# 定义编译选项
CFLAGS = -Wall -Wextra -O2 -Iinclude

# 源文件目录
SRC_DIR = src

# 目标文件目录
BUILD_DIR = build

# 获取所有的 .c 文件，包括子目录中的文件
SRCS = $(shell find $(SRC_DIR) -name '*.c' ! -name 'AdjMatrixGraph.c')

# 将 .c 文件名替换为 .o 文件名，并将路径调整为 BUILD_DIR
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# 生成依赖文件
DEPS = $(OBJS:.o=.d)

# 最终生成的可执行文件
TARGET = $(BUILD_DIR)/my_program

# 默认目标
all: $(TARGET)

# 链接目标文件生成最终可执行文件
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

# 编译源文件生成目标文件，同时生成依赖文件
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

# 包含所有的依赖文件
-include $(DEPS)

# 清理生成的文件
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)/*
