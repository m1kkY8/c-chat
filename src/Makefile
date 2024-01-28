# Makefile for Chat Server and Client

# Compiler
CC = gcc

# Compiler flags
CFLAGS =

# Server source files
SERVER_SRCS = server.c

# Client source files
CLIENT_SRCS = client.c

# Server object files
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

# Client object files
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

# Output executables
SERVER_TARGET = chat_server
CLIENT_TARGET = chat_client

# Default target
all: $(SERVER_TARGET) $(CLIENT_TARGET)

# Build the server executable
$(SERVER_TARGET): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Build the client executable
$(CLIENT_TARGET): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Compile server source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the generated files
clean:
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_TARGET) $(CLIENT_TARGET)

