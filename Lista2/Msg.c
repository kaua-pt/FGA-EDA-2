#include <stdio.h>
#include <stdlib.h>

#define M 1572869u

int main()
{
    unsigned int maior = 0, menor = 2e31, numero, j;
    char *v = calloc(M, sizeof(char)), l;

    while (scanf("%u %c", &numero, &l) != EOF)
    {
        v[numero] = l;

        if (numero > maior)
            maior = numero;
        if (numero < menor)
            menor = numero;
    }

    printf("%s\n", &v[menor]);
    return 0;
}