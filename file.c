
/* 
 * File:   file.c
 * Author: ie04
 *
 * Created on December 17, 2018, 11:14 PM
 */
#include <stdio.h>
#include "constants.h"
#include "file.h"
#include "vector.h"
//This header file will implement file I/O in wbgc

//Creates or overwrites data file
void create_file(const char *filename) {
    FILE * local_fp;
    local_fp = fopen(filename, "w");
    fprintf(local_fp, "0\n#DO NOT APPEND THIS FILE UNLESS YOU KNOW WHAT YOU ARE DOING\n\n");
    fclose(local_fp);
}

//Tests if a file exists
int does_file_exist(const char * filename) {
    FILE *local_fp;
    if ((local_fp = fopen(filename, "r"))) {
        fclose(local_fp);
        return 1;
    }
    return 0;
}

//Reads entire file and returns char vector
Vector_char file_read(const char* filename){
    Vector_char filebuf;
    vector_initiate_char(&filebuf);
    FILE * local_fp;
    if(!does_file_exist(filename))
        create_file(filename);
    local_fp = fopen(filename, "r");
    while(!feof(local_fp)){
        vector_append_char(&filebuf, getc(local_fp));
    }
    fclose(local_fp);
    return filebuf;
}


void append_string_to_file(const char* filename, const char* text_to_append) {
    FILE * local_fp;
    if(!does_file_exist(filename))
        create_file(filename);
    local_fp = fopen(filename, "a");
    fprintf(local_fp, "%s", text_to_append);
    fclose(local_fp);
}
void append_char_to_file(const char* filename, const char char_to_append) {
    FILE * local_fp;
    if(!does_file_exist(filename))
        create_file(filename);
    local_fp = fopen(filename, "a");
    fprintf(local_fp, "%c", char_to_append);
    fclose(local_fp);
}
void append_int_to_file(const char* filename, const int int_to_append) {
    FILE * local_fp;
    if(!does_file_exist(filename))
        create_file(filename);
    local_fp = fopen(filename, "a");
    fprintf(local_fp, "%d", int_to_append);
    fclose(local_fp);
}
void append_float_to_file(const char* filename, const float float_to_append) {
    FILE * local_fp;
    if(!does_file_exist(filename))
        create_file(filename);
    local_fp = fopen(filename, "a");
    fprintf(local_fp, "%.2f", float_to_append);
    fclose(local_fp);
}
void append_float_vector_to_file(const char* filename, Vector_float vec_to_append){
    for(int i=0;i<vec_to_append.size;i++){
        append_float_to_file(filename, vector_get_float(&vec_to_append, i));
        if(i != (vec_to_append.size-1)) //Append a colon as long as it isn't the last number
        append_char_to_file(filename, ':');
    }
    append_char_to_file(filename, '/');
    vector_free_float(&vec_to_append);
}
void append_scale(const char* filename, scale scale_to_append){
    append_string_to_file(filename, scale_to_append.label);
    append_char_to_file(filename, '/');
    append_float_to_file(filename, scale_to_append.averaged_values);
    append_char_to_file(filename, '/');
    append_float_to_file(filename, scale_to_append.grade);
    append_char_to_file(filename, '/');
    append_float_to_file(filename, scale_to_append.weight);
    append_char_to_file(filename, '/');
    append_float_vector_to_file(filename, scale_to_append.scores);
    append_string_to_file(filename, "$\n");
}
