
/* 
 * File:   vector.h
 * Author: ie04
 *
 * Created on December 17, 2018, 10:44 PM
 */

#ifndef VECTOR_H
#define VECTOR_H
#define VECTOR_INIT_CAP 100
#include "constants.h"
//Float Vector
void vector_initiate_float(Vector_float *vector);

void vector_append_float(Vector_float *vector, float value);

float vector_get_float(Vector_float *vector, int index);

void vector_set_float(Vector_float *vector, int index, float value);

void vector_double_cap_if_full_float(Vector_float *vector);

void vector_free_float(Vector_float *vector);

//Char Vector
void vector_initiate_char(Vector_char* vector);

void vector_append_char(Vector_char* vector, char value);

char vector_get_char(Vector_char* vector, int index);

void vector_set_char(Vector_char* vector, int index, char value);

void vector_double_cap_if_full_char(Vector_char *vector);

void vector_print_char(Vector_char vec_to_print);

void vector_free_char(Vector_char *vector);
#endif /* VECTOR_H */

