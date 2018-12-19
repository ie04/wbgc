/* 
 * File:   file.h
 * Author: ie04
 *
 * Created on December 1, 2018, 7:01 PM
 */
#ifndef FILE_H
#define FILE_H
void create_file(const char *filename);
int does_file_exist(const char * filename);
void append_string_to_file(const char* filename, const char* text_to_append);
void append_scale(const char* filename, scale scale_to_append);
void append_char_to_file(const char* filename, const char text_to_append);
void append_int_to_file(const char* filename, const int text_to_append);
void append_float_to_file(const char* filename, const float text_to_append);
void append_vector_to_file(const char* filename, Vector_float vec_to_append);
#endif /* FILE_H */

