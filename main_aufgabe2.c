#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "summarystats.h"

#define INPUTBUFFSIZE 256

int main(int argc, char *argv[]){
	char Input_Buff[INPUTBUFFSIZE];
	int n1;
	int *arr1;
	float avg, stddev;
	FILE *ptr = fopen("output_stream", "r");
	if (NULL == ptr) {
		printf("file can't be opened \n");
		exit(1);
	}
	arr1 = SL_getIntStream(ptr, &n1);
	for (int i=0; i<n1; i++){
		avg = SL_getAvg(arr1[i]);
	}
	for (int j=0; j<n1; j++){
		stddev = SL_getStddev(arr1[j], avg);
	}
	stddev = stddev/n1;
	printf("Der Stichprobenmittelwert betraegt %f und die Standardabweichung %f\n", avg, stddev);
	fclose(ptr);
	free(arr1);
	return 0;
	
}
	
