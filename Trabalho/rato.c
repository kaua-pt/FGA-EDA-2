#include <stdio.h>
#include <stdlib.h>
#define M 128

typedef struct Item
{
    char name;
} Item;

typedef struct Pilha
{
    Item *v;
    int size;
    int elem;
} Pilha;

int criaPilha(Pilha *pilha, int s)
{
    pilha->v = malloc(sizeof(Item) * s);
    if (pilha->v == NULL)
        return 1;

    pilha->size = s;
    pilha->elem = -1;
    return 0;
}

int estaVazia(Pilha *pilha)
{
    return pilha->elem == -1;
}

Item espia(Pilha *pilha)
{

    return pilha->v[pilha->elem];
}

int estaCheia(Pilha *pilha)
{
    return pilha->elem == pilha->size;
}

int empilha(Pilha *pilha, Item e)
{
    if (estaCheia(pilha))
        return 1;

    pilha->elem++;
    pilha->v[pilha->elem] = e;
    return 0;
}

int desempilha(Pilha *pilha)
{
    if (estaVazia(pilha))
    {
        return 1;
    }
    printf("%s\n", pilha->v[pilha->elem].name);
    pilha->elem--;
    return 0;
}

void desalocaPilha(Pilha *pilha)
{
    free(pilha->v);
    return;
}
typedef struct Cell
{
    int cima, tras, dir, esq;
} Cell;

Cell matrix[M][M];
int estaVoltando = 0;

int frente(int retorno)
{
    return (retorno << 0) & 1;
}
int direita(int retorno)
{
    return (retorno << 1) & 1;
}
int tras(int retorno)
{
    return (retorno << 2) & 1;
}
int esqueda(int retorno)
{
    return (retorno << 3) & 1;
}

void rEmpilhar(Pilha *pilha, char op)
{
    Item e;
    e.name = op;
    empilha(pilha, e);
}

void andarFrente(Pilha *pilha)
{
    if (estaVoltando == 0)
    {
        rEmpilhar(pilha, 'F');
    }
    printf("m");
}
void andarDir(Pilha *pilha)
{
    if (estaVoltando == 0)
    {
        rEmpilhar(pilha, 'D');
    }
    printf("r");
    printf("m");
}

void andarEsq(Pilha *pilha)
{
    if (estaVoltando == 0)
    {
        rEmpilhar(pilha, 'E');
    }
    printf("l");
    printf("m");
}

void andarTras(Pilha *pilha)
{
    if (estaVoltando == 0)
    {
        rEmpilhar(pilha, 'T');
    }
    printf("l");
    printf("l");
    printf("m");
}

int main()
{
    int data, prox, xInit = M / 2, yInit = M / 2;
    Pilha pilha;

    while (1)
    {
        printf("s");
        scanf("%d", &data);
        printf("d");
        scanf("%d", &prox);

        if (prox == 0)
            break;

        if (frente(data))
        {
            continue;
        }
        if (direita(data))
        {
            continue;
        }
        if (esqueda(data))
        {
            continue;
        }
        if (tras(data))
        {
            continue;
        }
    }

    return 0;
}