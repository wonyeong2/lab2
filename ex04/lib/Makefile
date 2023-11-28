CC = gcc
CFLAGS = -I./lib

SRCS = ./lib/calculator.c ./lib/add.c ./lib/subtract.c ./lib/multiply.c ./lib/divide.c

OBJS = ./lib/calculator.o ./lib/add.o ./lib/subtract.o ./lib/multiply.o ./lib/divide.o

EXEC = calculator

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^


%.o: %.c
	$(cc) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS) $(EXEC)

