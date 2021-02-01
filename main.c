#include <stdio.h>
#include <stdlib.h>

//Questão 1
void geraFib(LInt *l, int N){

    int i = 0, c1 = 1, c2 = 1;
    int tmp;
    while (i < N){
        *l = malloc(sizeof(struct slist));
        (*l)->valor = c1;
        tmp = c1;
        c1 = c2;
        c2 += tmp;
        l = &((*l)->prox);
        i++;
    }
    *l = NULL;
}


void geraFact(LInt *l, int N){
    int i = 1, acc = 1;
    while (i <= N){
        *l = malloc(sizeof(struct slist));
        (*l)->valor = acc;

        acc *= i;

        l = &((*l)->prox);
        i++;
    }
    *l = NULL;
}


//Questão 2
int verificaGeometrica(int s[], int n) {
    int flag = 1, i, b;
    if (n>1) {
        if (s[0]==0) b = 0; else b = s[1]/s[0];
        for (i=2; flag && i<n; i++) {
            if (s[i] != b*s[i-1])
                flag = 0;
        }
    }
    return flag;
}


int verificaLinear(int s[], int n) {
    int flag = 1, i, b;
    if (n>1) {
        b = s[1] - s[0];
        for (i=2; flag && i<n; i++) {
            if (s[i] != b + s[i-1])
                flag = 0;
        }
    }
    return flag;
}


//Questao 3
int tamanho (LInt l) {
    int r = 1;
    LInt init = l;
    if (l == NULL) return 0;
    while (l->prox != init) {
        r++;
        l = l->prox;
    }
    return r;
}


LInt ant (LInt l) {
    LInt init = l;
    if (l == NULL) return NULL;
    while (l->prox != init) {
        l = l->prox;
    }
    return l;
}


//Questão 4
int capicua(DLint l) {
    NodoD *front = l.front;
    NodoD *last = l.last;
    while (front != last && last->prox != front) {
        if (front->valor != last->valor) return 0;
        front = front->prox;
        last = last->ant;
    }
    return 1;
}


void reverse(DLint *l) {
    NodoD *front = l->front;
    NodoD *last = l->last;
    NodoD *aux;
    while (front != NULL) {
        aux = front->prox;
        front->prox = front->ant;
        front->ant = aux;
        front = aux;
    }
    l->last = l->front;
    l->front = last;
}

//ou

void reverse2(DLint *l) {
    NodoD *front = l->front;
    NodoD *last = l->last;
    int aux;
    while (front != last && last->prox != front) {
        aux = front->valor;
        front->valor = last->valor;
        last->valor = aux;
        front = front->prox;
        last = last->ant;
    }
}


//Questão 5
typedef struct abin {
    int valor;
    struct abin *esq, *dir;
} *ABin;

void preorderCaminho (ABin a, char cam[], int tam){
    if (a != NULL) {
        cam[tam] = '\0'; printf ("%s%d\n", cam, tam);
        cam[tam] = '<';  preorderCaminho (a->esq,cam,tam+1);
        cam[tam] = '>';  preorderCaminho (a->dir,cam,tam+1);
    }
}


void posorderCaminho (ABin a, char cam[], int tam){
    if (a != NULL) {
        cam[tam] = '<';  preorderCaminho (a->esq,cam,tam+1);
        cam[tam] = '>';  preorderCaminho (a->dir,cam,tam+1);
        cam[tam] = '\0'; printf ("%s%d\n", cam, tam);
    }
}


void imprimePRE (ABin a) {
    char caminho [100];
    preorderCaminho (a, caminho, 0);
}


void imprimePOS (ABin a) {
    char caminho [100];
    posorderCaminho (a, caminho, 0);
}


//Questão 6
void pad (char *texto, int p, int N){
    int w, // posição de escrita
    r, // posicao de leitura
    i;
    // O texto vai ser lido (e construido)
    // do final para o inicio;
    r = strlen(texto)-1;
    w = r + N * (p-1);

    texto[w+1]='\0'; // fim do texto final
    // espaços no fim do texto
    while (isspace(texto[r]))
        texto [w--] = texto [r--];
    // tratar p-1 palavras
    while (p>1) {
        // copiar palavra
        while (!isspace (texto[r]))
            texto [w--] = texto [r--];
        // copiar espaços
        while (isspace (texto[r]))
            texto [w--] = texto [r--];
        // acrescentar N espaços
        for (i=0;i<N;i++) texto[w--] = ' ';
        p--;
    }
}

//Questao 7
/* versão em que quantos tem a totalidade dos elementos*/
int calculaQuantosTot (Palavras p){
    // retorna o numero de elementos da árvore
    int e, d, r=0;
    if (p != NULL) {
        e = calculaQuantosTot (a->esq);
        d = calculaQuantosTot (a->dir);
        r = p->quantos = 1 + e + d;
    }
    return r;
}

/* versão em que quantos tem o num de elementos à esq*/
int calculaQuantosEsq (Palavras p){
    // retorna o numero de elementos da árvore
    int e, d, r=0;
    if (p != NULL) {
        p->quantos = e = calculaQuantosEsq (a->esq);
        d = calculaQuantosEsq (a->dir);
        r = 1 + e + d;
    }
    return r;
}

//Questao 8
/* versão em que quantos tem a totalidade dos elementos*/

int acrescentaTot (Palavras *e, char *p) {
    int r = 0;
    if (*e == NULL) {
        *e = malloc (sizeof (struct nodo));
        if (*e == NULL) r = 2;
        else { (*e)->raiz = strdup (p);
            (*e)->quantos = 1;
            (*e)->esq = (*e)->dir = NULL;
        }
    } else {
        cmp = strcmp (p,(*e)->raiz);
        if (cmp == 0) r = 2;
        else if (cmp < 0) r = acrescentaTot (&((*e)->esq), p);
        else              r = acrescentaTot (&((*e)->dir), p);
        if (r == 0) (*e)->quantos ++;
    }
    return r;
}
/* versão em que quantos tem o num de elementos à esq*/

int acrescentaEsq (Palavras *e, char *p) {
    int r = 0;
    if (*e == NULL) {
        *e = malloc (sizeof (struct nodo));
        if (*e == NULL) r = 2;
        else { (*e)->raiz = strdup (p);
            (*e)->quantos = 0;
            (*e)->esq = (*e)->dir = NULL;
        }
    } else {
        cmp = strcmp (p,(*e)->raiz);
        if (cmp == 0) r = 2;
        else if (cmp < 0) { r = acrescentaEsq (&((*e)->esq), p);
            if (r > 0) (*e)->quantos ++;
        }
        else r = acrescentaEsq (&((*e)->dir), p);
    }
    return r;
}

//Questao 9
/* versão em que quantos tem a totalidade dos elementos*/

char *atRankTot (Palavras p, int k) {
    char *r = NULL;
    int e;  // numero de elementos à esquerda
    if (p != NULL) {
        e = (p->esq == NULL) ? 0 : p->esq->quantos;
        if (k == e) r = p->raiz;
        else if (k<e) r = atRankTot (p->esq, k);
        else          r = atRankTot (p->dir, k-e-1);
    }
    return r;
}


/* versão em que quantos tem o num de elementos à esq*/

char *atRankEsq (Palavras p, int k) {
    char *r = NULL;
    if (p != NULL) {
        if (k == p->quantos) r = p->raiz;
        else if (k<p->quantos) r = atRankEsq (p->esq, k);
        else                   r = atRankEsq (p->dir, k - p->quantos - 1);
    }
    return r;
}


int main() {
    return 0;
}
