#include <stdio.h>
#include <stdlib.h>

#define M 1572869u

typedef struct Item
{
    int id;
    char letra;
} Item;

int main()
{
    unsigned j;
    int maior = -1, menor = 2e31, numero;
    char l;
    Item *v = malloc(sizeof(Item) * M);

    while (scanf("%d %c", &numero, &l) != EOF)
    {
        v[numero].letra = l;

        if (numero > maior)
            maior = numero;
        if (numero < menor)
            menor = numero;
    }

    for (j = menor; j <= maior; j++)
        printf("%c", v[j].letra);

    printf("\n numerozin %c\n", v[872899].letra);
    printf("\n");
    return 0;
}