#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pCML.h"

int main(){

	FILE *fp;
	fp = fopen("string.txt", "r");
	if(fp == NULL){
		printf("Archivo no existe\n");
	}
	char* strings;
	int i = 1;
	while (!feof(fp))
	{
		i++;
		char palabra[201];
		fread(&palabra, sizeof(char), 1, fp);
		printf("%i %s\n",i, palabra);
		/* code */
	}

	return 0;
}