#include <stdio.h>

int getAmount(int);
double withdraw(int amount, int removing){
  double charge=0.50;
  double result=0;
  if(removing > amount){
    printf("\nInsufficient funds, withdrawal cancelled.\n");
    return amount;
  }//thhis is in the scenario that removing is greater, else
  if(removing%5==0){//check if the withdrawn amount is a multiple of 5
    result=amount-removing;
    printf("\nResult is: %.2lf", result);
    result-=charge;
    printf("\nAfter taking charge interest, result is: %.2lf", result);
  }
  else{
    result=amount; 
  }
  return result;
}
int main() {
  int user_amount=1000;
  getAmount(user_amount);
  withdraw(user_amount, 40);
  withdraw(user_amount, 22);
  withdraw(user_amount, 9000);
  return 0;
}

int getAmount(int data){
  printf("The user has: %d", data);
  return data;
}