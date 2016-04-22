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
		printf("[ERROR] cargarData1: Archivo no existe\n");
		exit(0);
	}
	// http://stackoverflow.com/questions/19068643/dynamic-memory-allocation-for-pointer-arrays 
	char **strings;
	//Pedimos mucha memoria para optimizar el tiempo
	strings = malloc( sizeof(char) * MEMORIA_MAXIMA);
	int nuevotamanio = 0;
	char* palabra;
	while (!feof(fp))
	{
		
		palabra = (char *) malloc(201*sizeof(char));
		if( fgets (palabra, 201, fp)!=NULL ) 
		{
			size_t len = strlen(palabra);
			strings = realloc(strings, nuevotamanio+201*sizeof(char));
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
	free((void *)palabra);
	return strings;
}


char** cargarData2(char *nombre, int *i){
	FILE *fp;
	fp = fopen(nombre, "r");
	if(fp == NULL){
		printf("[ERROR] cargarData2: Archivo no existe\n");
		exit(0);
	}
	// http://stackoverflow.com/questions/19068643/dynamic-memory-allocation-for-pointer-arrays 
	char **strings;
	strings = malloc( sizeof(char) * 1);
	int nuevotamanio = 0;
	char* palabra;
	while (!feof(fp))
	{
		
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
	free((void *)palabra);
	strings = realloc(strings, nuevotamanio);
	fclose(fp);
	return strings;
}



int main(){

// Función 2
	int cantidadArchivos = 0;
	char file2[] = "input-strings.txt";
	char **archivos = cargarData2(file2,&cantidadArchivos);

	//Llamar a descomprimir y guardar en otro archivo
	FILE *fp;
	fp = fopen("strings-descomprimidos.txt", "w");
	if(fp == NULL){
		printf("[ERROR] main: No se pudo abrir el archivo strings-descomprimidos.txt \n");
		exit(0);
	}
	int largo;
	int i2;
	char *returnString;
	for (i2 = 0; i2 < cantidadArchivos; ++i2){
		returnString = descomprimir(archivos[i2]);
		printf("[INFO] main: Guardando string\n");
		fwrite(returnString, strlen(returnString) * sizeof(char), 1, fp);
		if(i2 != cantidadArchivos-1){
			fwrite("\n", sizeof(char), 1, fp);
		}
		if(strcmp(returnString,"El archivo no existe") != 0){
			free((void *) returnString);
		}
		
	}
	fclose(fp);






// Funcion 1
	int cantidad = 0;
	char file1[] = "string.txt";
	char **strings = cargarData1(file1,&cantidad);
	int i = 0;

	pCML(strings, cantidad);
	

	
	free((void *)strings);
	free((void *)archivos);
	return 0;
}