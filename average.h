
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
#include "scan.h"
#include "constants.h"
#include "error.h"
#include "not_equals_yno.h"
float average(char weight_label[]){
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
        
        do{
            __fpurge(stdin);
            fgets(input, BUFFER, stdin);
            sanitized_input = float_sanity_test_avg(input);
            if(sanitized_input == -2){
                printf("%s\n", display_error(DIRTY_INPUT));
                printf(": ");
            }
        }while(sanitized_input == -2);
        current_number = sanitized_input;
        
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

