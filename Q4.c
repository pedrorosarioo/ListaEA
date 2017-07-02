#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
int cont;
char arquivo[40], palavra[10], busca[100];
FILE *handler=NULL;	
	
	scanf("%[^\n]s", arquivo);
	scanf("%s", palavra);
	
	handler=fopen(arquivo, "r");
	if (handler==NULL){
		printf("Arquivo Inexistente");
		return 0;
	}
	
	while(!feof(handler)){
		fscanf(handler, "%s", busca); 
		if (strcmp(busca, palavra)==0){
			cont++;
		}
	}
	printf("%d", cont);
return 0;
}
			