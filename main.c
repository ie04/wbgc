/* 
 * File:   main.c
 * Author: Iyad Eltifi
 *
 * Created on November 15, 2018, 5:54 PM
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "score.h"
#include "add_array_numbers.h"
#include "scan.h"
#include "constants.h"
#include "error.h"
/*
 * 
 */
int main(void) {
    /*
     */
    int scale_amount = 0; //Amount of different scales user inputs
    int sanitized_input = 0; //Receives user input after a sanity check
    float calculated_grade = 0; //Final calculated grade
    float scored_numbers[MAX_SCORE_AMOUNT] = {0}; /*Array of numbers that are weighted and scored*/  
    char input[MAX_INPUT_AMOUNT] = {0}; //Raw user input
    /*
     * the sanity_test() method returns -1 if user-input is not an integer,
     * and the number user inputted otherwise
     */
    system("clear");
    printf("Grade Calculator version 1.0\nCopyleft Iyad Eltifi\n\n");
    do{
    __fpurge(stdin);
    printf("Enter amount of different scales (maximum %d)\n: ", MAX_SCORE_AMOUNT);
    fgets(input, BUFFER, stdin);
    system("clear"); // Sends clear command to terminal
    sanitized_input = int_sanity_test(input);
    if(sanitized_input < 0)
        printf("%s\n", display_error(NEGATIVE));
    if(sanitized_input > MAX_SCORE_AMOUNT)
        printf("%s, autosetting to %d\n", display_error(OUT_OF_BOUNDS), MAX_SCORE_AMOUNT);
    
    }while((sanitized_input == -1) || (sanitized_input < 1));

    scale_amount = sanitized_input;
        
    //Sanitizes inputs that are out of bounds
    if(scale_amount > MAX_SCORE_AMOUNT)
        scale_amount = MAX_SCORE_AMOUNT;
    
    //User-defined scales stored in an array
    scale user_scales[scale_amount];
    float weights[MAX_SCORE_AMOUNT] = {0};
    float added_weights = 0;
    for(int i=0; i<scale_amount; i++){
        user_scales[i] = calculate_score(i+1);
    }
    
    for(int i=0;i<scale_amount; i++){
        weights[i] = (user_scales[i].weight * 100);
    }
    added_weights = add_array_numbers_float(weights);
    if(added_weights != 100){
        if(not_equals_yno() == 1)
            main();
    }
        
    for(int i=0; i<scale_amount; i++){
        display_scale(user_scales[i]);
    }
    
    for(int i=0; i<scale_amount; i++){
        scored_numbers[i] = user_scales[i].grade;
    }
    //r-value adds array numbers
    calculated_grade = add_array_numbers_float(scored_numbers);
    
    printf("Your class grade is %.1f%%\n", calculated_grade);
    
    return 0;
}

