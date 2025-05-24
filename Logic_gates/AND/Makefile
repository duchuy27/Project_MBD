#### Configuration ###################

# Executable file name
EXE := main

# Directories
EXEDIR := build
OBJDIR := build/obj
TESTDIR := build/test

SRCDIR := src
TESTSRCDIR := test

# SystemC paths (bạn nhớ export trước khi chạy make)
SYSTEMC_PATH ?= /usr/local/systemc-2.3.3
SYSTEMC_INCLUDE := $(SYSTEMC_PATH)/include
SYSTEMC_LIB := $(SYSTEMC_PATH)/lib-linux64

# Compiler and linker
CXX := g++
CXXFLAGS := -g -Wall -Wextra -pedantic -I$(SYSTEMC_INCLUDE) -I$(SRCDIR)
LDFLAGS := -L$(SYSTEMC_LIB)
LDLIBS := -lsystemc -lm -lpthread

# Source and object files
SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

TESTSRCS := $(wildcard $(TESTSRCDIR)/*.cpp)
TESTOBJS := $(patsubst $(TESTSRCDIR)/%.cpp, $(TESTDIR)/%.o, $(TESTSRCS))

# Final binary path
BIN := $(EXEDIR)/$(EXE)

#### Rules ##########################

.PHONY: all clean run

all: $(BIN)

# Link rule: link both src and test objects
$(BIN): $(OBJS) $(TESTOBJS) | $(EXEDIR)
	$(CXX) $(CXXFLAGS) $(OBJS) $(TESTOBJS) $(LDFLAGS) $(LDLIBS) -o $@

# Compile source files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile test files
$(TESTDIR)/%.o: $(TESTSRCDIR)/%.cpp | $(TESTDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directories if not exist
$(EXEDIR):
	mkdir -p $@

$(OBJDIR):
	mkdir -p $@

$(TESTDIR):
	mkdir -p $@

run: all
	./$(BIN)

clean:
	rm -rf $(EXEDIR) $(OBJDIR) $(TESTDIR)

