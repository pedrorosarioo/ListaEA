#include <stdio.h>
#include <stdlib.h>

int main(){
char a;
FILE *handler;
	handler = fopen("Arq_Q1.txt", "a+");
	if (handler==NULL) exit(1);

	scanf("%c", &a);
	while(a!='0'){
		fputc(a, handler);
		scanf("%c", &a);
	}
	fclose(handler);

	handler = fopen("Arq_Q1.txt", "r");
	if (handler==NULL) exit(1);
	a=fgetc(handler);
	while(a!=EOF){
		printf("%c", a);
		a=fgetc(handler);
	}
return 0;
}


