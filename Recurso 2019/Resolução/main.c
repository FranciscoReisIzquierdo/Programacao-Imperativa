#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
    int nlesq;
    char *linha;
    struct nodo *esq, *dir;
}*Rope;

//Questão 1:
int nlinhas(Rope r){
    if(!r) return 0;
    return 1+ r-> nlesq+ nlinhas(r-> dir);
}

//Questão 2:
void print(Rope r){
    if(r){
        print(r-> esq);
        printf("%s\n", r-> linha);
        print(r-> dir);
    }
}

//Questão 3:
char *giveLine(int l, Rope r){
    if(r){
        giveLine(l, r-> esq);
        if(!l) return r-> linha;
        char* linha= giveLine(l- 1, r-> dir);
        return linha;
    }
}

char index(int l, int c, Rope r){
    int linhas= nlinhas(r);
    if(linhas -1< l) return '\0';
    char *line= giveLine(l, r);
    int i= 0;
    for(; c && line[i]; c--, i++);
    return !c? line[i]: '\0';
}

int main() {
    Rope r= malloc(sizeof(struct nodo));
    r-> nlesq= 5;
    r-> linha= "disciplina";
    r-> esq= malloc(sizeof(struct nodo));
    r-> dir= malloc(sizeof(struct nodo));
    r-> esq-> nlesq= 3;
    r-> esq-> linha= "definitivamente";
    r-> dir-> nlesq= 1;
    r-> dir-> linha= "muito";
    r-> esq-> esq= malloc(sizeof(struct nodo));
    r-> esq-> dir= malloc(sizeof(struct nodo));
    r-> dir-> esq= malloc(sizeof(struct nodo));
    r-> dir-> dir= malloc(sizeof(struct nodo));
    r-> esq-> esq-> nlesq= 1;
    r-> esq-> esq-> linha= "Imperativa";
    r-> esq-> dir-> nlesq= 0;
    r-> esq-> dir-> linha= "uma";
    r-> dir-> esq-> nlesq= 0;
    r-> dir-> esq-> linha= "mesmo";
    r-> dir-> dir-> nlesq= 0;
    r-> dir-> dir-> linha= "fixe.";
    r-> esq-> dir-> esq= r-> esq-> dir-> dir= NULL;
    r-> dir-> esq-> esq= r-> dir-> esq-> dir= r-> dir-> dir-> esq= r-> dir-> dir-> dir= NULL;
    r-> esq-> esq-> esq= malloc(sizeof(struct nodo));
    r-> esq-> esq-> dir= malloc(sizeof(struct nodo));
    r-> esq-> esq-> esq-> nlesq= 0;
    r-> esq-> esq-> esq-> linha= "Programacao";
    r-> esq-> esq-> dir-> nlesq= 0;
    r-> esq-> esq-> dir-> linha= "é,";
    r-> esq-> esq-> esq-> esq= r-> esq-> esq-> esq-> dir= r-> esq-> esq-> dir-> esq= r-> esq-> esq-> dir-> dir= NULL;
    //int linhas= nlinhas(r);
    //print(r);
    return 0;
}