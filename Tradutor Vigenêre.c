#include <stdio.h>
#include <string.h>

int main(){
    char frase[100];
    char palavra_chave[20];
    char acao;
    int i;

    printf("Digite uma frase\n");
    for(i = 0 ; ; i++){
        scanf("%c", frase[i]);
        if(frase[i] == '\n'){
            frase[i] = ' ';
            break;
        }
    }

    printf("Digite 'c' para codificar ou 'd' para decodificar\n");
    scanf("%c", & acao);

    printf("Digite uma palavra chave de ate 10 caracteres\n");
    scanf("%s", & palavra_chave);

    int nchave = strlen(palavra_chave);
    int caracteres = strlen(frase);

    char alf[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    if( acao == 'c' ){
        int localizador;
        int posicao = 0;
        int c = 0;
        printf("A frase criptografada e:");

         for(localizador = 0; localizador <= caracteres-1 ; localizador++){

            if(frase[localizador] == ' '){
                posicao++;
                localizador++;
                frase[localizador] = frase[posicao];
                printf(" ");

            }

            char letra = frase[localizador];
            char chave = palavra_chave[c];

                int varreralf;
                int varreralf2;
                for(varreralf = 0; varreralf <= 26 ; varreralf++){
                    char lalf = alf[varreralf];
                    if(lalf == letra){
                        break;
                    }
                }
                for(varreralf2 = 0; varreralf2 <= 26 ; varreralf2++){
                    char lalf = alf[varreralf2];
                    if(lalf == chave){
                        break;
                    }
                }

            int numerol = varreralf;
            int numeroc = varreralf2;
            int xy = numerol + numeroc;
                if(xy >= 26){
                 int w = xy - 26;
                 char novaletra = alf[w];
                 printf("%c", novaletra);
                }else{
                 int w = xy;
                 char novaletra = alf[w];
                 printf("%c", novaletra);
                }

            posicao++;
            c++;


             if(c >= nchave){
            c = 0;
           }

         }


    }if(acao == 'd'){

        printf("decodificar");

    }
    if( acao != 'c' && acao != 'd'){
        printf("ERRO");
    }

}
