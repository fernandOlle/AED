#
#   ==============================
#       Author: Daniel Olivera
#   ==============================
#

ifeq ($(OS), Windows_NT)
TARGET=agenda2020.exe
else
TARGET=program
endif

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
CC=gcc

all: $(TARGET) clear

$(TARGET): $(OBJ)
	$(CC) -g $^ -o $@ -Wall

%.o: %.c
	$(CC) -g -c $< -o $@ -Wall

ifeq ($(OS), Windows_NT)
clear:
	-@del /f /a *.o
else
clear:
	-@rm -rvf *.o
endif
