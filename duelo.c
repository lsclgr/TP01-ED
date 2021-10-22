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
    int aux = 0, win = 0;

    for (int i = 0; i < n; i++) {
        if ((cards[i].attack >= Prassodia.attack) ||
            (cards[i].defense >= Prassodia.defense) ||
            (cards[i].ability >= Prassodia.ability)) {
            continue;
        } else {
            sum.attack = cards[i].attack;
            sum.defense = cards[i].defense;
            sum.ability = cards[i].ability;
            printf("\n%d\n", cards[i].ability);
            printf(
                "\nif 1 - soma ataque: %d soma defesa: %d soma habillidade: "
                "%d\n",
                sum.attack, sum.defense, sum.ability);
            for (int j = i + 1; j < n; j++) {
                if ((cards[j].attack >= Prassodia.attack) ||
                    (cards[j].defense >= Prassodia.defense) ||
                    (cards[j].ability >= Prassodia.ability)) {
                    continue;
                } else {
                    aux = j;
                    while (++aux < n) {
                        sum.attack = cards[i].attack + cards[j].attack;
                        sum.defense = cards[i].defense + cards[j].defense;
                        sum.ability = cards[i].ability + cards[j].ability;
                        printf(
                            "\nif 2 - soma ataque: %d soma defesa: %d soma "
                            "habillidade: "
                            "%d\n",
                            sum.attack, sum.defense, sum.ability);
                        if ((cards[aux].attack >= Prassodia.attack) ||
                            (cards[aux].defense >= Prassodia.defense) ||
                            (cards[aux].ability >= Prassodia.ability)) {
                            continue;
                        } else {
                            if (((sum.attack + cards[aux].attack) <=
                                 Prassodia.attack) &&
                                ((sum.defense + cards[aux].defense) <=
                                 Prassodia.defense) &&
                                ((sum.ability + cards[aux].ability) <=
                                 Prassodia.ability)) {
                                toSum(&sum, cards[aux].attack,
                                      cards[aux].defense, cards[aux].ability);
                                printf(
                                    "\nif 3 - soma ataque: %d soma defesa: %d "
                                    "soma habillidade: "
                                    "%d\n",
                                    sum.attack, sum.defense, sum.ability);

                                for (int k = j + 1; k < n; k++) {
                                    if (k == aux) {
                                        continue;
                                    } else {
                                        if ((cards[k].attack >=
                                             Prassodia.attack) ||
                                            (cards[k].defense >=
                                             Prassodia.defense) ||
                                            (cards[k].ability >=
                                             Prassodia.ability)) {
                                            continue;
                                        } else if ((sum.attack <
                                                    Prassodia.attack) &&
                                                   (sum.defense <
                                                    Prassodia.defense) &&
                                                   (sum.ability <
                                                    Prassodia.ability)) {
                                            if (((sum.attack +
                                                  cards[k].attack) <=
                                                 Prassodia.attack) &&
                                                ((sum.defense +
                                                  cards[k].defense) <=
                                                 Prassodia.defense) &&
                                                ((sum.ability +
                                                  cards[k].ability) <=
                                                 Prassodia.ability)) {
                                                toSum(&sum, cards[k].attack,
                                                      cards[k].defense,
                                                      cards[k].ability);
                                                printf(
                                                    "\nif 4 - soma ataque: %d "
                                                    "soma defesa: %d soma "
                                                    "habillidade: "
                                                    "%d\n",
                                                    sum.attack, sum.defense,
                                                    sum.ability);
                                            }
                                            continue;
                                        } else if ((sum.attack =
                                                        Prassodia.attack) &&
                                                   (sum.defense =
                                                        Prassodia.defense) &&
                                                   (sum.ability =
                                                        Prassodia.ability)) {
                                            win = 1;
                                            break;
                                        } else {
                                            continue;
                                        }
                                    }
                                    if (win == 1) break;
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

void toSum(Card *sum, int a, int b, int c) {
    sum->attack += a;
    sum->defense += b;
    sum->ability += c;
}
