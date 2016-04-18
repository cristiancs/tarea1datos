#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pCML.h"
#include "descomprimir.h"
#define MEMORIA_MAXIMA 10000000


char** cargarDataF1(int *i){
	FILE *fp;
	fp = fopen("string.txt", "r");
	if(fp == NULL){
		printf("Archivo no existe\n");
	}
	// http://stackoverflow.com/questions/19068643/dynamic-memory-allocation-for-pointer-arrays 
	char **strings;
	//Pedimos mucha memoria para optimizar el tiempo
	strings = malloc( sizeof(char) * MEMORIA_MAXIMA);
	int nuevotamanio = 0;
	while (!feof(fp))
	{
		char* palabra;
		palabra = (char *) malloc(201*sizeof(char));
		if( fgets (palabra, 201, fp)!=NULL ) 
		{
			palabra = realloc(palabra, strlen(palabra));

			strings[*i] = palabra;
			nuevotamanio += strlen(palabra)*sizeof(char);
		}
		(*i)++;
	}
	(*i)--;
	strings = realloc(strings, nuevotamanio);
	fclose(fp);
	return strings;
}

char cargarDataF2(){
	return "c";
}



int main(){

// Función 2
	//descomprimir();











// Funcion 1
	int cantidad = 0;
	char **strings = cargarDataF1(&cantidad);
	pCML(strings, cantidad);
	//probamos
	// int i2;
	// for (i2 = 0; i2 < cantidad; ++i2)
	// {
	// 	printf("%i %s",i2, strings[i2]);
	// }

	
	free((void *)strings);
	return 0;
}