#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){

	FILE *sfp;
	FILE *efp;
	
	sfp = fopen(argv[1],'r');
	efp = fopen(argv[2],'r');

	char *token, *sep=" ,[]\n";
	char line[200];
	int obj[50];

	for(int i=0; i<50; i++)
		obj[i] = 0;


	return 0;
}
