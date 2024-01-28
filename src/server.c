#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 1337

#define check_error(cond)                                                      \
    do {                                                                       \
        if (!(cond)) {                                                         \
            fprintf(stderr, "File: %s, line: %d\n", __FILE__, __LINE__);       \
            exit(1);                                                           \
        }                                                                      \
    } while (0)

int main(int argc, char const **argv) {

    int *array = malloc(10 * sizeof(int));
    check_error(array != NULL);

    int a = 5;
    int b = 10;
    printf("%d", 69 - a + b);
}
