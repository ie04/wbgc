
/* 
 * File:   constants.h
 * Author: ie04
 *
 * Created on November 20, 2018, 4:24 PM
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

    #define MAX_SCALE_AMOUNT 5
    #define MAX_INPUT_AMOUNT 5
    #define MAX_LABEL_AMOUNT 50
    #define MAX_NAME_LENGTH 20
    #define BUFFER 2096

    typedef struct{
        int size;
        int capacity;
        float * data;
    }vector_float;

    typedef struct{
        int size;
        int capacity;
        char * data;
    }vector_char;

    typedef struct scale{

        //A vector of all user inputted scores
    vector_float scores;

typedef struct{
    int size;
    int capacity;
    float * data;
}Vector_float;

typedef struct{
    int size;
    int capacity;
    char * data;
}Vector_char;
typedef struct scale{
    
    //A vector of all user inputted scores
    Vector_float scores;

    
    //values averaged by the average function
    float averaged_values;
    
    //How much the scale weighs as a decimal
    float weight;

    char label[BUFFER];
    
    //averaged_values multiplied by weight
    float grade;
    
}scale;


typedef struct{
    
    vector_char label; //Class name
    
    int scale_amount;
    
    scale user_scales[MAX_SCALE_AMOUNT]; //All scales inputted by user
    
    float weights[MAX_SCALE_AMOUNT]; //array of scale percentages
    
    float added_weights = 0;
    
    float scored_numbers[MAX_SCALE_AMOUNT];
    
    float calculated_grade; //Final calculated grade for class
    
}wbgc_class;

typedef enum error_type { DIRTY_INPUT, OUT_OF_BOUNDS, NEGATIVE, ZERO, FW_FAILED } error_type;

#endif /* CONSTANTS_H */

