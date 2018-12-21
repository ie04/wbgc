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
<<<<<<< HEAD
#include "conversions.h"
=======
>>>>>>> refs/remotes/origin/file_implementation
/*
 * 
 */
int main(void) {

    wbgc_class new_class; //Creates class struct to hold data for class
    const char* filename = "data";
    
<<<<<<< HEAD
    system("clear");
    printf("Weight Based Grade Calculator version 0.1\n\n");
    
    new_class.scale_amount = input_cleaner_scale_amount(); //Checks sanity of input
=======
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
>>>>>>> refs/remotes/origin/file_implementation
        
    //Sanitizes inputs that are out of bounds
    if(new_class.scale_amount > MAX_SCALE_AMOUNT)
        new_class.scale_amount = MAX_SCALE_AMOUNT;
    
<<<<<<< HEAD
 
       
    for(int i=0; i<new_class.scale_amount; i++){  //scales are inputted and stored in array
        new_class.user_scales[i] = calculate_score(i+1); 
    }
 
    for(int i=0;i<new_class.scale_amount; i++){  
        
        new_class.weights[i] = (new_class.user_scales[i].weight);
=======
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
>>>>>>> refs/remotes/origin/file_implementation
    }
    new_class.added_weights = add_array_numbers_float(new_class.weights);
    
    if(new_class.added_weights != 100){ //Tests if weight percentages add up to 100, if not then restart
        if(not_equals_yno() == 1)
            main();
    }
        
<<<<<<< HEAD
    for(int i=0; i<new_class.scale_amount; i++){ //Displays scale details on screen
        display_scale(new_class.user_scales[i]);
        file_append_scale(filename, new_class.user_scales[i]);
=======
    for(int i=0; i<scale_amount; i++){
        display_scale(user_scales[i]);
        append_scale(filename, user_scales[i]);
>>>>>>> refs/remotes/origin/file_implementation
    }
    
    for(int i=0; i<new_class.scale_amount; i++){ //Total grade points stored in separate float array
        new_class.scored_numbers[i] = new_class.user_scales[i].grade;
    }
<<<<<<< HEAD
 
    new_class.calculated_grade = add_array_numbers_float(new_class.scored_numbers); //Float array is added up to final answer
    printf("Your class grade is %.1f%%\n", new_class.calculated_grade);
    int bro = file_get(filename,0); 
    printf("%s", int_to_char_array(bro));
=======
    //r-value adds array numbers
    calculated_grade = add_array_numbers_float(scored_numbers);
    printf("Your class grade is %.1f%%\n", calculated_grade);
>>>>>>> refs/remotes/origin/file_implementation
    return 0;
}

