#include "duelo.h"

#include <stdio.h>
#include <stdlib.h>

// função para alocar as cartas
void allocateCards(Card **cards, int n) {
    *cards = malloc(n * sizeof(Card));
    if (cards == NULL) {
        printf("Memória insuficiente !\n");
        exit(1);
    }
}

// função para liberar as cartas alocadas
void freeCards(Card **cards) { free(*cards); }

// função para ler o struct carta
Card input() {
    Card card;
    scanf("%d%d%d", &card.attack, &card.defense, &card.ability);
    return card;
}
// ler primeira linha, n e prassodia
void inputPrassodia(int *n, Card *Prassodia) {
    scanf("%d", n);
    *Prassodia = input();
}
// ler vetor do usuario
void inputCardsVector(Card *cards, int n) {
    for (int i = 0; i < n; i++) {
        cards[i] = input();
    }
}

// principais operações
int operations(Card *cards, Card Prassodia, int n) {
    Card sum;
    int countSum = 0;

    // total de possibilidades é 2^n
    // 1<<n significa 1*2*2*2... n vezes
    int total = 1 << n;

    for (int i = 0; i < total; i++) {
        // inicializa soma de 0
        sum.attack = 0;
        sum.defense = 0;
        sum.ability = 0;
        // contador para verificar se é a soma de 2 ou mais numeros
        countSum = 0;
        for (int j = 0; j < n; j++) {
            // if para verificar se i e j são não nulos e se essas posições
            // existem no vetor
            if ((i & (1 << j)) != 0) {
                // verifica se encontrou a soma q dá prassodia
                if ((sum.attack == Prassodia.attack) &&
                    (sum.defense == Prassodia.defense) &&
                    (sum.ability == Prassodia.ability) && countSum > 1) {
                    return 1;
                } else {
                    // se a carta for maior q prassodia, nem soma ela
                    if ((cards[j].attack >= Prassodia.attack) ||
                        (cards[j].defense >= Prassodia.defense) ||
                        (cards[j].ability >= Prassodia.ability)) {
                        continue;
                        // enquanto a soma for menor que prassodia, continua
                        // somando
                    } else if ((sum.attack < Prassodia.attack) &&
                               (sum.defense < Prassodia.defense) &&
                               (sum.ability < Prassodia.ability)) {
                        // se o somatorio com a proxima carta somada for maior
                        // que prassodia, nem adiciona ela na soma, mas se for
                        // menor faz a soma
                        if (((sum.attack + cards[j].attack) <=
                             Prassodia.attack) &&
                            ((sum.defense + cards[j].defense) <=
                             Prassodia.defense) &&
                            ((sum.ability + cards[j].ability) <=
                             Prassodia.ability)) {
                            toSum(&sum, cards[j].attack, cards[j].defense,
                                  cards[j].ability);
                            countSum++;
                            if ((sum.attack == Prassodia.attack) &&
                                (sum.defense == Prassodia.defense) &&
                                (sum.ability == Prassodia.ability) &&
                                countSum > 1) {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    // se não encontrar, retorna 0
    return 0;
}

// função para imprimir resultado
void printResult(int value) {
    if (value == 1)
        printf("Y\n");
    else
        printf("N\n");
}

// função para somar
void toSum(Card *sum, int a, int b, int c) {
    sum->attack += a;
    sum->defense += b;
    sum->ability += c;
}
