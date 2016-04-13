#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pCML.h"
#include "pCML.c"
#define MEMORIA_MAXIMA 10000000

int main(){

	FILE *fp;
	fp = fopen("string.txt", "r");
	if(fp == NULL){
		printf("Archivo no existe\n");
	}
	// http://stackoverflow.com/questions/19068643/dynamic-memory-allocation-for-pointer-arrays 
	char **strings;
	//Pedimos mucha memoria para optimizar el tiempo
	strings = malloc( sizeof(char) * MEMORIA_MAXIMA);
	int i, nuevotamanio = 0;
	while (!feof(fp))
	{
		char* palabra;
		palabra = (char *) malloc(201*sizeof(char));
		if( fgets (palabra, 201, fp)!=NULL ) 
		{
			palabra = realloc(palabra, strlen(palabra));

			strings[i] = palabra;
			nuevotamanio += strlen(palabra)*sizeof(char);
		}
		i++;
	}
	strings = realloc(strings, nuevotamanio);

	pCML(strings, i-1);
	//probamos
	// int i2;
	// for (i2 = 0; i2 < i-1; ++i2)
	// {
	// 	printf("%i %s\n",i2, strings[i2]);
	// }

	fclose(fp);
	free((void *)strings);
	return 0;
}