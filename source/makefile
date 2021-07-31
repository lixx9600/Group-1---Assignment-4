#Do not edit the contents of this file.
CC = gcc
CFLAGS = -Wall -g -std=gnu99
LDFLAGS = -lrt -lpthread
TARGET = Question1
OBJFILES = Question1.o
all: $(TARGET)

Question1: Question1.c
	$(CC) $(CFLAGS) -o Question1 Question1.c $(LDFLAGS)

runq1: Question1
	./Question1 10 5 7 8

clean:
	rm -f $(OBJFILES) $(TARGET) *~

	// place makefile in the same folder where Question1.c file is and to compile run:
	//$ make
	// if you want to run Question1.c then use:
	//$ make runq1
	// to clean out the directory then use:
	//$ make clean
