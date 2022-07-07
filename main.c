#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include "gauss_lib.h"

const char VERSIONSNR[] = "0.1";

int main(int argc, char* argv[]){
	int option;
	int expected_value;
	int std_deviation;
	int amount_of_values;
	FILE * ptr = fopen ("output_stream", "w");
	if(ptr == NULL){
		printf("Error!");   
		exit(1);             
	}

	while((option = getopt(argc, argv, "hvg")) != -1)
	switch(option){
		case 'h':
			printf("-h = Hilfe\n");
			printf("-v = Version\n");
			printf("-g = Eingabe der benoetigten Argumente\n");
			exit(0);
		case 'v':
			printf("Version: %s\n", VERSIONSNR);
			exit(0);
		case 'g':
			printf("Eingabe des Erwartungswerts\n");
			scanf("%d", &expected_value);
			printf("Eingabe der Standardabweichung\n");
			scanf("%d", &std_deviation);
			printf("Eingabe der Anzahl der Zufallswerte\n");
			scanf("%d", &amount_of_values);
			break;

		default:
			printf("Da ist was schiefgegangen\n");
			printf("Eingabe von -h erklärt mehr\n");
			exit(0);
	}
	print_gaussian_dist(expected_value, std_deviation, amount_of_values, ptr);
	fclose(ptr);
	return 0;
}
