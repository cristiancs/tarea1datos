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
	printf(" %s \n",nbreArchivo );
	// Leer archivo
	FILE *fp;
	fp = fopen(nbreArchivo, "r");

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
	printf("%d\n", MemoriaTotal);

	// Pedir memoria

	// char *salida = malloc(sizeof(unsigned char) * MemoriaTotal + sizeof(unsigned char));
	// int veces = 0;
	// for(i = 0; i < cantidad; i++){
	// 	printf("%c\n", *salida);
	// 	// Escribir cada letra las veces necesarias
	// 	for ( veces = 0; i < Repeticiones[i]; ++veces){
	// 		salida[veces] = Letras[i];
	// 	}
	// }
	// salida[veces] = '\0';
	// printf("%c\n", *salida);

	fclose(fp);

	// TEMPORAL
	free((void *) salida);
	return "c";
}