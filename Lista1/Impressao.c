#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le)
{
    while (le != NULL)
    {
        printf("%d ->", le->dado);
        le = le->prox;
    }
    printf("NULL\n");
}

void imprime_rec(celula *le)
{
    if (le == NULL)
    {
        printf("NULL\n");
        return;
    }

    printf("%d -> ", le->dado);
    imprime_rec(le->prox);
    return;
}
