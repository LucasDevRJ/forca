#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "principal.h"

//variáveis globais
char palavras_secretas[50];
char chutes[26];
int chutes_dados = 0;

void introducao() {
	printf("******************\n");
    printf("* Jogo de Forca *\n");
    printf("******************\n\n");
}

void desenha_forca() {
	for (int i = 0; i < strlen(palavras_secretas); i++) {
		int achou = ja_chutou(palavras_secretas[i]);	
		if (achou) {
			printf("%c ", palavras_secretas[i]);
		} else {
			printf("_ ");
		}
	}
	printf("\n");
}

void chuta() {
	char chute;
	scanf(" %c", &chute);

	chutes[chutes_dados] = chute;
	chutes_dados++;
}

void escolhe_palavra_secreta() {
	FILE* f;

	f = fopen("palavras.txt", "r");

	int quantidade_palavras;
	fscanf(f, "%d", &quantidade_palavras);

	srand(time(0));
	int randomico = rand() % quantidade_palavras;

	for (int i = 0; i <= randomico; i++) {
		fscanf(f, "%s", palavras_secretas);
	}

	fclose(f);
}

int acertou() {
	for (int i = 0; i < strlen(palavras_secretas); i++) {
		if (!ja_chutou(palavras_secretas[i])) {
			return 0;
		}
	}
	return 1;
}

int enforcou() {
	int erros = 0;
	for (int i = 0; i < chutes_dados; i++) {
		
		int existe = 0;
		for (int j = 0; j < strlen(palavras_secretas); j++) {
			if (chutes[i] == palavras_secretas[j]) {
				existe = 1;
				break;
			}
		}

		if (!existe) {
			erros++;
		}
	}

	return erros >= 5;
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
} 