#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct User{
	char nome[100];
	int tel;
}User;

int main(){
FILE *handler;
int i=0, j, id, k=0;
User v[100], aux[100], menor, maior;
	
	handler=fopen("Arq_Q5.bin", "rb+");
	if (handler==NULL){
		printf("Erro ao abrir o arquivo\n");
		return 0;
	}
	
	while(!feof(handler)){
		if (fread(&v[i], sizeof(User), 1, handler)==1){ 
			i++;
		}
	}
	
	for(k=0; k<i; k++){	
		for (j=0; j<i; j++){
			if (j==0){
				strcpy(menor.nome, v[j].nome);
				menor.tel=v[j].tel;
			}else{
				if (strcmp(menor.nome, v[j].nome)>0){
					strcpy(menor.nome, v[j].nome);
					menor.tel=v[j].tel;
					id=j;
				}
			}
		}
		strcpy(v[id].nome, "ZZZZZZZZZZZ");
		strcpy(aux[k].nome,menor.nome);
		aux[k].tel=menor.tel;
	}
	fseek(handler, 0, SEEK_SET);
	fwrite(aux, sizeof(User), i, handler);
	
	
	fclose(handler);
	return 0;
}		