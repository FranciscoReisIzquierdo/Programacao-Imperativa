#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <math.h>
#define MAXLINE 1024
char buffer[MAXLINE];


//Teste de Recurso 2019/2020:

//Tipo para representar listas ligadas de inteiros
typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

//Tipo para representar árvores binárias de inteiros
typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;


//Questão 1:
int potencia(unsigned int base, unsigned int exp){
    if(!exp) return 1;
    return base* potencia(base, --exp);
}

int reverse (int x){
    int digits[MAXLINE], index= 0, number= 0, ans= 0;
    while(x>= 1){
        digits[index++]= x% 10;
        x/= 10;
    }
    index--;
    for(; index>= 0; index--, ans++){
        number= number+ digits[index]* potencia(10, ans);
    }
    return number;
}

//Questão 2:
int itsVogal(char c){
    if(c== 'A' || c== 'E' || c== 'I' || c== 'O' || c== 'U' || c== 'a' || c== 'e' || c== 'i' || c== 'o' || c== 'u')
        return 1;
    else return 0;
}

int vogal (char *t){
    int i= 0, j= 0, flag= 1, size= 0;
    while(t[i]) {
        if (!itsVogal(t[i])){
            t[j++] = t[i++];
        }
        else if (itsVogal(t[i]) && t[i]== t[i +1]){
            t[j++] = t[i];
            i+= 2;
        }
        else{
            t[j++]= t[i++];
        }
    }
    t[j]= '\0';
    for(int index= 0; t[index]; index++) size++;
    return size;
}

//Questão 3:
typedef struct dlist {
    int valor; struct dlist *ant, *prox;
} *DList;

int DLIntOk (DList l){
    if(!l) return 1;
    int flag= 1;
    DList ans= NULL;
    while(l && flag){
        if(l-> ant!= ans) flag= 0;
        ans= l;
        l= l-> prox;
    }
    return flag;
}

//Questão 4:
typedef struct {LInt *front, *last} DifList;

void mypreorderaux(ABin a, LInt *l){
    if(a){
        for(; (*l); l= &((*l)-> prox));
        (*l) = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        (*l)->prox = NULL;
        mypreorderaux(a-> esq, l);
        mypreorderaux(a-> dir, l);
    }
}

void mypreorder(ABin a, LInt * l) {
    *l= NULL;
    mypreorderaux(a, l);
}

DifList imprime (ABin a){
    LInt l= NULL;
    mypreorder(a, &l);
    DifList lista;
    LInt frente= l;
    lista.front= frente;
    for(; l-> prox; l= l-> prox);
    LInt ultimo= l;
    lista.last= ultimo;
    return lista;
}

//Questao 5:
void imprimeAte(ABin a, int x){
    if(a){
        if(a-> valor>= x){
            imprimeAte(a-> dir, x);
            printf(" %d ", a-> valor);
            imprimeAte(a-> esq, x);
        }
        else imprimeAte(a-> dir, x);
    }
}

//Questão 6:
int track(ABin a, int x, LInt *p){
    if(!a){
        return 0;
    }
    if(a-> valor== x){
        *p= malloc(sizeof(struct lligada));
        (*p)-> valor= a-> valor;
        (*p)-> prox= NULL;
        return 1;
    }
    if(a-> valor!= x){
        *p= malloc(sizeof(struct lligada));
        (*p)-> valor= a-> valor;
        (*p)-> prox= NULL;
        if(a-> valor> x) return track(a-> esq, x, &((*p)-> prox));
        else return track(a-> dir, x, &((*p)-> prox));
    }
}

int mycaminho(ABin a, int x, LInt *p){
    int result= track(a, x, p);
    if(!result){
        free((*p));
        *p= NULL;
    }
    return result;
}

//Questão 7:
int valida(char s[]){
    int i= 0, flag= 1;
    for(;s[i] && flag; i++){
        if(s[i]>= 47 && s[i]<= 57 && s[i +1]!= '(') flag= 0;
        if(s[i]== '('){
            for(int j= i; s[j] && s[j]!= ')'; j++)
                if(!s[j]) flag= 0;
        }
    }
    return flag;
}


void imprimeLista(LInt lista){
    for(; lista; lista= lista-> prox) printf("%d-> ", lista-> valor);
    printf("NULL\n");
}

int main() {
    int questao;
    printf("Digite o numero da questao que deseja ver\n");
    scanf("%d", &questao);
    if(questao== 1){
        int number;
        printf("Digite o numero de deseja ver invertido\n");
        scanf("%d", & number);
        printf("%d\n", reverse(number));
    }
    if(questao== 2) {
        //Alterar argumento da função se assim desejar (não estava a conseguir usar o fgets nem o sscanf)
        char texto[MAXLINE]= "Heeeeeello Woorrdl";
        int size = vogal(texto);
        printf("%d\n", size);
        printf("Texto resultante: %s\n", texto);
    }
    if(questao== 3){
        //Alterar campos de l-> prox e l-> ant para obter resultados diferentes
        DList l= malloc(sizeof(struct dlist));
        l-> ant= NULL;
        l-> valor= 5;
        l-> prox= malloc(sizeof(struct dlist));
        l-> prox-> ant= l;
        l-> prox-> valor= 10;
        l-> prox-> prox= malloc(sizeof(struct dlist));
        l-> prox-> prox-> ant= l-> prox;
        l-> prox-> prox-> valor= 15;
        l-> prox-> prox-> prox= NULL;
        printf("%d\n", DLIntOk(l));
    }
    if(questao== 4 || questao== 5 || questao== 6){
        //Alterar valores dos nodos para obter resultados diferentes
        ABin a= malloc(sizeof(struct nodo));
        a-> valor= 5;
        a-> esq= malloc(sizeof(struct nodo));
        a-> dir= malloc(sizeof(struct nodo));
        a-> esq-> valor= 3;
        a-> dir-> valor= 8;
        a-> esq-> esq= malloc(sizeof(struct nodo));
        a-> esq-> dir= malloc(sizeof(struct nodo));
        a-> dir-> esq= malloc(sizeof(struct nodo));
        a-> dir-> dir= malloc(sizeof(struct nodo));
        a-> esq-> esq-> valor= 1;
        a-> esq-> dir-> valor= 4;
        a-> dir-> esq-> valor= 6;
        a-> dir-> dir-> valor= 12;
        a-> esq-> esq-> esq= a-> esq-> esq-> dir= a-> esq-> dir-> esq= a-> esq-> dir-> dir= a-> dir-> esq-> esq= a-> dir-> esq-> dir= a-> dir-> dir-> esq= a-> dir-> dir-> dir= NULL;
        if(questao== 4) {
            DifList l = imprime(a);
            LInt frente = l.front;
            LInt ultimo = l.last;
            printf("Frente: %d\n", frente->valor);
            printf("Ultimo: %d\n", ultimo->valor);
        }
        if(questao== 5){
            int numero;
            printf("Digite o numero para ver os elementos da arvore maiores ou iguais a x\n");
            scanf("%d\n", &numero);
            imprimeAte(a, numero);
        }
        if(questao== 6){
            int numero;
            printf("Digite o numero x para ver o caminho ate x na arvore\n");
            scanf("%d\n", &numero);
            LInt lista= NULL;
            int resultado= mycaminho(a, numero, &lista);
            imprimeLista(lista);
            printf("Resultado da procura: %d\n", resultado);
        }
    }
    if(questao== 7){
        char texto[MAXLINE];
        printf("Escreva a string comprimida (sem espacos)\n");
        scanf("%s", texto);
        printf("Resultado: %d\n", valida(texto));
    }
    return 0;
}