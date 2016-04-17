#include <stdlib.h>

int main(void) {
    int* i = malloc(sizeof(int));

    free(i);
    return 1;
}

int main(void) {
    int* i = new int();
     
    delete i;
    return 1;
}