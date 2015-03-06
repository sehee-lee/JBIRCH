#include<iostream>
#include<fstream>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<sstream>
#include<string>

using namespace std;

int main(int argc, char *argv[]){

	int N = atoi(argv[1]);
	char *file_x=(argv[2]);
	char *file_o(argv[3]);
	char line[500];;

	FILE *fx = fopen(file_x,"r");
	FILE *fo = fopen(file_o,"w");
	
	char *c_x_point;
	int i=5;
	int loc=1;
	int k=0, j=0;
	float **points;

	points = (float**)malloc(sizeof(float*)*N);
	for(int j=0; j<N; j++)
		points[j] = (float*)malloc(sizeof(float)*2);

	
	while(i<N){
		fgets(line, sizeof(line), fx);
		c_x_point = strtok(line," ,\n");

			
        points[i][0] = atof(c_x_point);
        //points[i][0] *= 20;
        c_x_point = strtok(NULL, ",\n");
        points[i][1] = atof(c_x_point);
        //points[i][1] *= 20;
        fprintf(fo, "%f %f\n", points[i][0], points[i][1]);
            
        i++;
			

	}


	return 0;
}
