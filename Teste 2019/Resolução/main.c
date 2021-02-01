#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct digitos{
    unsigned char val;
    struct digitos *prox;
}*Num;

unsigned char converseDigit(unsigned  int i){
    if(i== 0) return '0';
    if(i== 1) return '1';
    if(i== 2) return '2';
    if(i== 3) return '3';
    if(i== 4) return '4';
    if(i== 5) return '5';
    if(i== 6) return '6';
    if(i== 7) return '7';
    if(i== 8) return '8';
    if(i== 9) return '9';
}

//Questão 1 a):
Num fromInt(unsigned int i){
    int valor= 0;
    Num lista= NULL, temp= NULL;
    while(i){
        valor= i% 10; i/= 10;
        Num new= malloc(sizeof(struct digitos));
        new-> val= converseDigit(valor);
        new-> prox= NULL;
        if(!lista) lista= new;
        else{
            temp= lista;
            for(; temp-> prox; temp= temp-> prox);
            temp-> prox= new;
        }
    }
    return lista;
}

//Questão 1 b):
int potencia(unsigned int base, unsigned int exp){
    if(!exp) return 1;
    return base* potencia(base, --exp);
}

unsigned int toInt(Num n){
    if(!n) return 0;
    int exp= 0, valor= 0;
    while(n){
        int digit= n-> val -'0';
        valor+= digit* potencia(10, exp++);
        n= n-> prox;
    }
    return valor;
}

//Questão 2:
Num addNum(Num a, Num b){
    unsigned int first= toInt(a);
    unsigned second= toInt(b);
    unsigned soma= first+ second;
    Num result= fromInt(soma);
    return result;
}

//Questão 3:
Num mulDig(unsigned char dig, Num a){
    unsigned int valor= toInt(a);
    unsigned int digit= dig- '0';
    valor*= digit;
    Num result= fromInt(valor);
    return result;
}

//Questão 4:
Num mulNum(Num a, Num b){
    unsigned int first= toInt(a);
    unsigned int second= toInt(b);
    unsigned int mult= first* second;
    Num multiplica= fromInt(mult);
    return multiplica;
}

void imprimeLista(Num lista){
    if(!lista) printf("0\n");
    for(; lista; lista= lista-> prox) printf("%c-> ", lista-> val);
    printf("NULL\n");
}

Num criaLista(){
    int i;
    Num lista= NULL;
    while(i!= -1){
        scanf("%d\n", &i);
        Num new= malloc(sizeof(struct digitos));
        new-> val= '0'+ i;
        new-> prox= NULL;
        if(!lista) lista= new;
        else{
            Num temp= lista;
            for(; temp-> prox; temp= temp-> prox);
            temp-> prox= new;
        }
    }
    return lista;
}

int main() {
    int questao;
    printf("Insira o numero da questao\n");
    scanf("%d\n", &questao);
    if(questao == 1) {
        printf("Insira o numero que deseja ver na lista de digitos\n");
        int numero;
        scanf("%d\n", &numero);
        Num lista = fromInt(numero);
        imprimeLista(lista);
    }
    if(questao == 2) {
        printf("Insere os digitos (um a um) da lista de digitos acabada em -1\n");
        Num lista = criaLista();
        printf("Lista criada:\n");
        imprimeLista(lista);
        int x = toInt(lista);
        printf("Numero: %d\n", x);
    }

/*
    Num a= malloc(sizeof(struct digitos));
    a-> val= '7';
    a-> prox= malloc(sizeof(struct digitos));
    a-> prox-> val= '8';
    a-> prox-> prox= malloc(sizeof(struct digitos));
    a-> prox-> prox-> val= '9';
    a-> prox-> prox-> prox= NULL;

    Num b= malloc(sizeof(struct digitos));
    b-> val= '6';
    b-> prox= malloc(sizeof(struct digitos));
    b-> prox-> val= '7';
    b-> prox-> prox= malloc(sizeof(struct digitos));
    b-> prox-> prox-> val= '8';
    b-> prox-> prox-> prox= malloc(sizeof(struct digitos));
    b-> prox-> prox-> prox-> val= '9';
    b-> prox-> prox-> prox-> prox= NULL;
    Num soma= addNum(a, b);

    //Num multDigito= mulDig('3', n);
    Num multiplica= mulNum(a, b);*/
    return 0;
}