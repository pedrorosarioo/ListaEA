#include <stdio.h>
#include <stdlib.h>

int main(){
  FILE *handler=NULL;
  char a, arquivo[100];
  int i, letras[58];

  scanf("%[^\n]s", arquivo);
  handler = fopen(arquivo, "r");
  if (handler==NULL){
    printf("Erro ao abrir o arquivo");
    return 0;
  }
  
  for(i=0; i<58; i++){
    letras[i]=0;
  }
  
  do{
    a=fgetc(handler);
    letras[a-'A']++;
  }while(a!=EOF);
  
  for (i=0; i<58; i++){
    if ((i>31)||(i<26)) printf("Letra %c: %d\n", ('A'+i), letras[i]);
  }
  
  fclose(handler);
  return 0;
}
