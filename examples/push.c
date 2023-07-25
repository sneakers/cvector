#include <stdio.h>
#include "vector.h"

int main() {
    vector *v = vect_new(sizeof(int));

    int values[] = {1,5,7,1,123,234535,465,456,567,24,23,423,4234};

    for (int i = 0; i < 13; i++) {
        vect_push(v, &values[i]);
    } 

    int *data = (int *) v->data;

    for (int i = 0; i < v->length; i++) {
        printf("Vector value: %d\n", data[i]);
    }

    return 0;
}
