#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[16];
    int pontuacoes[12];
    int pontuacaoFinal;
    int classificacao;
} Jogador;

int compararJogadores(const void *a, const void *b) {
    Jogador *jogadorA = (Jogador *)a;
    Jogador *jogadorB = (Jogador *)b;

    if (jogadorB->pontuacaoFinal != jogadorA->pontuacaoFinal) {
        return jogadorB->pontuacaoFinal - jogadorA->pontuacaoFinal;
    } else {
        return strcmp(jogadorA->nome, jogadorB->nome);
    }
}

int main() {
    int numJogadores, i, j;

    while (1) {
        scanf("%d", &numJogadores);
        if (numJogadores == 0) {
            break;
        }

        Jogador jogadores[numJogadores];

        for (i = 0; i < numJogadores; i++) {
            scanf("%s", jogadores[i].nome);
            for (j = 0; j < 12; j++) {
                scanf("%d", &jogadores[i].pontuacoes[j]);
            }

            jogadores[i].pontuacaoFinal = 0;
            for (j = 0; j < 12; j++) {
                jogadores[i].pontuacaoFinal += jogadores[i].pontuacoes[j];
            }
        }

        qsort(jogadores, numJogadores, sizeof(Jogador), compararJogadores);

        for (i = 0; i < numJogadores; i++) {
            jogadores[i].classificacao = i + 1;
        }

        printf("Teste %d\n", i);
        for (i = 0; i < numJogadores; i++) {
            printf("%d %d %s\n", jogadores[i].classificacao, jogadores[i].pontuacaoFinal, jogadores[i].nome);
        }

        printf("\n");
    }

    return 0;
}