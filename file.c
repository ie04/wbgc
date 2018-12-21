
/* 
 * File:   file.c
 * Author: ie04
 *
 * Created on December 17, 2018, 11:14 PM
 */
#include <stdio.h>
#include<stdlib.h>
#include "constants.h"
#include "file.h"
#include "vector.h"
//This header file will implement file I/O in wbgc

//Creates or overwrites data file
void file_create(const char *filename) {
    FILE * local_fp;
    local_fp = fopen(filename, "w");
<<<<<<< HEAD
    fprintf(local_fp, "0\n#DO NOT APPEND THIS FILE UNLESS YOU KNOW WHAT YOU ARE DOING\n\n");
=======
    fprintf(local_fp, "#DO NOT APPEND THIS FILE UNLESS YOU KNOW WHAT YOU ARE DOING\n\n");
>>>>>>> refs/remotes/origin/file_implementation
    fclose(local_fp);
}

//Tests if a file exists
int file_exists(const char * filename) {
    FILE *local_fp;
    if ((local_fp = fopen(filename, "r"))) {
        fclose(local_fp);
        return 1;
    }
    return 0;
}

<<<<<<< HEAD
//Reads entire file and returns char vector
int file_get(const char* filename, int pos){
    int to_return;
    if(!file_exists(filename))
        file_create(filename);
    FILE * local_fp = fopen(filename, "r+");
    fseek(local_fp, pos, SEEK_SET);
    fscanf(local_fp, "%d[^\n]", &to_return);
    fclose(local_fp);
    return to_return;
}
void file_replace(const char* filename, int pos, int replace_with){
        if(!file_exists(filename))
        file_create(filename);
    FILE * local_fp = fopen(filename, "r+");
    fseek(local_fp, pos, SEEK_SET);
    fprintf(local_fp,"%d", replace_with);
    fclose(local_fp);
}
void file_print(const char* filename){
    vector_char filebuf;
    vector_initiate_char(&filebuf);
    FILE * local_fp;
  
    //If file doesn't exist create it
    if(!file_exists(filename))
        file_create(filename);
    
    
    local_fp = fopen(filename, "r");
    
    //Append characters to vector until end of file is reached
    while(!feof(local_fp)){
        vector_append_char(&filebuf, getc(local_fp));
    }
    fclose(local_fp);
    vector_print_char(filebuf);
}


void file_append_string(const char* filename, const char* text_to_append) {
    FILE * local_fp;
    if(!file_exists(filename))
        file_create(filename);
=======
void append_string_to_file(const char* filename, const char* text_to_append) {
    FILE * local_fp;
    if(!does_file_exist(filename))
        create_file(filename);
>>>>>>> refs/remotes/origin/file_implementation
    local_fp = fopen(filename, "a");
    fprintf(local_fp, "%s", text_to_append);
    fclose(local_fp);
}
<<<<<<< HEAD
void file_append_char(const char* filename, const char char_to_append) {
    FILE * local_fp;
    if(!file_exists(filename))
        file_create(filename);
=======
void append_char_to_file(const char* filename, const char char_to_append) {
    FILE * local_fp;
    if(!does_file_exist(filename))
        create_file(filename);
>>>>>>> refs/remotes/origin/file_implementation
    local_fp = fopen(filename, "a");
    fprintf(local_fp, "%c", char_to_append);
    fclose(local_fp);
}
<<<<<<< HEAD
void file_append_int(const char* filename, const int int_to_append) {
    FILE * local_fp;
    if(!file_exists(filename))
        file_create(filename);
=======
void append_int_to_file(const char* filename, const int int_to_append) {
    FILE * local_fp;
    if(!does_file_exist(filename))
        create_file(filename);
>>>>>>> refs/remotes/origin/file_implementation
    local_fp = fopen(filename, "a");
    fprintf(local_fp, "%d", int_to_append);
    fclose(local_fp);
}
<<<<<<< HEAD
void file_append_float(const char* filename, const float float_to_append) {
    FILE * local_fp;
    if(!file_exists(filename))
        file_create(filename);
=======
void append_float_to_file(const char* filename, const float float_to_append) {
    FILE * local_fp;
    if(!does_file_exist(filename))
        create_file(filename);
>>>>>>> refs/remotes/origin/file_implementation
    local_fp = fopen(filename, "a");
    fprintf(local_fp, "%.2f", float_to_append);
    fclose(local_fp);
}
<<<<<<< HEAD
void file_append_float_vector(const char* filename, vector_float vec_to_append){
    for(int i=0;i<vec_to_append.size;i++){
        file_append_float(filename, vector_get_float(&vec_to_append, i));
        if(i != (vec_to_append.size-1)) //Append a colon as long as it isn't the last number
        file_append_char(filename, ':');
    }
    file_append_char(filename, '/');
    vector_free_float(&vec_to_append);
}
void file_append_scale(const char* filename, scale scale_to_append){
    int index = file_get(filename, 0);
    
    file_replace(filename,0,++index);
    file_append_int(filename, index);
    file_append_char(filename, ' ');
    file_append_string(filename, scale_to_append.label);
    file_append_char(filename, '/');
    file_append_float(filename, scale_to_append.averaged_values);
    file_append_char(filename, '/');
    file_append_float(filename, scale_to_append.grade);
    file_append_char(filename, '/');
    file_append_float(filename, scale_to_append.weight);
    file_append_char(filename, '/');
    file_append_float_vector(filename, scale_to_append.scores);
    file_append_string(filename, "$\n");
}
scale file_construct_scale(const char* filename){
    
=======
void append_vector_to_file(const char* filename, Vector_float vec_to_append){
    for(int i=0;i<vec_to_append.size;i++){
        append_float_to_file(filename, vector_get_float(&vec_to_append, i));
        if(i != (vec_to_append.size-1))
        append_char_to_file(filename, ':');
    }
    append_char_to_file(filename, '/');
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
    append_vector_to_file(filename, scale_to_append.scores);
    append_string_to_file(filename, "$\n");
>>>>>>> refs/remotes/origin/file_implementation
}