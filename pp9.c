#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "statlib.h"

const char VERSIONSNR[] = "0.1";

int main(int argc, char* argv[]){

	int option;
	int expected_value;
	int std_deviation;
	int amount_of_values;
	FILE *ptr = fopen ("output_stream", "w");

	while((option = getopt(argc, argv, "hvg")) != -1)
	switch(option)
	{
		case 'h':
			printf("-h = help\n");
			printf("-v = version\n");
			printf("-g = input of needed arguments\n");
			exit(0);

		case 'v':
			printf("Version: %s\n", VERSIONSNR);
			exit(0);

		case 'g':
			printf("Enter the expected value!\n");
			scanf("%d", &expected_value);
			printf("Enter the standart deviation!\n");
			scanf("%d", &std_deviation);
			printf("Enter the amount of values!\n");
			scanf("%d", &amount_of_values);
			break;

		default:
			printf("Something went wrong!\n");
			printf("Use -h for help!\n");
			exit(0);
	}
	
	print_gaussian_dist(expected_value, std_deviation, amount_of_values, ptr);

	return 0;
}	
