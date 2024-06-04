#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 1337

int main() {
    // Create a socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_address.sin_addr);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Error connecting to the server");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    // Create tasks and send them to the server
    for (unsigned i = 0; i < 10; ++i) {
        task_t new_task;
        new_task.task_id = i;
        new_task.val1 = i * 2;
        new_task.val2 = i * 3;

        // Send the task to the server
        if (send(client_socket, &new_task, sizeof(task_t), 0) == -1) {
            perror("Error sending task to the server");
            close(client_socket);
            exit(EXIT_FAILURE);
        }

        // Optionally, sleep for a while between sending tasks
        sleep(1);
    }

    // Close the socket
    close(client_socket);

    return 0;
}

