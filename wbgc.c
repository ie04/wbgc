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
/*
 * 
 */
int main(void) {

    
    int scale_amount = 0; //Amount of different scales user inputs
    float calculated_grade = 0; //Final calculated grade
    float scored_numbers[MAX_SCORE_AMOUNT] = {0}; /*Array of numbers that are weighted and scored*/  
    const char* filename = "data";
    /*
     * the sanity_test() method returns -1 if user-input is not an integer,
     * and the number user inputted otherwise
     */
    system("clear");
    printf("Weight Based Grade Calculator version 0.1\n\n");
    scale_amount = input_cleaner_scale_amount(); //Checks sanity of input
        
    //Sanitizes inputs that are out of bounds
    if(scale_amount > MAX_SCORE_AMOUNT)
        scale_amount = MAX_SCORE_AMOUNT;
    
    //User-defined scales stored in an array
    scale user_scales[scale_amount];
    
    //array of scale percentages 
    float weights[MAX_SCORE_AMOUNT] = {0};
    float added_weights = 0;
    for(int i=0; i<scale_amount; i++){
        user_scales[i] = calculate_score(i+1);
    }
    
    for(int i=0;i<scale_amount; i++){
        
        //Weights are multiplied by 100 from fraction value
        weights[i] = (user_scales[i].weight);
    }
    added_weights = add_array_numbers_float(weights);
    if(added_weights != 100){
        if(not_equals_yno() == 1)
            main();
    }
        
    for(int i=0; i<scale_amount; i++){
        display_scale(user_scales[i]);
        append_scale(filename, user_scales[i]);
    }
    
    for(int i=0; i<scale_amount; i++){
        scored_numbers[i] = user_scales[i].grade;
    }
    //r-value adds array numbers
    calculated_grade = add_array_numbers_float(scored_numbers);
    printf("Your class grade is %.1f%%\n", calculated_grade);
    return 0;
}

