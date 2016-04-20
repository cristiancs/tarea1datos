#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int cmpfunc(const void *a, const void *b){
	const char*pa = *(const char**)a;
	const char*pb = *(const char**)b;
	return strcmp(pa,pb); 
}
int pCML (char **S, int n){
	char abc[27];
	printf("%d", (int)sizeof(abc));
	//abc={"a","b","c","d","e","f","g","h","i","j","q","l","m","n","ñ","o","p","q","r","s","t","u","v","w","x","y","z"};
	int i=0;
	int size;
	qsort(S,n,sizeof(char*), cmpfunc);
	//for(i=0; i<n ; i++){
	//	printf("%s",S[i]);
	//}
	/*char x[]="char";
	printf("%d\n", (int)*x);
	int l;*/
	//for(i=0; i<n ; i++){
		
	//}
	return 0;
}
