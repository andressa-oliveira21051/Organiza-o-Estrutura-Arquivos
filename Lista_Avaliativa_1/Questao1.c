#include <stdio.h>
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

int main(int argc, char**argv)
{
	FILE *f;
    long tamanhoArquivo;

    f = fopen("sinasc-sp-2018.dat","rb");
    fseek(f,0,SEEK_END);
	tamanhoArquivo = ftell(f);
    rewind(f); 

	printf("tamanho do arquivo %ld\n", tamanhoArquivo);

    fclose(f);
    return 0;
}