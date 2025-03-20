
CC = g++
CFLAGS = -Wall -Wextra -g
SRC = src/main.cpp #src/parser.cpp src/executor.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = posix-shell

all: $(TARGET)

$(TARGET): $(OBJ)
    $(CC) $(CFLAGS) -o $(TARGET) $(OBJ) -lreadline

run:
    ./main

clean:
    rm -f $(OBJ) $(TARGET)
