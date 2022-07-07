#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INPUTBUFFSIZE 256
#include <summarystats.h>

int main(int arc, char *argv[])
{
	int n1;
	double *arr;
	double avg, stddev;
	FILE  *ptr = fopen("output_stream", "r");
	if (NULL== ptr){
		printf("File can't be opened \n");
		exit(1);
	}
	arr = SL_getDoubStream(ptr, &n1);
	for (int i = 0; i<n1; i++){
		avg = SL_getAvg(arr[i]);
	}
	for (int j = 0; j<n1; j++){
		stddev = SL_getStddev(arr[j], avg);
	}
	stddev = stddev/n1;
	printf("Der Stichprobenmittelwert betraegt %f und die Standardabweichung %f\n", avg, stddev);
	fclose(ptr);
	free(arr);
	return 0;
}
