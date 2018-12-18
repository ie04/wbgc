
/* 
 * File:   average.h
 * Author: ie04
 *
 * Created on November 15, 2018, 5:54 PM
 */

#ifndef AVERAGE_H
#define AVERAGE_H
#include <stdio.h>
#include <stdio_ext.h>
#include "sanity.h"
#include "constants.h"
#include "error.h"
#include "vector.h"
float average(char weight_label[], Vector_float * vector_toreturn){
    //Input sanitized
    float sanitized_input = 0;
    
    char input[5] = {0};
    //current user-inputted number
    float current_number = 0;
    
    //sum of user inputted numbers
    float current_sum = 0;
    
    //amount of numbers user inputted
    int number_count = 0;
    
    //average of variables declared above
    float calculated_average = 0;
    
    
    
    printf("Enter current grades for scale \"%s\" (negative to terminate)\n", weight_label);
    while(current_number >= 0){
        printf(": ");
        

        current_number = input_cleaner_avg();
        vector_append_float(vector_toreturn, current_number);
        if(current_number >= 0){
            
            //temp var current_number adds value to sum
            current_sum += current_number;
            number_count++;
        }

        
    }
    system("clear");
    
    //Finds average of user-inputted numbers and the amount of numbers
    //number_count typecasted from int
    /*
     * The if statements are to protect against divide-by-zero errors which occur
     * if no numbers are inputted. If this happens, the average() function will
     * simply return 0.
     */
    if(number_count != 0){
    calculated_average = current_sum / (float)number_count;
    return calculated_average;
}else
    return 0;

    
}

#endif /* AVERAGE_H */

