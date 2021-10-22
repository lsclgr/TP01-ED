#include "duelo.h"

#include <stdio.h>
#include <stdlib.h>

void allocateCards(Card **cards, int n) {
    *cards = malloc(n * sizeof(Card));
    if (cards == NULL) {
        printf("Memória insuficiente !\n");
        exit(1);
    }
}
void freeCards(Card **cards) { free(*cards); }
Card input() {
    Card card;
    scanf("%d%d%d", &card.attack, &card.defense, &card.ability);
    return card;
}
void inputPrassodia(int *n, Card *Prassodia) {
    scanf("%d", n);
    *Prassodia = input();
}
void inputCardsVector(Card *cards, int n) {
    for (int i = 0; i < n; i++) {
        cards[i] = input();
    }
}
int operations(Card *cards, Card Prassodia, int n) {
    Card sum;
    int aux = 0, aux2 = 0, win = 0;

    for (int i = 0; i < n; i++) {
        if ((cards[i].attack >= Prassodia.attack) ||
            (cards[i].defense >= Prassodia.defense) ||
            (cards[i].ability >= Prassodia.ability)) {
            continue;
        } else {
            sum.attack = cards[i].attack;
            sum.defense = cards[i].defense;
            sum.ability = cards[i].ability;

            for (int j = i + 1; j < n; j++) {
                if ((cards[j].attack >= Prassodia.attack) ||
                    (cards[j].defense >= Prassodia.defense) ||
                    (cards[j].ability >= Prassodia.ability)) {
                    continue;
                } else {
                    aux2 = j;
                    aux = ++aux2;
                    while (aux2 < n) {
                        sum.attack = cards[i].attack + cards[j].attack;
                        sum.defense = cards[i].defense + cards[j].defense;
                        sum.ability = cards[i].ability + cards[j].ability;
                        if ((cards[aux2].attack >= Prassodia.attack) ||
                            (cards[aux2].defense >= Prassodia.defense) ||
                            (cards[aux2].ability >= Prassodia.ability)) {
                            aux2++;
                        } else if (((sum.attack += cards[aux2].attack) <
                                    Prassodia.attack) &&
                                   ((sum.defense += cards[aux2].defense) <
                                    Prassodia.defense) &&
                                   ((sum.ability += cards[aux2].ability) <
                                    Prassodia.ability)) {
                            sum.attack += cards[aux2].attack;
                            sum.defense += cards[aux2].defense;
                            sum.ability += cards[aux2].ability;
                            aux = ++aux2;
                            while (aux < n) {
                                if ((cards[aux].attack >= Prassodia.attack) ||
                                    (cards[aux].defense >= Prassodia.defense) ||
                                    (cards[aux].ability >= Prassodia.ability)) {
                                    aux++;
                                } else if ((sum.attack < Prassodia.attack) &&
                                           (sum.defense < Prassodia.defense) &&
                                           (sum.ability < Prassodia.ability)) {
                                    sum.attack += cards[aux].attack;
                                    sum.defense += cards[aux].defense;
                                    sum.ability += cards[aux].ability;
                                    aux++;
                                } else if ((sum.attack = Prassodia.attack) &&
                                           (sum.defense = Prassodia.defense) &&
                                           (sum.ability = Prassodia.ability)) {
                                    win = 1;
                                    break;
                                } else {
                                    aux++;
                                }
                            }
                        }
                        if (win == 1) break;
                    }
                }
                if (win == 1) break;
            }
        }
        if (win == 1) break;
    }
    if (win == 1)
        return 1;
    else
        return 0;
}

void printResult(int value) {
    if (value == 1)
        printf("Y\n");
    else
        printf("N\n");
}