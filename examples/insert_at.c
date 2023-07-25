#include <stdio.h>
#include "vector.h"

void loop_through_vect(vector *v);

int main() {
    vector *v = vect_new(sizeof(int));

    int values[] = {1,2,3,4,5,6,7,8};

    for (int i = 0; i < 8; i++) {
        vect_push(v, &values[i]);
    } 

    loop_through_vect(v);
    int valueToInsert = 1337;

    vect_insert_at(v, 5, &valueToInsert);
    vect_insert_at(v, 5, &valueToInsert);
    vect_insert_at(v, -1, &valueToInsert); // does nothing

    loop_through_vect(v);

    return 0;
}

void loop_through_vect(vector *v) {
    int *data = (int *) v->data;

    for (int i = 0; i < v->length; i++) {
        printf("Vector value: %d\n", data[i]);
    }

    printf("----------\n");
}
