#include<math.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
void print_gaussian_dist(double expected_value, double std_deviation, int amount_of_values, FILE * output_stream){
	// Anzahl der Datensätze erzeugen
	//Initialisierung des Zufallszahlengenerators über Systemzeit
	int sek = time(0);
	srand(10000*sek);
	double random_uniform(){
		return (double)rand() / (double)(RAND_MAX);
	}
	double stdnorm[amount_of_values];
	double normal[amount_of_values];
	double uniform1[amount_of_values];
	double uniform2[amount_of_values];
	for (int i=0; i < amount_of_values; i++){
		uniform1[i] = random_uniform();
		uniform2[i] = random_uniform();
		stdnorm[i]= sqrt((-2.0)*log(uniform1[i]))*cos(2.0*M_PI*uniform2[i]);
		normal[i] = stdnorm[i]*std_deviation + expected_value;	
		fprintf(output_stream, "%lf\n ", normal[i]);
	}
}
