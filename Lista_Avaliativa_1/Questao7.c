#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _NascimentosSp Nascimento;

struct _NascimentosSp
{
	char CODMUNNASC[6];
	char CODESTAB[7];
	char CODMUNRES[6];
	char DTNASC[8];
	char SEMAGESTAC[2];
	char SEXO[1];
	char PESO[4]; 
    char DTNASCMAE[8];
};
int compara(const void *n1, const void *n2)
{
	return strncmp(((Nascimento*)n1)->CODESTAB,((Nascimento*)n2)->CODESTAB,7);
}
int main(int argc, char**argv)
{
	FILE *f;
	Nascimento *n;
	long posicao, qtd;

	f = fopen("sinasc-sp-2018.dat","rb");
	fseek(f,0,SEEK_END);
	posicao = ftell(f);
	qtd = posicao/sizeof(Nascimento);
	n = (Nascimento*) malloc(posicao);
	if(n == NULL) {
		printf("Erro: Nao consegui alocar a memoria\n");
		fclose(f);
		return -1;
	}
	rewind(f); 
	if(fread(n,sizeof(Nascimento),qtd,f) == qtd) {
		printf("Lido = OK\n");
	}
	fclose(f);
	qsort(n,qtd,sizeof(Nascimento),compara);
	printf("Ordenado = OK\n");
	f = fopen("sinasc-sp-2018-ordenado.dat","wb");
	fwrite(n,sizeof(Nascimento),qtd,f);
	fclose(f);
	printf("Escrito = OK\n");
	free(n);

	return 0;
}