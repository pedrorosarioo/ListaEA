#include <stdio.h>
#include <stdlib.h>

int main(){
int cont=0;
char a, arquivo[100], arquivo2[100], arquivo3[100];
FILE *handler, *handler2, *handler3;

	scanf("%[^\n]s", arquivo);
	handler = fopen(arquivo, "r");
	if (handler==NULL){
		printf("Arquivo Inexistente");
		return 0;
	}
	
	scanf(" %[^\n]s", arquivo2);
	handler2 = fopen(arquivo2, "r");
	if (handler==NULL){
		printf("Arquivo Inexistente");
		return 0;
	}
	
	scanf(" %[^\n]s", arquivo3);
	handler3 = fopen(arquivo3, "a");
	if (handler==NULL){
		printf("Arquivo Inexistente");
		return 0;
	}
	
	a=fgetc(handler);
	while(a!=EOF){
		fputc(a, handler3);
		a=fgetc(handler);
	}
	fclose(handler);
	
	a=fgetc(handler2);
	while(a!=EOF){
		fputc(a, handler3);
		a=fgetc(handler2);
	}
	fclose(handler2);
	fclose(handler3);
return 0;
}
