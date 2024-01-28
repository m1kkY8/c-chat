# Makefile for Chat Server and Client
CC = gcc

CFLAGS =

BIN_DIR = ../bin

SERVER_SRCS = server.c main_server.c
CLIENT_SRCS = client.c main_client.c

SERVER_OBJS = $(SERVER_SRCS:%.c=$(BIN_DIR)/%.o)
CLIENT_OBJS = $(CLIENT_SRCS:%.c=$(BIN_DIR)/%.o)

SERVER_TARGET = $(BIN_DIR)/chat_server
CLIENT_TARGET = $(BIN_DIR)/chat_client

# Default target
all: $(SERVER_TARGET) $(CLIENT_TARGET)

# Build the server executable
$(SERVER_TARGET): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Build the client executable
$(CLIENT_TARGET): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Compile server source files to object files
$(BIN_DIR)/%.o: %.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the generated files
clean:
	rm -rf $(BIN_DIR)/*
