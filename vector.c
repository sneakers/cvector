#include "vector.h"
#include <stdio.h>

vector *vect_new(size_t n) {
    vector *vect = (vector *) malloc(sizeof(vector));

    vect->length = 0;
    vect->data_size = n;
    vect->data = NULL;

    return vect;
}

void vect_push(vector *vect, void *element) {
    vect->length += 1;

    vect->data = realloc(vect->data, vect->length * vect->data_size);

    // get the position where the bytes of the new element should start
    char *position = (char *) vect->data + ((vect->length - 1) * vect->data_size);

    memcpy_s(position, vect->data_size, element, vect->data_size);
}

void vect_pop(vector *vect) {
    if (vect->length == 0) return;

    vect->length -= 1;

    vect->data = realloc(vect->data, vect->length * vect->data_size);    
}

void vect_clear(vector *vect) {
    free(vect->data);
    vect->length = 0;
}

int vect_insert_at(vector *vect, unsigned int index, void *element) {
    if (index >= vect->length - 1) {
        vect_push(vect, element);
        return 0;
    }

    vect->length += 1;

    vect->data = realloc(vect->data, vect->length * vect->data_size);

    // get the position where the bytes of the new element should be inserted
    char *position = (char *) vect->data + ((index) * vect->data_size);

    size_t length = vect->length * vect->data_size - (index * vect->data_size);

    // move the memory over so we have space for the new data
    int err = memmove_s(
        (char *) vect->data + (index * vect->data_size) + vect->data_size,
        vect->data_size * vect->length,
        position,
        length
    );

    if (err != 0) return err;

    // copy the new data into the previously occupied space
    memcpy_s(position, vect->data_size, element, vect->data_size);

    return 0;
}

int vect_delete_at(vector *vect, unsigned int index) {
    if (index >= vect->length - 1) {
        vect_pop(vect);
        return 0;
    }

    // start position
    char *position = (char *) vect->data + ((index) * vect->data_size);

    int err = memmove_s(
        position,
        vect->length * vect->data_size,
        position + vect->data_size,
        (vect->length * vect->data_size) - vect->data_size
    );

    if (err != 0) return 1;

    vect->length -= 1;
    vect->data = realloc(vect->data, vect->length * vect->data_size);

    return 0;
}

void vect_free(vector *vect) {
    vect_clear(vect);
    free(vect->data);
}
