#ifndef DUELO_H
#define DUELO_H

typedef struct {
    int attack;
    int defense;
    int ability;
} Card;

void allocateCards(Card **cards, int n);
void freeCards(Card **cards);
Card input();
void inputPrassodia(int *n, Card *Prassodia);
void inputCardsVector(Card *cards, int n);
int operations(Card *cards, Card Prassodia, int n);
void toSum(Card *sum, int a, int b, int c);
void printResult(int value);

#endif