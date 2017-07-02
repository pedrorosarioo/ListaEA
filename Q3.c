#include <stdio.h>
#include <stdlib.h>

int main(){
int cont=0;
char a;
FILE *handler, *handler2, *handler3;
	handler = fopen("Arq_Q1.txt", "r");
	handler2 = fopen("Complemento_Q3.txt", "r");
	handler3 = fopen("Arq_Q3.txt", "a");
	
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
return 0;
}