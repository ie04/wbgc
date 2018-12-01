
/* 
 * File:   weight.h
 * Author: ie04
 *
 * Created on November 15, 2018, 6:15 PM
 */

#ifndef SCORE_H
#define SCORE_H
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include "average.h"
#include "scan.h"
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
    
    
    float sanitized_input; //Receives sanitized user input
    scale new_scale; //Scale object that holds scale attributes
    printf("What's the name of scale #%d?\n: ", index);
    fgets(new_scale.label, BUFFER, stdin);
    system("clear");
    //removes the newline added by fgets
    strtok(new_scale.label, "\n");
    
    new_scale.averaged_values = average(new_scale.label);

    //Sanity loop
    do{
        printf("How much does scale \"%s\" weigh for the class (percentage)?\n: ", new_scale.label);
        __fpurge(stdin); //Clears stdin from carriage-returns
        fgets(input, BUFFER, stdin);
        sanitized_input = float_sanity_test(input) / 100;
        system("clear");
        if((sanitized_input == -1) || (sanitized_input > 1) || (sanitized_input < 0.01))
            printf("%s\n", display_error(DIRTY_INPUT));
        
    }while((sanitized_input == -1) || (sanitized_input > 1) || (sanitized_input < 0.01));
    
    new_scale.weight = sanitized_input;
    
    //l-value is the percentage scale represents in the final grade
    new_scale.grade  = new_scale.averaged_values * new_scale.weight;
    
    return new_scale;
    
}

void display_scale(scale input_scale){
    printf("Your average for scale %s is %.1f (scale %s is %.0f%% of your overall grade)\n", input_scale.label, input_scale.averaged_values,
                                                                                              input_scale.label, (input_scale.weight * 100));
}
#endif /* SCORE_H */
