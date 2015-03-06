#include <stdio.h>
#include <math.h>
#include <stdlib.h>


char *getpoints(int line, FILE *f){

	char *l;
	l = (char*)malloc(sizeof(char)*500);
	int n = 1;
	while(fgets(l,500,f)){

		if(line = n){
			return l;
		}
		
		n++;

	}
	
	return "error\n";
	
}


int main(int argc, char *argv[]){

	FILE *originalfile = fopen(argv[1],"r");
	FILE *resultfile = fopen(argv[2], "w");


	int *used;
	int get_line, total;
	bool check = true;
	total = atoi(argv[3]);
	used = (int*)malloc(sizeof(int)*total);
	int current = 0;

	for(int i=0; i<total; i++)
		used[i] = 0;
	int j = 0;
	while(current != total){
		j = 0;
		check = true;
		get_line = (rand()%total)+1;
		printf("get line : %d || current line : %d\n",get_line, current);
		while(used[j] != 0){

			if(used[j] == get_line){
				check = false;
				break;
			}
			else
				j++;


		}
		
		if(check){
			used[j] = get_line;
			char *line = getpoints(get_line, originalfile);
			fprintf(resultfile,"%s",line);
			current ++;
			printf("current line : %d\n",current);
		}


	}


	fclose(originalfile);
	fclose(resultfile);

	return 0;

}
