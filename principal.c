#include <stdio.h>
#include <string.h>

void introducao() {
	printf("******************\n");
    printf("* Jogo de Forca *\n");
    printf("******************\n\n");
}

void desenha_forca(char palavras_secretas[20], char chutes[26], int tentativas) {
	for (int i = 0; i < strlen(palavras_secretas); i++) {
		int achou = ja_chutou(palavras_secretas[i], chutes, tentativas);	
		if (achou) {
			printf("%c ", palavras_secretas[i]);
		} else {
			printf("_ ");
		}
	}
	printf("\n");
}

void chuta(char chutes[26], int* tentativas) {
	char chute;
	scanf(" %c", &chute);

	chutes[(*tentativas)] = chute;
	(*tentativas)++;
}

int ja_chutou(char letra, char chutes[26], int tentativas) {
	int achou = 0;
		for (int j = 0; j < tentativas; j++) {
			if (chutes[j] == letra) {
				achou = 1;
			break;
		}
	}
	return achou;
}

void escolhe_palavra_secreta(char palavras_secretas[20]) {
	sprintf(palavras_secretas, "MELANCIA");
}

int main() {
	char palavras_secretas[20];
	int acertou = 0;
	int enforcou = 0;

	char chutes[26];
	int tentativas = 0;

	escolhe_palavra_secreta(palavras_secretas);
	introducao();

	do {
		desenha_forca(palavras_secretas, chutes, tentativas);
		chuta(chutes, &tentativas);

	} while (!acertou && !enforcou);
} 