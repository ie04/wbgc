
/* 
 * File:   sanity.h
 * Author: ie04
 *
 * Created on November 16, 2018, 5:41 PM
 */

#ifndef SANITY_H
#define SANITY_H
#include "constants.h"
#include "error.h"
#include <stdio.h>
int int_sanity_test(char* input){
    int number = 0;
    int error_test = 0;
    float bad_float = 0;
    char bad_char = 0;
    error_test = sscanf(input, "%d %c %f", &number, &bad_char, &bad_float);
    if(error_test != 1)
        return -1;
    else
        return number;
}

float float_sanity_test(char* input){
    float number = 0;
    int error_test = 0;
    int bad_int = 0;
    char bad_char = 0;
    error_test = sscanf(input, "%f %c %d", &number, &bad_char, &bad_int);
    if(error_test != 1)
        return -1;
    else
        return number;
}
float float_sanity_test_avg(char* input){
    float number = 0;
    int error_test = 0;
    int bad_int = 0;
    char bad_char = 0;
    error_test = sscanf(input, "%f %c %d", &number, &bad_char, &bad_int);
    if(error_test != 1)
        return -2;
    else
        return number;
}
int sanitize_yno(char *yno){
    switch(*yno){
        case 'Y':
            *yno = 'y';
            return 0;
            
        case 'N':
            *yno = 'n';
            return 0;
            
        case 'y':
            return 0;
         
        case 'n':
            return 0;
            
        default:
            return 1;
    }
}
int not_equals_yno(){
        char yno;
        int oob;
        printf("Weights don't add up to 100!\n\nRestart?(y/n): ");
        scanf(" %c", &yno);
        oob = sanitize_yno(&yno);
        if(oob == 1)
            exit(1);
        if(yno == 'y')
            return 1;
        else
            exit(1);
}
int input_cleaner_int(){
    char input[MAX_INPUT_AMOUNT] = {0}; //Raw user input
    int sanitized_input;
        do{
    __fpurge(stdin);
    printf("Enter amount of different scales (maximum %d)\n: ", MAX_SCORE_AMOUNT);
    fgets(input, BUFFER, stdin);
    system("clear"); // Sends clear command to terminal
    sanitized_input = int_sanity_test(input);
    if(sanitized_input < 0)
        printf("%s\n", display_error(NEGATIVE));
    if(sanitized_input > MAX_SCORE_AMOUNT)
        printf("%s, auto-setting to %d\n", display_error(OUT_OF_BOUNDS), MAX_SCORE_AMOUNT);
    
    }while((sanitized_input == -1) || (sanitized_input < 1));
    
    return sanitized_input;
}
int input_cleaner_float(char *label){
    float sanitized_input;
    char input[MAX_INPUT_AMOUNT];
    
    do{
        printf("How much does scale \"%s\" weigh for the class (percentage)?\n: ", label);
        __fpurge(stdin); //Clears stdin from carriage-returns
        fgets(input, BUFFER, stdin);
        sanitized_input = float_sanity_test(input) / 100;
        system("clear");
        if((sanitized_input == -1) || (sanitized_input > 1) || (sanitized_input < 0.01))
            printf("%s\n", display_error(DIRTY_INPUT));
        
    }while((sanitized_input == -1) || (sanitized_input > 1) || (sanitized_input < 0.01));
    
    return sanitized_input;
}
    
#endif /* SANITY_H */

