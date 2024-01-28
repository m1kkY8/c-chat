# Makefile for Chat Server

# Compiler
CC = gcc

# Compiler flags
CFLAGS =

# Source files
SRCS = server.c test.c

# Object files
OBJS = $(SRCS:.c=.o)

# Output executable
TARGET = chat_server

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the generated files
clean:
	rm -f $(OBJS) $(TARGET)

