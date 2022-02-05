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
    FILE *f2;
    int qt, c;
    Nascimento n;

    f = fopen("sinasc-sp-2018.dat","rb");
    f2 = fopen("sinasc-sp-meninasSantos-2018.dat","wb");
    
    qt = fread(&n,sizeof(Nascimento),1,f);
    while(qt>0){
        
        if (strncmp(n.CODMUNNASC,"354850",6)==0 && strncmp(n.SEXO,"2",1)==0){
            c++;
            fwrite(&n,sizeof(Nascimento),1,f2);
        }
        qt = fread(&n,sizeof(Nascimento),1,f);
    }
    printf("Nasceram %d meninas em Santos em 2018.\n", c);
    fclose(f);
    fclose(f2);
    return 0;
}