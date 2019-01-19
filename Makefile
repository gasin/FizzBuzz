CC = g++
CFLAGS = -g -Wall -std=c++11

FizzBuzz: src/FizzBuzz.cpp
	$(CC) $(CFLAGS) -o obj/FizzBuzz src/FizzBuzz.cpp

test: FizzBuzz
	./obj/FizzBuzz input/sample.txt output/sample.txt

clean:
	rm -f obj/*
