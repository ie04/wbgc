
/* 
 * File:   error.c
 * Author: ie04
 *
 * Created on December 17, 2018, 10:41 PM
 */
#include "constants.h"
#include "error.h"

char * display_error(error_type error){
    if(error == DIRTY_INPUT)
        return "Error: Invalid input";
    if(error == OUT_OF_BOUNDS)
        return "Error: Number inputted exceeds maximum";
    if(error == NEGATIVE)
        return "Error: Please enter a positive number";
    if(error == ZERO)
        return "Error: Please enter a number greater than zero";
    if(error == FW_FAILED)
        return "Error: Failed to write data to file";
    
}