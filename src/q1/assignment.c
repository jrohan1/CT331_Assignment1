#include <stdio.h>

int main(int arg, char* argc[]) {
	printf("Hello assignment1.\n");

	int i = 10;
	int* iPointer = &i;
	long l;
	double *dPointer;
	char **string;

	printf("size of int =  %ld\n", sizeof(i));
	printf("size of int Pointer = %ld\n", sizeof(iPointer));
	printf("size of long =  %ld\n", sizeof(l));
	printf("size of double Pointer = %ld\n", sizeof(dPointer));
	printf("size of string pointer = %ld\n", sizeof(string));

	return 0;
}