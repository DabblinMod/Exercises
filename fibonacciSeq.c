//creating a fibonacci sequence

#include <stdio.h> 

//the fibonacci number sequence method is: (n-1) + (n-2) 

int fib(int x){//caller method and function type check will execute here
	//we use recursion to execute the method to get the fibonacci numbers
	if (x==0)
		return 0;
	else if(x==1)
		return x;
	return fib(x-1) + fib(x-2);
}

int main(void){//main method executor
	int x=10;
	int ans=fib(x);
	printf("The answer is: %d", ans);
	return 0;

}