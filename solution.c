#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 39

unsigned long fibonacci(unsigned int n);
unsigned long * fibonacci_array(unsigned int n);
void unsigned_long_swap(unsigned long *a, unsigned long *b);
void unsigned_long_reverse_array(unsigned long *array, unsigned int size);
void unsigned_long_bubble_sort(unsigned long *array,unsigned int size);

int main(int argc, char *argv[]){

	unsigned long * fibonacci_result;
	fibonacci_result=fibonacci_array(SIZE);
	unsigned long *fibonacci_result_copy;

	memcpy(fibonacci_result_copy,fibonacci_result,sizeof(unsigned long)*SIZE);

	unsigned_long_reverse_array(fibonacci_result_copy,SIZE);

	unsigned_long_bubble_sort(fibonacci_result_copy,SIZE);

	int result=memcmp(fibonacci_result,fibonacci_result_copy,SIZE*sizeof(unsigned long));

	printf("risultato: %d",result);
}

unsigned long fibonacci (unsigned int n){

	int fibo0=0;
	int fibo1=1;
	unsigned long fibonacci;

	if (n==0) return fibo0;
	if (n==1) return fibo1;

	for (int i=0;i<n-1;i++){
		fibonacci=fibo1+fibo0;
		fibo0=fibo1;
		fibo1=fibonacci;
	}
	return fibonacci;
}

unsigned long * fibonacci_array(unsigned int n){

	unsigned long *fibonacci_array;
	fibonacci_array=calloc(n+1,sizeof(unsigned long));
	for (unsigned int i=0;i<=n;i++)
		fibonacci_array[i]=fibonacci(i);
	return fibonacci_array;
}

void unsigned_long_swap(unsigned long *a, unsigned long *b){
	unsigned long buffer;
	buffer=*a;
	*a=*b;
	*b=buffer;
}

void unsigned_long_reverse_array(unsigned long *array, unsigned int size){

	for (unsigned int i=0;i<size/2;i++){
		unsigned_long_swap(&array[i],&array[size-i-1]);
	}
}

void unsigned_long_bubble_sort(unsigned long *array,unsigned int size){

	bool flag=false;
	while (flag==false){

		flag=true;

		for (unsigned int i=0;i<size;i++){
			if (array[i]>array[i+1]){
				unsigned_long_swap(&array[i],&array[i+1]);
				flag=false;
			}
		}
	}
}
