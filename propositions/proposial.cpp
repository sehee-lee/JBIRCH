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
    
    double points[2];
   
	double var=0;
	double t=0;
	double change[50] = {0};
	double sd=0;
    while(obj[j] != 0){
        datafile = fopen("../dataset/DDS4_S", "r");
		i = 1;
        while(fgets(line, 500, datafile)){
            
            if(obj[j] == i){
                
                token = strtok(line, sep);
                points[0] = atof(token);
                token = strtok(NULL, sep);
                points[1] = atof(token);
        		fclose(datafile);    
                break;
            }
            
            else
                i++;
        }
       
        cent[0] = cent[0] * j + points[0];
        cent[1] = cent[1] * j + points[1];
      
		cent[0] /= j+1;
		cent[1] /= j+1;
		if(j != 0){
			var = sqrt( pow(pre_cent[0] - cent[0],2.0) + pow(pre_cent[1] - cent[1], 2.0));
			change[j-1] = var;
			t += var;
		}
		
        j++;
   		 
		pre_cent[0] = cent[0];
		pre_cent[1] = cent[1];
	

        printf("%d : %f, %f _ %f | ",j,pre_cent[0],pre_cent[1], var);
	}
	if(t != 0){
    	to += t/(j-1);
		idx = idx + 1;
		int k = 0;
		while(change[k] != 0){
			
			sd += pow((t/(j-1)) - change[k],2.0);
			k++;
			
		}

		sd /= j;
		avg_sd += sd;
		printf("SD : %f | ",sd);
	}
    printf("\n");
    
    
}

void init(int *obj, double *cent){
    
    int i;
    for(i=0; i<50; i++)
        obj[i] = 0;
    
    for(i=0; i<2; i++)
        cent[i] = 0;
    
}
int main(int argc, char *argv[]){
   
	to = 0;
	idx = 0;
	avg_sd = 0;

    char *name = argv[1];
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
	printf("total : %d\n",idx);
    return 0;
}
