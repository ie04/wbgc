
/* 
 * File:   main.c
 * Author: ie04
 *
 * Created on December 8, 2018, 1:26 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkstruct.h"
void print_list(node * head);
int main(int argc, char** argv) {
    node * head = NULL;
    head = malloc(sizeof(node));
    head->data = "h";
    head->next = malloc(sizeof(node));
    head->next->data = "e";
    head->next->next = malloc(sizeof(node));
    head->next->next->data = "l";
    head->next->next->next = malloc(sizeof(node));
    head->next->next->next->data = "l";
    head->next->next->next->next = NULL;
    print_list(head);
    return 0;
}
void print_list(node * head) {
    node * current = head;

    while (current != NULL) {
        printf("%c\n", current->data);
        current = current->next;
    }
}
