#include <stdio.h>
#include <stdlib.h>

#include "duelo.h"

int main() {
    Card *cards, prassodia;
    int n;
    inputPrassodia(&n, &prassodia);
    allocateCards(&cards, n);
    inputCardsVector(cards, n);
    freeCards(&cards);
    printResult(operations(cards, prassodia, n));
    return 0;
}