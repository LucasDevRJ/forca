#include <stdio.h>
#include <string.h>

void introducao() {
	printf("******************\n");
    printf("* Jogo de Forca *\n");
    printf("******************\n\n");
}

void chuta(char chutes[26], int tentativas) {
	char chute;
	scanf(" %c", &chute);

	chutes[tentativas] = chute;
}

int main() {

	char palavras_secretas[20];

	sprintf(palavras_secretas, "MELANCIA");

	int acertou = 0;
	int enforcou = 0;

	char chutes[26];
	int tentativas = 0;

	introducao();


	do {
		for (int i = 0; i < strlen(palavras_secretas); i++) {
			int achou = 0;

			for (int j = 0; j < tentativas; j++) {
				if (chutes[j] == palavras_secretas[i]) {
					achou = 1;
					break;
				}
			}

			if (achou) {
				printf("%c ", palavras_secretas[i]);
			} else {
				printf("_ ");
			}
			
		}
		printf("\n");

		chuta(chutes, tentativas);
		tentativas++;

	} while (!acertou && !enforcou);
	
} 