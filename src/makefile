CXX = g++
CXXFLAGS = -Wall -g
TARGET = main

all:$(TARGET)
OBJS = main.o function.o unit_tests.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp function.h
	$(CXX) $(CXXFLAGS) -c main.cpp

function.o: function.h function.cpp
	$(CXX) $(CXXFLAGS) -c function.cpp

unit_tests.o: function.h unit_tests.cpp
	$(CXX) $(CXXFLAGS) -c unit_tests.cpp



.PHONY: clean
clean:
	rm -f *.o $(TARGET)
