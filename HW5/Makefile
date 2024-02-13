# Define the compiler
CXX=g++

# Define any compile-time flags
CXXFLAGS=-Wall -std=c++11

# Define the source files
SRCS=gnf5628_HW5_q1.cpp

# Define the target executable
TARGET=program

# Define the build rule
all: $(TARGET)

# Define the rule for the target
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Define the clean rule
clean:
	rm -f $(TARGET)
