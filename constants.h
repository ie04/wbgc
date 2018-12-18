
/* 
 * File:   constants.h
 * Author: ie04
 *
 * Created on November 20, 2018, 4:24 PM
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#define MAX_SCORE_AMOUNT 5
#define MAX_INPUT_AMOUNT 5
#define MAX_LABEL_AMOUNT 50
#define MAX_NAME_LENGTH 20
#define BUFFER 2096

typedef enum error_type { DIRTY_INPUT, OUT_OF_BOUNDS, NEGATIVE, ZERO, FW_FAILED } error_type;

typedef struct scale{
    
    //values averaged by the average function
    float averaged_values;
    
    //How much the scale weighs as a decimal
    float weight;

    char label[BUFFER];
    
    //averaged_values multiplied by weight
    float grade;
    
}scale;
#endif /* CONSTANTS_H */

