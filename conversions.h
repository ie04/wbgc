
/* 
 * File:   conversions.h
 * Author: ie04
 *
 * Created on December 20, 2018, 5:52 PM
 */

#ifndef CONVERSIONS_H
#define CONVERSIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "constants.h"
#include "vector.h"
char * int_to_char_array(int number){
    int digit_count = floor(log10(number)) + 1;
    char * int_conv = calloc(sizeof(char), digit_count);
    sprintf(int_conv,"%d", number);
    return int_conv;
}

#endif /* CONVERSIONS_H */

