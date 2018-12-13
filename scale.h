
/* 
 * File:   weight.h
 * Author: ie04
 *
 * Created on November 15, 2018, 6:15 PM
 */

#ifndef SCALE_H
#define SCALE_H
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include "average.h"
#include "sanity.h"
#include "constants.h"
#include "error.h"
typedef struct scale{
    
    //values averaged by the average function
    float averaged_values;
    
    //How much the scale weighs as a decimal
    float weight;

    char label[BUFFER];
    
    //averaged_values multiplied by weight
    float grade;
    
}scale;

scale calculate_score(int index){
    
    char input[20] = {0}; //Raw user input
    
    scale new_scale; //Scale object that holds scale attributes
    printf("What's the name of scale #%d?\n: ", index);
    fgets(new_scale.label, MAX_NAME_LENGTH, stdin);
    system("clear");
    //removes the newline added by fgets
    strtok(new_scale.label, "\n");
    
    new_scale.averaged_values = average(new_scale.label);


    //Redirects to sanity checker
    new_scale.weight = input_cleaner_float(new_scale.label);
    
    //l-value is the percentage scale represents in the final grade
    new_scale.grade  = new_scale.averaged_values * new_scale.weight;
    
    return new_scale;
    
}

void display_scale(scale input_scale){
    printf("Your average for scale %s is %.1f (scale %s is %.0f%% of your overall grade)\n", input_scale.label, input_scale.averaged_values,
                                                                                              input_scale.label, (input_scale.weight * 100));
}
#endif /* SCALE_H */