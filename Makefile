# ==== Load Config ====
include build_config.mk

# ==== Compiler & flags ====
CXX := g++
CXXFLAGS := -Wall -g
SYSTEMC_DIR := /usr/local/systemc-2.3.3
INCLUDES := -I$(SYSTEMC_DIR)/include
LIBS := -L$(SYSTEMC_DIR)/lib-linux64 -lsystemc -lm -pthread

# ==== Paths ====
MODULE_DIR := $(TARGET_TYPE)/$(TARGET_MODULE)
TEST_DIR := Test/$(TARGET_TYPE)/$(TARGET_MODULE)
BUILD_DIR := build
SRC_DIR := $(MODULE_DIR)/src
INC_DIR := $(MODULE_DIR)/include

# ==== Logic Gate dependencies ====
GATES := AND OR NOT NAND NOR XOR XNOR
GATE_SRC := $(foreach gate, $(GATES), Logic_gates/$(gate)/src/$(gate)_GATE.cpp)
GATE_INC := $(foreach gate, $(GATES), -ILogic_gates/$(gate)/include)

# ==== Sources ====
ifeq ($(TARGET_TYPE), Logic_gates)
SRC := $(TARGET_TYPE)/$(TARGET_MODULE)/src/$(TARGET_MODULE)_GATE.cpp
TEST := Test/$(TARGET_TYPE)/$(TARGET_MODULE)/Test_$(TARGET_MODULE).cpp
else
SRC := $(TARGET_TYPE)/$(TARGET_MODULE)/src/$(TARGET_MODULE).cpp
TEST := Test/$(TARGET_TYPE)/$(TARGET_MODULE)/test_$(TARGET_MODULE).cpp
endif

# ==== Auto-detect includes from source and test ====
INCLUDED_HEADERS := $(shell grep -h '^#include "' $(SRC) $(TEST) | sed 's/#include "\(.*\)"/\1/' | cut -d. -f1)
DEPENDENCIES := $(sort $(INCLUDED_HEADERS))

# ==== Generate include paths and source files from auto-detected dependencies ====
DEP_INC := $(foreach dep,$(DEPENDENCIES),\
	$(if $(wildcard Logic_gates/$(dep)/include/$(dep)_GATE.h),-ILogic_gates/$(dep)/include,\
	$(if $(wildcard Components/$(dep)/include/$(dep).h),-IComponents/$(dep)/include,)\
))

DEP_SRC := $(foreach dep,$(DEPENDENCIES),\
	$(if $(wildcard Logic_gates/$(dep)/src/$(dep)_GATE.cpp),Logic_gates/$(dep)/src/$(dep)_GATE.cpp,\
	$(if $(wildcard Components/$(dep)/src/$(dep).cpp),Components/$(dep)/src/$(dep).cpp,)\
))
INCLUDES += -I$(INC_DIR) $(DEP_INC)
ALL_SRC := $(SRC) $(DEP_SRC) $(TEST)

OBJECTS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRC) $(GATE_SRC) $(TEST))
TARGET := $(BUILD_DIR)/test_$(shell echo $(TARGET_MODULE) | tr A-Z a-z)

# ==== Includes ====
INCLUDES += -I$(INC_DIR) $(GATE_INC)

# ==== Build rules ====
.PHONY: all run clean help

all: clean $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "🔧 Linking target..."
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS) && \
	echo "✅ Build thành công: $@" || \
	(echo "❌ Link thất bại!"; exit 1)

# Compile .cpp -> .o
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "🛠️  Compiling: $<"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@ || \
	(echo "❌ Compile FAILED: $<"; exit 1)

run: $(TARGET)
	@echo "🚀 Running simulation..."
	@./$(TARGET)

clean:
	@echo "🧹 Cleaning..."
	@rm -rf $(BUILD_DIR)
	@echo "✅ Done."

help:
	@echo "📖 Các lệnh Makefile:"
	@echo "  make         → Build project"
	@echo "  make run     → Run simulation"
	@echo "  make clean   → Xoá file build"
	@echo "  make help    → Hiển thị hướng dẫn"
	@echo ""
	@echo "📦 Module đang build: $(TARGET_MODULE) (type: $(TARGET_TYPE)) - xem trong build_config.mk"
