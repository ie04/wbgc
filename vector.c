
/* 
 * File:   vector.c
 * Author: ie04
 *
 * Created on December 17, 2018, 10:50 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "vector.h"

void vector_initiate_float(Vector_float *vector) {
  // initialize size and capacity
  vector->size = 0;
  vector->capacity = VECTOR_INIT_CAP;

  // allocate memory for vector->data
  vector->data = malloc(sizeof(int) * vector->capacity);
}

void vector_append_float(Vector_float *vector, float value){
    vector_double_cap_if_full_float(vector);
    vector->data[vector->size++] = value;
}

float vector_get_float(Vector_float *vector, int index){
    if (index >= vector->size || index < 0) {
    printf("Index %d out of bounds for vector of size %d\n", index, vector->size);
    exit(1);
  }
  return vector->data[index];
}

void vector_set_float(Vector_float *vector, int index, float value){
   while (index >= vector->size) {
    vector_append_float(vector, 0);
  }

  // set the value at the desired index
  vector->data[index] = value;
}

void vector_double_cap_if_full_float(Vector_float *vector){
    if (vector->size >= vector->capacity) {
    // double vector->capacity and resize the allocated memory accordingly
    vector->capacity *= 2;
    vector->data = realloc(vector->data, sizeof(int) * vector->capacity);
  }
}

void vector_free_float(Vector_float *vector){
    free(vector->data);
}
