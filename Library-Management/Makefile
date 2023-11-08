CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC_DIR = src
INCLUDE_DIR = include
OBJ = $(SRC_DIR)/*.c

all: $(OBJ)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -o library-management $(OBJ)

run:
	./library-management

clean:
	rm -f library-management