
/* 
 * File:   scan.h
 * Author: Iyad Eltifi
 *
 * Created on November 16, 2018, 5:41 PM
 */

#ifndef SCAN_H
#define SCAN_H
#include <stdio.h>
int int_sanity_test(char* input){
    int number = 0;
    int error_test = 0;
    float bad_float = 0;
    char bad_char = 0;
    error_test = sscanf(input, "%d %c %f", &number, &bad_char, &bad_float);
    if(error_test != 1)
        return -1;
    else
        return number;
}

float float_sanity_test(char* input){
    float number = 0;
    int error_test = 0;
    int bad_int = 0;
    char bad_char = 0;
    error_test = sscanf(input, "%f %c %d", &number, &bad_char, &bad_int);
    if(error_test != 1)
        return -1;
    else
        return number;
}
float float_sanity_test_avg(char* input){
    float number = 0;
    int error_test = 0;
    int bad_int = 0;
    char bad_char = 0;
    error_test = sscanf(input, "%f %c %d", &number, &bad_char, &bad_int);
    if(error_test != 1)
        return -2;
    else
        return number;
}
int sanitize_yno(char *yno){
    switch(*yno){
        case 'Y':
            *yno = 'y';
            return 0;
            
        case 'N':
            *yno = 'n';
            return 0;
            
        case 'y':
            return 0;
         
        case 'n':
            return 0;
            
        default:
            return 1;
    }
}

#endif /* SCAN_H */

