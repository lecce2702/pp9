#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INPUTBUFFSIZE 256

int *SL_getIntStream(FILE *fp, int *n){
	char str[INPUTBUFFSIZE];
	char *token;
	char delim[] = " ";
	int *arr = NULL;
	int count = 0;
	
	if(NULL == (fgets(str, INPUTBUFFSIZE, fp))){
		printf("File can't be opened\n");
		exit(1);
	}
	for (token = strtok(str, delim); token != NULL; token = strtok(NULL, delim)){
		if (NULL == (arr = realloc(arr, (count+1) * sizeof(int)))){
			perror("realloc");
			exit(1);
		}
		arr[count] = (int) strtol(token, (char **)NULL, 10);
		count++;
	}
	*n = count;
	return arr;
}

