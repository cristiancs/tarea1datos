#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*****
* char descomprimir
******
* Esta función descomprime un archivo y returna el resultado de esta descompresión
******
* Input:
* string nbreArchivo : Nombre del archivo a descomprimir
******
* Returns:
* string, string resultante de descomprimir el contenido del ficher
*****/
char * descomprimir (char *nbreArchivo){
	printf("[INFO] descomprimir: Procesando %s \n",nbreArchivo );
	// Leer archivo
	FILE *fp;
	fp = fopen(nbreArchivo, "r");

	if(fp == NULL){
		printf("[WARNING] descomprimir:El archivo %s no existe\n", nbreArchivo);
		return "El archivo no existe";
	}
	int cantidad = 0;
	fread(&cantidad,sizeof(int),1,fp);

	int Repeticiones[cantidad];
	char Letras[cantidad];
	
	fread(&Repeticiones,sizeof(unsigned int),cantidad,fp);
	fread(&Letras,sizeof(unsigned char),cantidad,fp);

	int i, MemoriaTotal = 0;
	// Calcular memoria que necesitaremos
	for(i = 0; i < cantidad; ++i){
		MemoriaTotal +=Repeticiones[i];
	}

	// Pedir memoria

	char *salida = (char *) malloc(sizeof(unsigned char) * MemoriaTotal + sizeof(unsigned char));
	int veces;
	int posicion = 0;
	for(i = 0; i < cantidad; ++i){
		// Escribir cada letra las veces necesarias
		for ( veces = 0; veces < Repeticiones[i]; ++veces){

			salida[posicion] = Letras[i];
			
			posicion++;
		}
		
	}
	salida[posicion] = '\0';
	printf("[INFO] descomprimir: Resultado es %s\n", salida);

	fclose(fp);

	return salida;
}