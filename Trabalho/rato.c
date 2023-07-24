#include <stdio.h>
#include <stdlib.h>

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

void andarFrente()
{
    printf("m");
}
void andarDir()
{
    printf("r");
    printf("m");
}

void andarEsq()
{
    printf("l");
    printf("m");
}

void andarTras()
{
    printf("l");
    printf("l");
    printf("m");
}

int main()
{
    int data, prox;
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