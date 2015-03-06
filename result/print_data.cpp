#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void printpoints(int line, FILE *f){


	char *l;
	l = (char*)malloc(sizeof(char)*500);
	int n = 1;
	
	while(fgets(l,500,f)){

		if(line = n){
			printf("%s",l);
			break;
		}

		n++;
	}

}

int main(int argc, char *argv[]){

	FILE *fo = fopen(argv[1], "r");

	FILE *rf = fopen(argv[2], "r");

	if(argc != 3){
		printf("Input Data file name , Clustering result file name\n");
		return 0;
	}


	char l[500];
	char *sep = " [],\n";
	char *token;

	while(fgets(l,500,rf)){

		token = strtok(l,sep);
		printpoints(atoi(token),fo);
	
		token = strtok(NULL, sep);
		while(token != NULL){
			printpoints(atoi(token),fo);
			token = strtok(NULL, sep);
		}

		printf("=====================\n");

	}


	return 0;

}

