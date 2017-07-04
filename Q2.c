#include <stdio.h>
#include <stdlib.h>

int main(){
int cont=0;
char a, arquivo[100];
FILE *handler=NULL;
	scanf("%[^\n]s", arquivo);
	handler = fopen(arquivo, "r");
	if (handler==NULL){
		printf("Arquivo Inexistente");
		return 0;
	}

	a=fgetc(handler);
    if (a!=EOF) cont++;
	while(a!=EOF){
		a=fgetc(handler);
		if (a=='\n') cont++;
	}
	fclose(handler);
	printf("%d", cont);
return 0;
}
