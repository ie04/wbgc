
/* 
 * File:   sanity.h
 * Author: ie04
 *
 * Created on November 16, 2018, 5:41 PM
 */

#ifndef SANITY_H
#define SANITY_H

int int_sanity_test(char* input);
float float_sanity_test(char* input);
float float_sanity_test_avg(char* input);
int sanitize_yno(char *yno);
int not_equals_yno();
int input_cleaner_scale_amount();
int input_cleaner_weight(char *label);
float input_cleaner_avg();

#endif /* SANITY_H */

