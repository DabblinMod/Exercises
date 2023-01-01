/*
 * Name: Samuel Kusi Amportey
 * CS262 Lab Section: 210
 * In Lab 1 Assignment
 */

#include <stdio.h>
#include <ctype.h>
/* Goal: Take input from user as a Capital letter
 * then convert capital letter to lowercase
 */

int main(){
    char ltr, lower;
    printf("Please type in a capital letter:");
    scanf("%c", &ltr);
    ltr=toupper(ltr);
//scanf will consume any whitespace before it, such as the \n, make space
    //printf("Here is %c\n", ltr);
    ltr=tolower(ltr);
    printf("Output: %c\n", ltr);
    return 0;
}

