
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
  vector->data = malloc(sizeof(float) * vector->capacity);
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
    vector->data = realloc(vector->data, sizeof(float) * vector->capacity);
  }
}

void vector_free_float(Vector_float *vector){
    free(vector->data);
}

//Char Vector
void vector_initiate_char(Vector_char* vector){
    vector->size = 0;
    vector->capacity = VECTOR_INIT_CAP;
    vector->data = malloc(sizeof(char) * vector->capacity);
}
void vector_append_char(Vector_char* vector, char value){
    vector_double_cap_if_full_char(vector);
    vector->data[vector->size++] = value;
}
char vector_get_char(Vector_char* vector, int index){
    if (index >= vector->size || index < 0) {
    printf("Index %d out of bounds for vector of size %d\n", index, vector->size);
    exit(1);
  }
  return vector->data[index];
}
void vector_set_char(Vector_char* vector, int index, char value){
    while (index >= vector->size) {
    vector_append_char(vector, 0);
  }

  // set the value at the desired index
  vector->data[index] = value;
}
void vector_double_cap_if_full_char(Vector_char *vector){
    if (vector->size >= vector->capacity) {
    // double vector->capacity and resize the allocated memory accordingly
    vector->capacity *= 2;
    vector->data = realloc(vector->data, sizeof(char) * vector->capacity);
  }
}

void vector_free_char(Vector_char *vector){
    free(vector->data);
}