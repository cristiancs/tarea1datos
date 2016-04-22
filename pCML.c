#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int cmpfunc(const void *a, const void *b){
	const char*pa = *(const char**)a;
	const char*pb = *(const char**)b;
	return strcmp(pa,pb); 
}
int pCML (char **S, int n){
	//n+=1;
	int i=0;
	int size;
	qsort(S,n,sizeof(char*), cmpfunc);

	int *cantidadPalabras = calloc(27, sizeof(int));
	char *anterior = malloc(sizeof(char));
	char posletra = -1;
	char *primeraletra = malloc(sizeof(char));
	*anterior = 'z';


	// Contar cuantas tenemos que empiecen con cada letra del abecedario
	while(i <= n){
		*primeraletra = *S[i];
		if( strcmp(primeraletra,anterior) != 0){
			// printf("Letras diferentes %s %s \n",anterior,primeraletra);
			*anterior = *S[i];
			posletra = (int)*primeraletra-97;
			cantidadPalabras[posletra]++;
		}
		else{
			// printf("%d\n", posletra);
			cantidadPalabras[posletra]++;
			// printf("Letras iguales, sumamos %d \n",cantidadPalabras[posletra]);
		}
		i++;
	}
	
	free((void *)primeraletra);
	free((void *)anterior);



	for(i=0; i < 27; i++){
		printf("%d ",cantidadPalabras[i]);
	}



	i = 0;
	int acumulado = 0;
	int *nPrefijo = calloc(27, sizeof(int)); 
	int j;
	int algunsimilar = 0;
	int indice = 0; // Letra ordenada en la que voy
	while(i <= n){
		// Revisar que siga siendo la misma letra
		// S[i] -> palabra
		if((int)*S[i]-97 != indice){
			indice = (int)*S[i]-97;
		}
		printf("%d\n", indice);
		if(i >= acumulado){
			nPrefijo[indice]+=1;
			printf(" Palabra es la que inicia con la letra %d\n",indice);
			printf(" Palabras que tienen la letra %d es %d\n",indice,cantidadPalabras[indice]);
			for(j = 1; j <= 200; j++){
				algunsimilar = 0;
				// Verificar que tenga la letra
				// Si es el último
				
				if(i-1 == n){
					printf("%d es el último\n", j);
					if(S[i-1][j] != S[i][j]){
						printf("%d es diferente a el anterior \n", j);
						S[i] = "0\0";
					}
					else{
						printf("%d es igual a el anterior \n", j);
						algunsimilar = 1;
					}
				}

				else if(strlen(S[i]) > j && strlen(S[i+1]) > j){
					printf("  Itero letras %d\n",j);
					printf("   La palabra tiene mas letras que %d\n",j);
					// Si es el primero
					if(i == 0){
						printf("%d es el primero\n", j);
						if(S[i][j] !=  S[i+1][j]){
							printf("%d es diferente a el siguiente \n", j);
							S[i] = "0\0";
						}
						else{
							printf("%d es igual a el siguiente \n", j);
							algunsimilar = 1;
						}
					}
					

					// Los demas
					else if( (S[i][j] !=  S[i+1][j]) && (S[i-1][j] != S[i][j]) ){
						printf("%d esta entre medio y es diferente\n", j);
						S[i] = "0\0";
					}
					else{
						printf("%d esta entre medio y es similar\n", j);
						algunsimilar = 1;
					}
					if(algunsimilar == 1){
						printf("la letra %d tiene similar en la posicion %d\n",indice, j);
						nPrefijo[indice]+=1;
						printf("El acumulado de %d va en %d \n",indice, nPrefijo[indice]);
					}
				}
				
			}
			acumulado+= cantidadPalabras[indice];
		}
		i+=1;
	}


	int max = 0;
	for (i = 0; i < 27; ++i)
	{
		printf("%d ", nPrefijo[i]);
		if(nPrefijo[i] > max){
			max = nPrefijo[i];
		}
	}
	printf("\n %d \n", max);
	return max;
}
