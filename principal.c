#include <stdio.h>
#include <string.h>

//variáveis globais
char palavras_secretas[20];
char chutes[26];
int tentativas = 0;

void introducao() {
	printf("******************\n");
    printf("* Jogo de Forca *\n");
    printf("******************\n\n");
}

int ja_chutou(char letra) {
	int achou = 0;
		for (int j = 0; j < tentativas; j++) {
			if (chutes[j] == letra) {
				achou = 1;
			break;
		}
	}
	return achou;
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

	chutes[tentativas] = chute;
	tentativas++;
}

void escolhe_palavra_secreta() {
	sprintf(palavras_secretas, "MELANCIA");
}

int main() {
	int acertou = 0;
	int enforcou = 0;

	escolhe_palavra_secreta();
	introducao();

	do {
		desenha_forca();
		chuta();

	} while (!acertou && !enforcou);
} 