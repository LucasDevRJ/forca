#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "principal.h"
#include <ctype.h>

//variáveis globais
char frutas[TAMANHO];
char chutes[26];
int chutes_dados = 0;

void introducao() {
	printf("******************\n");
    printf("* Jogo de Forca das Frutas *\n");
    printf("******************\n\n");
}

void desenha_forca() {

	int erros = chutes_errados();

	printf("  _______       \n");
	printf(" |/      |      \n");
	printf(" |      %c%c%c  \n", (erros>=1?'(':' '), 
	    (erros>=1?'_':' '), (erros>=1?')':' '));
	printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), 
	    (erros>=2?'|':' '), (erros>=3?'/': ' '));
	printf(" |       %c     \n", (erros>=2?'|':' '));
	printf(" |      %c %c   \n", (erros>=4?'/':' '), 
	    (erros>=4?'\\':' '));
	printf(" |              \n");
	printf("_|___           \n");
	printf("\n\n");


	for (int i = 0; i < strlen(frutas); i++) {
		int achou = ja_chutou(frutas[i]);	
		if (achou) {
			printf("%c ", frutas[i]);
		} else {
			printf("_ ");
		}
	}
	printf("\n");
}

void chuta() {
	char chute;
	printf("Digite uma letra: ");
	scanf(" %c", &chute);

	chute = toupper(chute);

	chutes[chutes_dados] = chute;
	chutes_dados++;
}

void escolhe_palavra_secreta() {
	FILE* f;

	f = fopen("palavras.txt", "r");

	if (f == 0) {
		printf("Erro ao tentar ler o arquivo.");
		exit(1);
	}

	int quantidade_palavras;
	fscanf(f, "%d", &quantidade_palavras);

	srand(time(0));
	int randomico = rand() % quantidade_palavras;

	for (int i = 0; i <= randomico; i++) {
		fscanf(f, "%s", frutas);
	}

	fclose(f);
}

int acertou() {
	for (int i = 0; i < strlen(frutas); i++) {
		if (!ja_chutou(frutas[i])) {
			return 0;
		}
	}
	return 1;
}

int chutes_errados() {
	int erros = 0;
	for (int i = 0; i < chutes_dados; i++) {
		
		int existe = 0;
		for (int j = 0; j < strlen(frutas); j++) {
			if (chutes[i] == frutas[j]) {
				existe = 1;
				break;
			}
		}

		if (!existe) {
			erros++;
		}
	}
	return erros;
}

int enforcou() {
	
	return chutes_errados() >= 5;
}

int ja_chutou(char letra) {
	int achou = 0;
	for (int j = 0; j < chutes_dados; j++) {
		if (chutes[j] == letra) {
			achou = 1;
			break;
		}
	}		
	return achou;
}

int main() {
	escolhe_palavra_secreta();
	introducao();

	do {
		desenha_forca();
		chuta();

	} while (!acertou() && !enforcou());

	if (acertou()) {
		printf("Parabens! Voce acertou, a fruta era %s\n", frutas);

		printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

	} else {
		printf("****************************\n");
		printf("     GAME OVER\n");
		printf("A fruta era %s\n", frutas);
		printf("    _______________         \n");
	    printf("   /               \\       \n"); 
	    printf("  /                 \\      \n");
	    printf("//                   \\/\\  \n");
	    printf("\\|   XXXX     XXXX   | /   \n");
	    printf(" |   XXXX     XXXX   |/     \n");
	    printf(" |   XXX       XXX   |      \n");
	    printf(" |                   |      \n");
	    printf(" \\__      XXX      __/     \n");
	    printf("   |\\     XXX     /|       \n");
	    printf("   | |           | |        \n");
	    printf("   | I I I I I I I |        \n");
	    printf("   |  I I I I I I  |        \n");
	    printf("   \\_             _/       \n");
	    printf("     \\_         _/         \n");
	    printf("       \\_______/           \n");
	    printf("****************************\n");
	}
} 