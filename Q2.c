#include <stdio.h>
#include <stdlib.h>

int main(){
int cont=0;
char a;
FILE *handler;
	handler = fopen("Arq_Q1.txt", "r");
	if (handler==NULL) exit(1);

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
