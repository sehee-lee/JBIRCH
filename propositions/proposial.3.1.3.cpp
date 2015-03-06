//
//  proposial.cpp
//  
//
//  Created by Jayden Sehee Lee on 5/19/14.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


double to;
int idx;
double avg_sd;

void get_centroid(int *obj){
    
    double cent[2] = {0,0};
    double pre_cent[2] = {0,0};
    FILE *datafile;
    
    int i=1;
    char line[500];
    int j=0;
    char *token = NULL, *sep=" ,\n";
    
    double points[10][2];
   
	double var=0;
	double t=0;
	double change[50] = {0};
	double sd=0;

	double centroids[10][2];

	int index = 0;

	for(int a=0; a<10; a++)
		for(int b=0; b<2; b++)
			centroids[a][b] = 0;

    while(obj[j] != 0){
        datafile = fopen("DDS1_0", "r");
		i = 1;
        while(fgets(line, 500, datafile)){
            
            if(obj[j] == i){
                
                token = strtok(line, sep);
                points[index][0] = atof(token);
                token = strtok(NULL, sep);
                points[index++][1] = atof(token);
        		fclose(datafile);    
                break;
            }
            
            else
                i++;
        }
       
	}

	int cent_index = 0;
	int point_index = 0;
	if(index != 1){

		for(int l = 1; l<=index; l++){
			if(cent_index == 0){
			
				centroids[cent_index][0] = points[0][0];
				centroids[cent_index++][1] = points[0][1];

			}
			else{

				centroids[cent_index][0] = (centroids[cent_index-1][0] *
						cent_index) + points[point_index][0];
				centroids[cent_index][1] = (centroids[cent_index-1][1] *
						cent_index) + points[point_index++][1];

				cent_index ++;

				centroids[cent_index-1][0] /= cent_index;
				centroids[cent_index-1][1] /= cent_index;

			}
			
		}
	}

	double center_centroid[2]={0};

	for(int l = 0; l<cent_index; l++){
		center_centroid[0] += centroids[l][0];
		center_centroid[1] += centroids[l][1];
	}
	center_centroid[0] /= cent_index;
	center_centroid[1] /= cent_index;

	



    
}

void init(int *obj, double *cent){
    
    int i;
    for(i=0; i<50; i++)
        obj[i] = 0;
    
    for(i=0; i<2; i++)
        cent[i] = 0;
    
}
int main(void){
   
	to = 0;
	idx = 0;
	avg_sd = 0;

    char *name = "result";
    char line[500];
    char *sep = " [],\n";
    char *token=NULL;
    FILE *file;
    file = fopen(name, "r");
    int i;
    int obj[50];
    double cent[2];
    int j=0;
    while(fgets(line, 500, file)){
		i=0;
        init(obj, cent);
        token = NULL;
        token = strtok(line, sep);
        obj[i++] = atoi(token);
        while(token = strtok(NULL, sep)){
            obj[i++] = atoi(token);
        }
        
        printf("%d. =============\n",++j);
        get_centroid(obj);
    }

	printf("avg : %f | avg sd : %f\n", to/idx, avg_sd/idx);

    return 0;
}
