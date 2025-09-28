.PHONY : all clean run

CXX = g++
CXXFLAGS = -Wall -g -O0 -std=c++11

BUILD_DIR = build
TARGET = main
SOURCES = main.cpp log.cpp

OBJECTS = $(SOURCES:%.cpp=$(BUILD_DIR)/%.o)

all: $(BUILD_DIR)/$(TARGET)

# link
$(BUILD_DIR)/$(TARGET): $(OBJECTS)
	@echo "🔗 Linking target: $@"
	@$(CXX) $(OBJECTS) -o $@
	@echo "✅ Build successful!"

# compile
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	@echo "🔨 Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# create build directory
$(BUILD_DIR):
	@echo "📁 Creating directory: $@"
	@mkdir -p $(BUILD_DIR)

run: all
	@echo "🚀 Running executable..."
	@$(BUILD_DIR)/$(TARGET)

clean:
	@echo "🧹 Cleaning up build files..."
	@rm -rf $(BUILD_DIR)