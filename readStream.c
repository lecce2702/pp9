#include<stdio.h>
#include<stdlib.h>
#define INPUTBUFFSIZE 256

double *SL_getDoubStream(FILE*fp, int*n){
	int count = 0;
	char str[INPUTBUFFSIZE];
	double *arr = malloc(sizeof(double)*1);
	char * ptr;
	while(NULL != (fgets(str, INPUTBUFFSIZE, fp))){
		arr[count] = strtod(str, &ptr);
		count++;
		arr = realloc(arr, sizeof(double)*(count+1));
	}
	*n = count;
	return arr;
}
