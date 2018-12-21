/* 
 * File:   main.c
 * Author: ie04
 *
 * Created on November 15, 2018, 5:54 PM
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "scale.h"
#include "add_array_numbers.h"
#include "sanity.h"
#include "constants.h"
#include "error.h"
#include "file.h"
#include "conversions.h"
/*
 * 
 */
int main(void) {

    wbgc_class new_class; //Creates class struct to hold data for class
    const char* filename = "data";
    
    system("clear");
    printf("Weight Based Grade Calculator version 0.1\n\n");
    
    new_class.scale_amount = input_cleaner_scale_amount(); //Checks sanity of input
        
    //Sanitizes inputs that are out of bounds
    if(new_class.scale_amount > MAX_SCALE_AMOUNT)
        new_class.scale_amount = MAX_SCALE_AMOUNT;
    
 
       
    for(int i=0; i<new_class.scale_amount; i++){  //scales are inputted and stored in array
        new_class.user_scales[i] = calculate_score(i+1); 
    }
 
    for(int i=0;i<new_class.scale_amount; i++){  
        
        new_class.weights[i] = (new_class.user_scales[i].weight);
    }
    new_class.added_weights = add_array_numbers_float(new_class.weights);
    
    if(new_class.added_weights != 100){ //Tests if weight percentages add up to 100, if not then restart
        if(not_equals_yno() == 1)
            main();
    }
        
    for(int i=0; i<new_class.scale_amount; i++){ //Displays scale details on screen
        display_scale(new_class.user_scales[i]);
        file_append_scale(filename, new_class.user_scales[i]);
    }
    
    for(int i=0; i<new_class.scale_amount; i++){ //Total grade points stored in separate float array
        new_class.scored_numbers[i] = new_class.user_scales[i].grade;
    }
 
    new_class.calculated_grade = add_array_numbers_float(new_class.scored_numbers); //Float array is added up to final answer
    printf("Your class grade is %.1f%%\n", new_class.calculated_grade);
    int bro = file_get(filename,0); 
    printf("%s", int_to_char_array(bro));
    return 0;
}

