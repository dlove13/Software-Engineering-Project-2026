CXX = g++
CXXFLAGS = -Wall -g
TARGET = main

all:$(TARGET)
OBJS = main.o display.o tokenizer.o parser.o evaluator.o unit_tests.o error_handler.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp function.h
	$(CXX) $(CXXFLAGS) -c main.cpp

display.o: display.cpp function.h
	$(CXX) $(CXXFLAGS) -c display.cpp

tokenizer.o: tokenizer.cpp function.h
	$(CXX) $(CXXFLAGS) -c tokenizer.cpp

parser.o: parser.cpp function.h
	$(CXX) $(CXXFLAGS) -c parser.cpp

evaluator.o: evaluator.cpp function.h
	$(CXX) $(CXXFLAGS) -c evaluator.cpp

unit_tests.o: unit_tests.cpp function.h 
	$(CXX) $(CXXFLAGS) -c unit_tests.cpp

error_handler.o: error_handler.cpp function.h

.PHONY: clean
clean:
	rm -f *.o $(TARGET)
