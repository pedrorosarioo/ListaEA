#include <stdio.h>
#include <stdlib.h>

typedef struct User{
	char nome[100];
	int tel;
}User;

int main(){
FILE *handler;
int i=0;
User v[100];
	
	handler=fopen("Arq_Q5.bin", "ab");
	if (handler==NULL){
		printf("Erro ao abrir o arquivo\n");
		return 0;
	}
	
	scanf("%[^\n]s", v[i].nome);
	scanf("%d", &v[i].tel);
		while(v[i].tel!=0){
			//fwrite(&v[i], sizeof(User), 1, handler);
			i++;
			scanf(" %[^\n]s", v[i].nome);
			scanf("%d", &v[i].tel);
		}
	fwrite(v, sizeof(User), i, handler);
	
	fclose(handler);
	
	return 0;
}		
			