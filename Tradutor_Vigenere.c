#include <stdio.h>

typedef struct {
	char frase[1000];
	char palavra_chave[20];
	int tamanho_da_frase;
	int tamanho_da_chave;
} OBJETO;

char alf[52] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int teste(OBJETO * objeto);

int mostra_resultado(OBJETO * objeto);

int recebefrase_e_chave(OBJETO * objeto);

int codifica(OBJETO * objeto);

int decodifica(OBJETO * objeto);

int main(void){
	OBJETO  objeto;
	OBJETO * ponteiro = &objeto;
	int i;
	char acao,aux;
	
	/*
		inicializaçao do tamanho da frase 
		e do tamanho da chave
	*/
	objeto.tamanho_da_frase = 0;
	objeto.tamanho_da_chave = 0;

	recebefrase_e_chave(ponteiro);

	/*
		acao que sera realizada
	*/
	for(;;){
		printf("Digite 'c' para codificar ou 'd' para decodificar\n");
		scanf("%c%c", &acao,&aux);

		if(acao == 'c'){
			codifica(ponteiro);
			break;
		}else if(acao == 'd'){
			decodifica(ponteiro);
			break;
		}else{
			printf("\nERRO - acao invalida\nDigite novamente\n\n");
		}
	}

	mostra_resultado(ponteiro);
}

int recebefrase_e_chave(OBJETO * objeto){

	printf("Digite uma frase:\n>> ");
	for(int i = 0 ; ; i++){
		scanf("%c", &objeto->frase[i]);
		if(objeto->frase[i] == '\n'){
			objeto->frase[i] = ' ';
			break;
		}

		objeto->tamanho_da_frase ++;
  }

	printf("Digite a palavra chave:\n>> ");
	for(int i = 0 ; ; i++){
		scanf("%c", &objeto->palavra_chave[i]);
		if(objeto->palavra_chave[i] == '\n'){
			objeto->palavra_chave[i] = ' ';
			break;
		}

		objeto->tamanho_da_chave++;
  }
}

int teste(OBJETO * objeto){
	int i;
	printf("A frase digitada foi:\n");
	for(i = 0 ; i<objeto->tamanho_da_frase ; i++){
		printf("%c", objeto->frase[i]);
	}
	printf("\n");
	printf("O tamanho da frase e de:\n");
	printf("%i\n", objeto->tamanho_da_frase);

	printf("A palavra chave digitada:\n");
	for(i = 0 ; i<objeto->tamanho_da_chave ; i++){
		printf("%c", objeto->palavra_chave[i]);
	}
	printf("\n");
	printf("O tamanho da palavra chave e de:\n");
	printf("%i\n", objeto->tamanho_da_chave);
}

int mostra_resultado(OBJETO * objeto){
	int i;
	printf("\nEsse e o resultado: ");
	for(i = 0 ; i<objeto->tamanho_da_frase ; i++){
		printf("%c", objeto->frase[i]);
	}
	printf("\n");
}

int codifica(OBJETO * objeto){
	int localizador_frase, localizador_chave = 0;
	int rep_numerica_frase = 0, rep_numerica_chave = 0, rep_numerica_cod;

	for(localizador_frase = 0 ; localizador_frase <= objeto->tamanho_da_frase-1 ; localizador_frase++){
		
		if(objeto->frase[localizador_frase] != ' '){
			/*
				-Primeiro é preciso transformar a letra da frase
				-em seu numero correspondente 
			*/

			//variaveis de controle 
			int frase_control = 0;
			int caractere_esp = 0;
			//


			int i;
			for(i = 0 ; i<=52 ; i++){
				if(objeto->frase[localizador_frase] == alf[i]){
					rep_numerica_frase = i;
					break;
				}
				if(i == 52){
					caractere_esp = 1;
				}
			}
		
			if(caractere_esp == 0){
				/*
				-Depois é preciso transformar a letra da chave
				-em uso em seu numero correspondente 
				*/

				int j;
				for(j = 0 ; j<=52 ; j++){
					if(objeto->palavra_chave[localizador_chave] == alf[j]){
						rep_numerica_chave = j;
						break;
					}
				}

				/*
					-Reajuste das letras maiusculas 
				*/

				if(rep_numerica_frase >25){
					rep_numerica_frase -= 26;
					frase_control = 1;
				}

				if(rep_numerica_chave > 25){
					rep_numerica_chave -= 26;
				}

				/*
					-Calculo da representaçao numerica da nova letra
				*/

				rep_numerica_cod = rep_numerica_frase + rep_numerica_chave;
				if(rep_numerica_cod >= 26){
					rep_numerica_cod -= 26;
				}

				/*
					-Reajuste para controle de letras maiusculas
				*/
			
				if(frase_control == 1){
					rep_numerica_cod += 26;
				}
			

				/*
					-Conversao da representaçao numerica da nova letra
					-para a letra real 
				*/

				objeto->frase[localizador_frase] = alf[rep_numerica_cod];
	
				/*
					-Reajuste do localizador da chave 
				*/
				localizador_chave++;
				if(localizador_chave == objeto->tamanho_da_chave){
					localizador_chave = 0;
				}
			}	
		}
	}
}

int decodifica(OBJETO * objeto){
	int localizador_frase, localizador_chave = 0;
	int rep_numerica_frase = 0, rep_numerica_chave = 0, rep_numerica_dcod;

	for(localizador_frase = 0 ; localizador_frase <= objeto->tamanho_da_frase-1 ; localizador_frase++){
		if(objeto->frase[localizador_frase] != ' '){
			/*
				-Primeiro é preciso transformar a letra em
				-sua representaçao numerica
			*/

			//variaveis de controle
			int frase_control = 0;
			int caractere_esp = 0;
			//

			int i;
			for(i = 0 ; i<=52 ; i++){
				if(objeto->frase[localizador_frase] == alf[i]){
					rep_numerica_frase = i;
					break;
				}
				if(i == 52){
					caractere_esp = 1;
				}
			}
			
			if(caractere_esp == 0){
				/*
					-Depois é preciso transformar a letra da chave
					-em uso em seu numero correspondente
				*/
				int j;
				for(j = 0 ; j<=52 ; j++){
					if(objeto->palavra_chave[localizador_chave] == alf[j]){
						rep_numerica_chave = j;
						break;
					}
				}
				/*
					-Reajuste das letras maiusculas
				*/

				if(rep_numerica_frase > 25){
					rep_numerica_frase -=26;
					frase_control = 1;
				}

				if(rep_numerica_chave > 25){
					rep_numerica_chave -= 26;
				}
			
				/*
					-Calculo da representaçao numerica da letra
					-que foi codificada
				*/

				if(rep_numerica_frase >= rep_numerica_chave){
					rep_numerica_dcod = rep_numerica_frase - rep_numerica_chave;
				}else{
					rep_numerica_dcod = rep_numerica_frase + 26 - rep_numerica_chave;
				}

				/*
					-Reajuste para controle das letras maiusculas
				*/

				if(frase_control == 1){
					rep_numerica_dcod += 26;
				}

				/*
					-Conversao da representaçao numerica da letra
					-na letra correspondente 
				*/

				objeto->frase[localizador_frase] = alf[rep_numerica_dcod];

				/*
					-Reajuste do localizador da chave 
				*/
				localizador_chave++;
				if(localizador_chave == objeto->tamanho_da_chave){
					localizador_chave = 0;
				}
			}
		}
	}
}
