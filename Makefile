CC = g++
CFLAGS = -g -Wall -std=c++11

FizzBuzz: src/FizzBuzz.cpp
	$(CC) $(CFLAGS) -o obj/FizzBuzz src/FizzBuzz.cpp

test: FizzBuzz
	./obj/FizzBuzz parameter/input.txt

clean:
	rm -f obj/*
