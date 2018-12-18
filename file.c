
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

void create_file(const char *filename) {
    FILE * local_fp;
    local_fp = fopen(filename, "w");
    fclose(local_fp);
}

int does_file_exist(const char * filename) {
    FILE *local_fp;
    if ((local_fp = fopen(filename, "r"))) {
        fclose(local_fp);
        return 1;
    }
    return 0;
}

void append_to_file(const char* filename, const char* text_to_append) {
    FILE * local_fp;
    if (!does_file_exist(filename))
        create_file(filename);
    local_fp = fopen(filename, "a");
    fprintf(local_fp, "%s\n", text_to_append);
    fclose(local_fp);
}
void append_scale(const char* filename, scale scale_to_append){
    
}