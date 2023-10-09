CC = g++
CFLAGS = -Wall -g

all: main.cpp
	$(CC) $(CFLAGS) -o main main.cpp

clean:
	$(RM) main.exe