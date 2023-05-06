#include <stdio.h>
#include <stdlib.h>

#define M 1572869u
#define HASH(A) (A % M)
#define EXC(A, B) \
    int tt = A;   \
    A = B;        \
    B = tt
typedef struct celula
{
    int chave, ocorr; // inteiro ou ITEM ?
    struct celula *prox;
} celula;

typedef struct Item
{
    int code;
    char letter;
} Item;

celula th[M];

void inicializa_hash(celula *th);
int insere_hash(celula *th, Item chave);
int remove_hash(celula *th, Item chave);
int busca_ocorr(celula *th, Item chave);
void destroi_hash(celula *th);

void inicializa_hash(celula *th)
{
    for (int i = 0; i < M; i++)
        th[i].prox = NULL;
}

int insere_hash(celula *th, Item chave)
{
    celula *elem;
    int pos = HASH(chave.code);

    for (elem = th[pos].prox;
         elem != NULL && elem->chave != chave.code;
         elem = elem->prox)
        ;

    if (elem != NULL)
        elem->ocorr++;
    else
    {
        celula *nova = malloc(sizeof(celula));
        if (nova == NULL)
            return 1;
        nova->chave = chave.code;
        nova->ocorr = 1;
        nova->prox = th[pos].prox;
        th[pos].prox = nova;
    }

    return 0;
}

int remove_hash(celula *th, Item chave)
{
    celula *elem;
    int pos = HASH(chave.code);

    for (elem = &th[pos];
         elem->prox != NULL && elem->prox->chave != chave.code;
         elem = elem->prox)
        ;

    if (elem->prox != NULL)
    {
        celula *lixo = elem->prox;
        elem->prox = lixo->prox;
        free(lixo);

        return 0;
    }
    else
    {
        return 1;
    }
}

int busca_ocorr(celula *th, Item chave)
{
    celula *elem;
    int pos = HASH(chave.code);

    for (elem = th[pos].prox;
         elem != NULL && elem->chave != chave.code;
         elem = elem->prox)
        ;

    if (elem != NULL)
        return elem->ocorr;
    else
        return 0;
}

void destroi_hash(celula *th)
{
    for (int i = 0; i < M; i++)
    {
        celula *elem = th[i].prox;
        while (elem != NULL)
        {
            celula *lixo = elem;
            elem = elem->prox;
            free(lixo);
        }
    }
}

int separe(int *V, int l, int r)
{
    int i = l - 1, j = r;
    int v = V[r];
    for (;;)
    {
        while (V[++i] < v)
            ;
        while (v < V[--j])
            if (j == l)
                break;
        if (i >= j)
            break;
        EXC(V[i], V[j]);
    }
    EXC(V[i], V[r]);
    return i;
}

void insertionSort(int *vetor, int l, int r)
{
    int minor, k, aux, i;

    for (i = r - 1; i > l; i--)
    {
        if (vetor[i] < vetor[i - 1])
        {
            EXC(vetor[i - 1], vetor[i]);
        }
    }

    for (k = 2; k <= r; k++)
    {
        int u = k;
        aux = vetor[u];

        while (aux < vetor[u - 1])
        {
            vetor[u] = vetor[u - 1];
            u--;
        }
        vetor[u] = aux;
    }
}

void qs(int *v, int l, int r)
{
    if (r - l <= 32)
        return;

    EXC(v[(l + r) / 2], v[r - 1]);

    if (v[l] < v[r - 1])
    {
        EXC(v[l], v[r - 1]);
    }
    if (v[l] < v[r])
    {
        EXC(v[l], v[r]);
    }
    if (v[r - 1] < v[r])
    {
        EXC(v[r - 1], v[r]);
    }

    int j = separe(v, l + 1, r - 1);
    qs(v, l, j - 1);
    qs(v, j + 1, r);
}

void qsI(int *V, int l, int r)
{
    qs(V, l, r);
    insertionSort(V, l, r);
}

int main()
{
    inicializa_hash(&th);
    int code, i, nums = 0;
    char letter;

    while (scanf("%d %c", &code, &letter) != EOF)
    {
        Item a;
        a.code = code;
        a.letter = letter;
        insere_hash(&th, a);
        nums++;
    }

    // arrumar qs para ordenar por chave
    qsI(&th, 0, nums);
    for (i = 0; i < nums; i++)
    {
        }

    return 0;
}