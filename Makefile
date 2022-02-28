CXX=g++
CFLAGS=-c -Wall --std=c++11

ifeq ($(OS),Windows_NT)
    RM := del
	BINARY := main.exe
else
    RM := rm
	BINARY := main
endif

all: main

main: main.o
	$(CXX) $(DEBUG) main.o -o main

clean:
	$(RM) *.o *.gch $(BINARY)

run:
	$(BINARY) > out.txt
	python main.py