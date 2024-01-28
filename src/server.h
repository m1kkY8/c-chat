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

void amogus();
void amogus1();

