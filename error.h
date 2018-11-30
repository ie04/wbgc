
/* 
 * File:   error.h
 * Author: Iyad Eltifi
 *
 * Created on November 20, 2018, 4:50 PM
 */

#ifndef ERROR_H
#define ERROR_H
typedef enum error_type { DIRTY_INPUT, OUT_OF_BOUNDS, NEGATIVE, ZERO } error_type;

char * display_error(error_type error){
    if(error == DIRTY_INPUT)
        return "Error: Invalid input";
    if(error == OUT_OF_BOUNDS)
        return "Error: Number inputted exceeds maximum";
    if(error == NEGATIVE)
        return "Error: Please enter a positive number";
    if(error == ZERO)
        return "Error: Please enter a number greater than zero";
    
}

#endif /* ERROR_H */

