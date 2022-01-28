#include <stdio.h>
#include <string.h>

typedef struct _Endereco Endereco;

struct _Endereco
{
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2]; 
};

int main(int argc, char**argv)
{
	FILE *f;
	Endereco e;
	int qt;
    int c=0;
    char cepprocurado [8];
    long tamanhoArquivo, posicao, primeiro, ultimo, meio;
    strncpy(cepprocurado,argv[1],8);

    f = fopen("cep_ordenado.dat","rb");
    fseek(f,0,SEEK_END);
	tamanhoArquivo = ftell(f);
	rewind(f); 
    
    printf("Tamanho do Arquivo: %ld\n", tamanhoArquivo);
	printf("Tamanho do Registro: %ld\n", sizeof(Endereco));
	printf("Tamanho do Arquivo em Registros: %ld\n", tamanhoArquivo/sizeof(Endereco));
	primeiro = 0;
	ultimo = (tamanhoArquivo/sizeof(Endereco))-1;
	meio = (primeiro+ultimo)/2;

    while (primeiro <= ultimo)
{
    c++;
    meio = (primeiro + ultimo) / 2;
    fseek (f,(meio*sizeof(Endereco)), SEEK_SET); 
    qt = fread(&e,sizeof(Endereco),1,f);
    if (strncmp(e.cep, cepprocurado, 8) == 0)
    {
        printf("achou!\n");
        printf("%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n",e.logradouro,e.bairro,e.cidade,e.uf,e.sigla,e.cep);
        break;
    }
        else
        {
            if (strncmp(cepprocurado, e.cep, 8) < 0)
            {
                ultimo = meio-1;
            }

            else
            {
                primeiro = meio+1;
            }
        }     
}
    fclose(f);
    printf("Total Lido: %d\n", c);
    return 0;
}