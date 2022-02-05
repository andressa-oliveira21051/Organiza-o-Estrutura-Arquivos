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
    int qt, c;
    Nascimento n;
    char aux [7];

    f = fopen("sinasc-sp-2018-ordenado.dat","rb");
    qt = fread(&n,sizeof(Nascimento),1,f);
    c=1;
    strncpy(aux, n.CODESTAB,7);

    while(qt>0){
     qt = fread(&n,sizeof(Nascimento),1,f);
     if (qt==0){
         break;
     }

     if(strncmp (n.CODESTAB,aux,7)==0){
         c++;
     }
     else{
         printf("Nasceram %d pessoas no estabelecimento %.7s no ano de 2018.\n",c,aux);
         strncpy(aux, n.CODESTAB,7);
         c=1;
     }   
     }
   printf("Nasceram %d pessoas no estabelecimento %.7s no ano de 2018.\n",c,aux);
   fclose(f);
   return 0;
}
    