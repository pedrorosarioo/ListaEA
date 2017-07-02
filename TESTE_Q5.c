#include <stdio.h>
#include <stdlib.h>

typedef struct User{
	char nome[100];
	int tel;
}User;

int main(){
FILE *handler;
int i=0;
User r;
	
	handler=fopen("Arq_Q5.bin", "ab+");
	if (handler==NULL){
		printf("Erro ao abrir o arquivo\n");
		return 0;
	}
	
	while(!feof(handler)){
		if (fread(&r, sizeof(User), 1, handler)==1){ 
			printf("%s %d\n", r.nome, r.tel);
		}
	}
	
	fclose(handler);
	return 0;
}		