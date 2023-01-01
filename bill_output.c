/*
 * Name: Samuel Kusi Amportey
 * CS262, Lab Section 210
 *In Lab 1 Assignment
 */
#include <stdio.h>

int main(){
    int hours;
    double rate, total_bill;
    printf("Enter  a whole number for hours:");
    scanf("%d", &hours);
    printf("\nEnter  a double number for the rate:");
    scanf("%lf", &rate);
    //printf("Check %d hours and %lf rate", hours,rate);
    total_bill=rate * hours;
    printf("Bill = %.1lf\n", total_bill);
    return 0;

}
