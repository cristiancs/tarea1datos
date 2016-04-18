#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Esta función solo se utiliza para crear el binario de prueba

int main(){
	unsigned int l1,l2,l3,l4;
	l1 = 1;
	l2 = 2;
	l3 = 3;
	l4 = 4;
	unsigned char c1[2] = "a";
	unsigned char c2[2] = "b";
	unsigned char c3[2] = "c";
	unsigned char c4[2] = "d";

	int constante = 4;
	FILE *fp;
	fp = fopen("binario.bin","w");
	fwrite(&constante, sizeof(int), 1, fp); //cantidad

	// repeticiones
	fwrite(&l1, sizeof(unsigned int), 1, fp);
	fwrite(&l2, sizeof(unsigned int), 1, fp);
	fwrite(&l3, sizeof(unsigned int), 1, fp);
	fwrite(&l4, sizeof(unsigned int), 1, fp);

	// letra
	fwrite(&c1, sizeof(unsigned char), 1, fp);
	fwrite(&c2, sizeof(unsigned char), 1, fp);
	fwrite(&c3, sizeof(unsigned char), 1, fp);
	fwrite(&c4, sizeof(unsigned char), 1, fp);


	fclose(fp);
	printf("Archivo binario creado correctamente\n");
	return 0;

}