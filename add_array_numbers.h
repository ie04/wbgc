
/* 
 * File:   add_array_numbers.h
 * Author: Iyad Eltifi
 *
 * Created on November 15, 2018, 6:57 PM
 */

#ifndef ADD_ARRAY_NUMBERS_H
#define ADD_ARRAY_NUMBERS_H

float add_array_numbers_float(float array[]){
    
    float added_array = 0.0;
    
    //all array values starting from 0 added into variable added_array
    for(int i=0; i<=5; i++){
        added_array += array[i];
    }
    return added_array;
}
int add_array_numbers_int(int array[]){
    
    int added_array = 0;
    
    //all array values starting from 0 added into variable added_array
    for(int i=0; i<=5; i++){
        added_array += array[i];
    }
    return added_array;
}
#endif /* ADD_ARRAY_NUMBERS_H */

