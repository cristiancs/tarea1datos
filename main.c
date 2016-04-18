#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pCML.h"
#include "descomprimir.h"
#define MEMORIA_MAXIMA 10000000

/*****
* char cargarData1
******
* Abre un archivo en txt y retorna un arreglo de string con las strings encontradas
******
* Input:
* char *nombre : Nombre del archivo a leer
* int  *i      : Variable que escribe la cantidad de elementos encontrados
******
* Returns:
* char**, listado de string encontradas
*****/
char** cargarData1(char *nombre, int *i){
	FILE *fp;
	fp = fopen(nombre, "r");
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


char** cargarData2(char *nombre, int *i){
	FILE *fp;
	fp = fopen(nombre, "r");
	if(fp == NULL){
		printf("Archivo no existe\n");
	}
	// http://stackoverflow.com/questions/19068643/dynamic-memory-allocation-for-pointer-arrays 
	char **strings;
	strings = malloc( sizeof(char) * 1);
	int nuevotamanio = 0;
	while (!feof(fp))
	{
		char* palabra;
		palabra = (char *) malloc(101*sizeof(char));
		if( fgets (palabra, 101, fp)!=NULL ) 
		{
			size_t len = strlen(palabra);
			strings = realloc(strings, nuevotamanio+101*sizeof(char));
			palabra = realloc(palabra, len);
			// http://stackoverflow.com/a/27729970/2213659
			if (len > 0 && palabra[len-1] == '\n') {
			 	palabra[--len] = '\0';
			}
			strings[*i] = palabra;
			nuevotamanio += len*sizeof(char);
		}
		(*i)++;
	}
	(*i)--;
	strings = realloc(strings, nuevotamanio);
	fclose(fp);
	return strings;
}



int main(){

// Función 2
	int cantidadArchivos = 0;
	char file2[] = "input-strings.txt";
	char **archivos = cargarData2(file2,&cantidadArchivos);

	//Llamar a descomprimir
	int i2;
	for (i2 = 0; i2 < cantidadArchivos; ++i2){
		descomprimir(archivos[i2]);
	}






// Funcion 1
	int cantidad = 0;
	char file1[] = "string.txt";
	char **strings = cargarData1(file1,&cantidad);
	pCML(strings, cantidad);
	

	
	free((void *)strings);
	free((void *)archivos);
	return 0;
}