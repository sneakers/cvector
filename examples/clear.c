#include <stdio.h>
#include "vector.h"

void loop_through_vect(vector *v);

int main() {
    vector *v = vect_new(sizeof(int));

    int values[] = {1,5,7};

    for (int i = 0; i < 3; i++) {
        vect_push(v, &values[i]);
    } 

    loop_through_vect(v);
    vect_clear(v);
    loop_through_vect(v);

    return 0;
}

void loop_through_vect(vector *v) {
    printf("Vector length: %d\n", v->length);
    
    int *data = (int *) v->data;

    for (int i = 0; i < v->length; i++) {
        printf("Vector value: %d\n", data[i]);
    }

    printf("----------\n");
}
