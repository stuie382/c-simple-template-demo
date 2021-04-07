#include <stdio.h>
#include <stdlib.h>

#include "template_demo/library.h"

int main(int argc, char *argv[]) {
    printf("Hello, example!\n");
    struct bowling *game = bowling_init();
    bowling_free(game);
    return EXIT_SUCCESS;
}