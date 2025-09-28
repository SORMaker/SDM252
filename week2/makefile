.PHONY: clean all run

CFLAGS = -Wall -g -O0
targets = main
sources = main.cpp log.cpp math.cpp
Compiler = g++

BUILD_DIR = build

objects = $(sources:%.cpp=$(BUILD_DIR)/%.o)

# 预编译文件（.i）路径
preprocessed_files = $(sources:%.cpp=$(BUILD_DIR)/%.i)

# 汇编文件（.s）路径
asm_files = $(sources:%.cpp=$(BUILD_DIR)/%.s)  # 新增：汇编文件路径

all: $(BUILD_DIR)/$(targets)

$(BUILD_DIR)/$(targets): $(objects)
	@$(Compiler) $(CFLAGS) $(objects) -o $@
	@echo "Build successful. Executable is at: $@"

run:all
	@$(BUILD_DIR)/$(targets)

# 生成预编译文件（.i）的规则：仅执行预处理
$(BUILD_DIR)/%.i: %.cpp | $(BUILD_DIR)
	@g++ $(CFLAGS) -E $< -o $@  # -E选项:只预处理,不编译
	@echo "Generated preprocessed file: $@"

# 生成汇编文件（.s）的规则：编译到汇编阶段
$(BUILD_DIR)/%.s: %.cpp | $(BUILD_DIR)  # 新增：汇编文件生成规则
	@g++ $(CFLAGS) -S $< -o $@  # -S选项:只生成汇编代码,不汇编/链接
	@echo "Generated assembly file: $@"

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	@$(Compiler) $(CFLAGS) -c $< -o $@ 

# 单独生成所有预编译文件的目标
preprocess: $(preprocessed_files)

# 单独生成所有汇编文件（新增目标）
assemble: $(asm_files)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

clean:
	@rm -rf $(BUILD_DIR)
