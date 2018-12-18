/* 
 * File:   file.h
 * Author: ie04
 *
 * Created on December 1, 2018, 7:01 PM
 */
#ifndef FILE_H
#define FILE_H
#include <stdio.h>
#include "constants.h"
//This header file will implement file I/O in wbgc
void create_file(const char *filename){
    FILE * local_fp;
    local_fp = fopen(filename, "w");
    fclose(local_fp);
}
int does_file_exist(const char * filename){
    FILE *local_fp;
    if ((local_fp = fopen(filename, "r"))){
        fclose(local_fp);
        return 1;
    }
    return 0;
}
void append_to_file(const char* filename, const char* text_to_append){
    FILE * local_fp;
    if(!does_file_exist(filename))
    create_file(filename);
    local_fp = fopen(filename, "a");
    fprintf(local_fp, "%s\n", text_to_append);
    fclose(local_fp);
}
#endif /* FILE_H */

