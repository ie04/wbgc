
/* 
 * File:   vector.h
 * Author: ie04
 *
 * Created on December 17, 2018, 10:44 PM
 */

#ifndef VECTOR_H
#define VECTOR_H
#define VECTOR_INIT_CAP 100
typedef struct{
    int size;
    int capacity;
    float * data;
}Vector_float;

void vector_initiate_float(Vector_float *vector);

void vector_append_float(Vector_float *vector, int value);

int vector_get_float(Vector_float *vector, int index);

void vector_set_float(Vector_float *vector, int index, int value);

void vector_double_capacity_if_full_float(Vector_float *vector);

void vector_free_float(Vector_float *vector);
#endif /* VECTOR_H */

