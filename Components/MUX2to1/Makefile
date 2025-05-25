# Biến SystemC
SYSTEMC_HOME = /usr/local/systemc-2.3.3

CXX = g++
CXXFLAGS = -I$(SYSTEMC_HOME)/include -std=c++11 -Wall -g \
           -IComponents/MUX2to1/src \
           -ILogic_gates/AND/src \
           -ILogic_gates/OR/src \
           -ILogic_gates/NOT/src

LDFLAGS = -L$(SYSTEMC_HOME)/lib-linux -lsystemc -lm -pthread

# Source files
SRCS = \
  Components/MUX2to1/src/MUX2to1.cpp \
  Logic_gates/AND/src/AND_GATE.cpp \
  Logic_gates/OR/src/OR_GATE.cpp \
  Logic_gates/NOT/src/NOT_GATE.cpp \
  test_mux2to1.cpp

# Object files (tạo tương ứng trong thư mục build)
OBJS = $(patsubst %.cpp, build/%.o, $(SRCS))

# Target executable
TARGET = build/mux2to1_sim

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Rule để compile .cpp thành .o trong thư mục build
build/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build/*

.PHONY: all clean
