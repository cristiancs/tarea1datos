#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Esta función solo se utiliza para crear el binario de prueba

int main(){
	unsigned int l1,l2,l3,l4;
	l1 = 9;
	l2 = 8;
	l3 = 7;
	l4 = 6;
	unsigned char c1[2] = "z";
	unsigned char c2[2] = "x";
	unsigned char c3[2] = "y";
	unsigned char c4[2] = "h";

	int constante = 4;
	FILE *fp;
	fp = fopen("binario2.bin","w");
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