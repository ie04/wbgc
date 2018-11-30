
/* 
 * File:   not_equals_yno.h
 * Author: Iyad Eltifi
 *
 * Created on November 25, 2018, 1:57 PM
 */

#ifndef NOT_EQUALS_YNO_H
#define NOT_EQUALS_YNO_H
#include <stdio.h>
#include "scan.h"
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

#endif /* NOT_EQUALS_YNO_H */

