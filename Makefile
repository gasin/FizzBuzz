CC = g++
CFLAGS = -g -Wall -std=c++11

FizzBuzz: src/FizzBuzz.cpp
	$(CC) $(CFLAGS) -o obj/FizzBuzz src/FizzBuzz.cpp

clean:
	rm -f obj/*
