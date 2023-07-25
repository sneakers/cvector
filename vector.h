#include <stdlib.h>
#include <string.h>

typedef struct {
    void *data;
    size_t length;
    size_t data_size;
} vector;

// Create a new vector where n represents
// the amount of bytes of the data type being held
// Example: vect_new(sizeof(int))
vector *vect_new(size_t n);

// Push an element to the end of the vector
// Example: vect_push(vect, &val)
void vect_push(vector *vect, void *element);

// Remove the last element of a vector
void vect_pop(vector *vect);

// Clear a vector of all its elements
void vect_clear(vector *vect);

// Insert an element at index
// This re-sizes the vector
// Returns: error code. 0 is no error
int vect_insert_at(vector *vect, unsigned int index, void *element);

// Deletes an element at the index 
// Re-sizes vector appropriately
// Returns: error code. 0 is no error
int vect_delete_at(vector *vect, unsigned int index);

// Free the vector from memory
void vect_free(vector *vect);