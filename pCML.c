#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int cmpfunc(const void *a, const void *b){
	const char*pa = *(const char**)a;
	const char*pb = *(const char**)b;
	return strcmp(pa,pb); 
}
int pCML (char **S, int n){
	// printf("%d\n", n);
	int i=0;
	int size;
	qsort(S,n,sizeof(char*), cmpfunc);
	// printf("AL MENOS ENTRO\n");

	

	int *cantidadPalabras = (int *)calloc(27, sizeof(int));
	char *anterior = (char *) malloc(sizeof(char));

	char posletra = -1;
	char *primeraletra = (char *) malloc(sizeof(char));
	*anterior = 'z';





	// Contar cuantas tenemos que empiecen con cada letra del abecedario
	for(i = 0;i <= n; i++){
		*primeraletra = *S[i];
		if( strcmp(primeraletra,anterior) != 0){
			// printf("Letras diferentes %s %s \n",anterior,primeraletra);
			*anterior = *S[i];
			posletra = (int)*primeraletra-97;
			//printf("%d",posletra);
			cantidadPalabras[posletra]++;
		}
		else{
			// printf("%d\n", posletra);
			cantidadPalabras[posletra]++;
			// printf("Letras iguales, sumamos %d \n",cantidadPalabras[posletra]);
		}
	}


	free((void *)primeraletra);
	free((void *)anterior);



	

	i = 0;
	int acumulado = 0;
	int *nPrefijo = (int *) calloc(27, sizeof(int)); 
	int *nPrefijoTemp = (int *) calloc(27, sizeof(int)); 


	int j = 0;
	int algunsimilar = 0;
	int indice = 0; // Letra ordenada en la que voy
	int i2 = 0;
	int indiceanterior = -1;
	for(i=0; i < n;++i){
		// printf("--HOLA-- %d\n", i);
		// Revisar que siga siendo la misma letra
		// S[i] -> palabra
		// printf("%c\n", *S[i]);
		if((int)*S[i]-97 != indice){
			indice = (int)*S[i]-97;
		}
		// printf("Iterando %d indice %d\n", i, indice);
		// if(i >= acumulado){
		nPrefijoTemp[indice]+=1;

		// printf(" Palabra es la que inicia con la letra %d\n",indice);
		// printf(" Palabras que tienen la letra %d es %d\n",indice,cantidadPalabras[indice]);
		for(j = 1; j <= 200; j++){
			algunsimilar = 0;
			// Verificar que tenga la letra
			// printf("%s\n", S[i+1]);
			if((int)strlen(S[i]) > j && (int)strlen(S[i+1]) > j){
				// printf("entro\n");
				// printf("  Itero letras %d\n",j);
				// printf("   La palabra tiene mas letras que %d\n",j);
				// Si es el primero
				if(indice != indiceanterior){
					// printf("%d es el primero\n", j);
					if(S[i][j] !=  S[i+1][j]){
						// printf("%d es diferente a el siguiente \n", j);
						S[i] = "0";
					}
					else{
						// printf("%d es igual a el siguiente \n", j);
						algunsimilar = 1;
					}
				}
				// Si es el último

				else if((int)*S[i] != (int)*S[i+1]){
					// printf("%d es el último\n", j);
					if(S[i-1][j] != S[i][j]){
						// printf("%d es diferente a el anterior \n", j);
						S[i] = "0";
					}
					else{
						// printf("%d es igual a el anterior \n", j);
						algunsimilar = 1;
					}
				}
				else{
					// printf("%d es intermedio\n", j);
					if( (S[i][j] !=  S[i+1][j]) && (S[i-1][j] != S[i][j]) ){
						// printf("%d esta entre medio y es diferente\n", j);
						S[i] = "0";
					}
					else{
						// printf("%d esta entre medio y es similar\n", j);
						algunsimilar = 1;
					}
				} 
			}
			else{
				// printf("no entro\n");
				break;
			}
			if(algunsimilar == 1){
				// printf("la letra %d tiene similar en la posicion %d\n",indice, j);
				nPrefijoTemp[indice]+=1;
				if(nPrefijoTemp[indice] >= nPrefijo[indice]){
					nPrefijo[indice] = nPrefijoTemp[indice];
				}
				
				// printf("El acumulado de %d va en %d \n",indice, nPrefijo[indice]);
			}
			indiceanterior = indice;
		}
		nPrefijoTemp[indice] = 0;
		acumulado+= cantidadPalabras[indice];
		// for (i2 = 0; i2 < 27; ++i2){
		// printf("%d ", nPrefijo[i2]);
		// }
		// printf("\n");
		// }
	}


	int max = 0;
	for (i = 0; i < 27; ++i)
	{
		// printf("%d ", nPrefijo[i]);
		if(nPrefijo[i] > max){
			max = nPrefijo[i];
		}
	}
	printf("\n %d \n", max);
	return max;
}
