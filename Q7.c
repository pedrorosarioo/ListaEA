#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Produto{
	char nome[100];
	int cod;
	int qtd;
}Produto;

typedef struct Acao{
	char ac[10]; //ENTRADA OU SAIDA
	char l_nome[100];
	int l_cod;
	int l_qtd;
}Acao;

void InsereProduto(FILE *handler){
FILE *historico;
int salto;
Produto r, p;
Acao log;

	historico = fopen("Log_Q7", "ab+");
	if (historico==NULL) exit(1);


	printf("Digite o nome do produto:\n");

	scanf(" %[^\n]s", p.nome);
	printf("\n");
	fread(&r, sizeof(Produto), 1, handler);
	while((!feof(handler))&&(strcmp(r.nome, p.nome))){
		fread(&r, sizeof(Produto), 1, handler);
	}
	if (feof(handler)){
        printf("Digite o código do produto:\n");
        scanf("%d", &p.cod);
        printf("Digite a quantidade do produto:\n");
        scanf("%d", &p.qtd);
        printf("\n");
		fwrite(&p, sizeof(Produto), 1, handler);
		fseek(handler, 0, SEEK_SET);
	}else{
	    printf("Este produto ja se encontra no estoque, digite a quantidade a acrescentar:\n");
        scanf("%d", &p.qtd);
        p.qtd=p.qtd+r.qtd;
        p.cod=r.cod;
		salto = -1;
		salto = salto*sizeof(Produto);
		fseek(handler, salto, SEEK_CUR);
		fwrite(&p, sizeof(Produto), 1, handler);
		fseek(handler, 0, SEEK_SET);
	}
	printf("PRODUTO INSERIDO!\n");

	strcpy(log.ac, "ENTRADA:");
	strcpy(log.l_nome, p.nome);
	log.l_cod=p.cod;
	log.l_qtd=p.qtd;

	fwrite(&log, sizeof(Acao), 1, historico);
	fclose(historico);
	printf("\n");
}


void RetiraProduto(FILE *handler){
FILE *historico;
Produto r;
int quant, salto;
char entrada[100];
Acao log;

	historico = fopen("Log_Q7", "ab+");
	if (historico==NULL) exit(1);

	printf("Digite o nome do produto:\n");
	scanf(" %[^\n]s", entrada);
	fread(&r, sizeof(Produto), 1, handler);
	while((!feof(handler))&&(strcmp(r.nome, entrada))){
		fread(&r, sizeof(Produto), 1, handler);
	}
	if (feof(handler)){
		printf("Produto não encontrado\n");
		printf("\n");
	}else{
		printf("Quantos deseja remover?\n");
		scanf("%d", &quant);
		if ((r.qtd-quant)<0){
			printf("Desculpe, nao temos essa quantidade de %s disponivel\n", r.nome);
			fseek(handler, 0, SEEK_SET);
		}else{
			r.qtd=r.qtd-quant;
			salto = -1;
			salto = salto*sizeof(Produto);
			fseek(handler, salto, SEEK_CUR);
			fwrite(&r, sizeof(Produto), 1, handler);
			fseek(handler, 0, SEEK_SET);
			printf("PRODUTO REMOVIDO \n");

			strcpy(log.ac, "SAIDA:");
			strcpy(log.l_nome, r.nome);
			log.l_cod=r.cod;
			log.l_qtd=quant;

			fwrite(&log, sizeof(Acao), 1, historico);
			printf("\n");
		}
	}
	fclose(historico);
}

void ProdutosEmFalta(FILE *handler){
FILE *historico;
Produto r;
//int quant;
//char entrada[100];
Acao log;

	historico = fopen("Log_Q7", "ab+");
	if (historico==NULL) exit(1);

	//fread(&r, sizeof(Produto), 1, handler);
	while((!feof(handler))){
		fread(&r, sizeof(Produto), 1, handler);
		if (r.qtd==0){
			printf("%s %d %d\n", r.nome, r.cod, r.qtd);
		}
	}

	strcpy(log.ac, "EM FALTA");
	strcpy(log.l_nome, "0");
	log.l_cod=0;
	log.l_qtd=0;
	fwrite(&log, sizeof(Acao), 1, historico);
	printf("\n");
	fclose(historico);
}
void MostraEstoque(FILE *handler){
Produto r;
    while(!feof(handler)){
		if(fread(&r, sizeof(Produto), 1, handler)==1){
            printf("%s %d %d\n", r.nome, r.cod, r.qtd);
		}
	}
	fseek(handler, 0, SEEK_SET);
	printf("\n");
}

void MostraHistorico(){
FILE *historico;
Acao log;
	historico = fopen("Log_Q7", "rb+");
	if (historico==NULL) exit(1);

	while(!feof(historico)){
		if(fread(&log, sizeof(Acao), 1, historico)==1){
            printf("%s %s %d %d\n", log.ac, log.l_nome, log.l_cod, log.l_qtd);
		}
	}
	printf("\n");
	fclose(historico);
}

int main(){
FILE *handler;
int escolha;

	handler = fopen("Arq_Q7.bin", "wb+");
	if (handler==NULL) exit(1);

	fseek(handler, 0, SEEK_SET);
	printf("1: Inserir produto\n2: Retirar produto\n3: Produtos em falta\n4: Mostrar estoque\n5: Mostra historico\n6: Sair\n");
	scanf("%d", &escolha);

	while(escolha!=6){
        if (escolha==1) InsereProduto(handler);
        else if (escolha==2) RetiraProduto(handler);
        else if (escolha==3) ProdutosEmFalta(handler);
        else if (escolha==4) MostraEstoque(handler);
        else if (escolha==5) MostraHistorico();
        printf("1: Inserir produto\n2: Retirar produto\n3: Produtos em falta\n4: Mostrar estoque\n5: Mostra historico\n6: Sair\n");
        scanf("%d", &escolha);
	}
	fclose(handler);
return 0;
}
