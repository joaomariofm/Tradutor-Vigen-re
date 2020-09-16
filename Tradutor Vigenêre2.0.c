#include <stdio.h>
#include <string.h>

int main(){

    char frase[101];
    char palavra_chave[20];
    char acao;
    char alf[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    printf("Digite uma frase\n");
    fgets(frase, 101 , stdin);

    printf("Digite 'c' para codificar ou 'd' para decodificar\n");
    scanf("%c", & acao);

    printf("Digite uma palavra chave\n");
    scanf("%s", &palavra_chave[20]);

        if(acao == 'c'){
            //codificar
            int nchave = strlen(palavra_chave);
            int nfrase = strlen(frase);
            int localizador;
            int posicao =0;
            int c = 0;
            printf("A palavra codificada e: ");

            for(localizador = 0; localizador <= nfrase -2; localizador++){

                if(frase[localizador] == ' '){
                    posicao++;
                    localizador++;
                    frase[localizador] = frase[posicao];
                    printf(" ");
                    }

                char letra = frase[localizador];
                char chave = palavra_chave[c];

                int varrealf;
                int varrealf2;

                for(varrealf = 0; varrealf <= 26; varrealf++){
                    char lalf = alf[varrealf];
                    if(lalf == letra){
                        break;
                    }
                }

                for(varrealf2 = 0; varrealf2 <= 26; varrealf2++){
                    char lalf = alf[varrealf2];
                    if(lalf == chave){
                        break;
                    }
                }
    int numero1 = varrealf;
    int numero2 = varrealf2;
    int xy = numero1 + numero2;

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
        }
        if(acao == 'd'){
            //decodificar
            int nchave = strlen(palavra_chave);
            int nfrase = strlen(frase);
            int localizador;
            int posicao =0;
            int c = 0;
            printf("A palavra decodificada e:\n");

            for(localizador = 0; localizador <= nfrase -2; localizador++){

                if(frase[localizador] == ' '){
                    posicao++;
                    localizador++;
                    frase[localizador] = frase[posicao];
                    printf(" ");
                    }

                char letra = frase[localizador];
                char chave = palavra_chave[c];

                int varrealf;
                int varrealf2;

                for(varrealf = 0; varrealf <= 26; varrealf++){
                    char lalf = alf[varrealf];
                    if(lalf == letra){
                        break;
                    }
                }

                for(varrealf2 = 0; varrealf2 <= 26; varrealf2++){
                    char lalf = alf[varrealf2];
                    if(lalf == chave){
                        break;
                    }
                }
    int numero1 = varrealf;
    int numerochave = varrealf2;

if(numero1< numerochave){
    int w =(numero1 + 26) - numerochave;
    char novaletra = alf[w];
    printf("%c", novaletra);
}else{
    int w = numero1 - numerochave;
    char novaletra = alf[w];
    printf("%c", novaletra);
}
    posicao++;
    c++;

if(c >= nchave){
    c = 0;
}
            }
        }
        if( acao != 'c' && acao != 'd' ){
            printf("ERRO");
        }
    }
