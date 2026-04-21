CXX = g++
CXXFLAGS = -Wall -g
TARGET = main

all:$(TARGET)
OBJS = main.o function.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp function.h
	$(CXX) $(CXXFLAGS) -c main.cpp

function.o: function.h function.cpp
	$(CXX) $(CXXFLAGS) -c function.cpp


.PHONY: clean
clean:
	rm -f *.o $(TARGET)
