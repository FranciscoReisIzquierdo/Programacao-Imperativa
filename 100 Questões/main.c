#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <math.h>
#define MAXLINE 1024
char buffer[MAXLINE];

// Questão 1:
void leMaior() {
    printf("Digite a sequencia de numero acabada em 0\n");
    int numero, maior = 0;
    while (numero) {
        scanf("%d", &numero);
        if (maior <= numero) maior = numero;
    }
    printf("Maior da sequencia: %d", maior);
}

// Questão 2:
void mediaSequencia(){
    int numero, count= 0;
    double total= 0;
    printf("Digite a sequencia de numero acabada em 0\n");
    while(numero){
        scanf("%d", &numero);
        total+= numero;
        count++;
    }
    printf("Media da sequencia: %.5f", total/--count);
}

// Questão 3:
void segundoMaior(){
    int maior= 0, sndMaior= 0, numero;
    printf("Digite a sequencia de numero acabada em 0 (com pelo menos 2 numeros, excluindo o 0)\n");
    while (numero) {
        scanf("%d", &numero);
        if (maior <= numero){
            sndMaior= maior;
            maior = numero;
        }
        else if(sndMaior<= numero) sndMaior= numero;
    }
    printf("Segundo maior da sequencia: %d", sndMaior);
}

// Questão 4:
int bitsUm (unsigned int x){
    if(!x) return 0;
    int count= 1;
    while(x!= 1){
        if(x%2) count++;
        x/=2;
    }
    return count;
}

// Questão 5:
int trailingZ (unsigned int n) {
    if(!n) return 32;
    int count= 0;
    while(n!= 1){
        if(n% 2) break;
        count++;  n/= 2;
    }
    return count;
}
//Questão 6:
int qDig (unsigned int n){
    if(!n) return 1;
    int count= 0;
    while(n>= 1){
        count++;
        n/= 10;
    }
    return count;
}

//Questão 7:
char *mystrcat (char s1[], char s2[]){
    int i= 0, j= 0;
    while(s1[i]) i++;
    while(s2[j]){
        s1[i++]= s2[j++];
    }
    s1[i]= '\0';
    return s1;
}
//Questão 8:
char *mystrcpy (char *dest, char source[]){
    int i= 0;
    while(source[i]) dest[i]= dest[i++];
    source[i]= '\0';
    return source;
}

//Questão 9:
int mystrcmp (char s1[], char s2[]){
    int i= 0;
    while(s1[i] && s2[i]){
        if(s1[i]< s2[i]) return -1;
        else if(s1[i]> s2[i]) return 1;
        i++;
    }
    if(!s1[i] && !s2[i]) return 0;
    else if(!s1[i]) return -1;
    else return 1;
}

//Questão 10:
char *mystrstr (char s1[], char s2[]){
    int i= 0, j= 0;
    while(s1[i] && s2[j]){
        if(s1[i]== s2[j]) j++;
        else j= 0;
        i++;
    }
    if(!s2[j]) return &s1[i- j];
    else return NULL;
}

//Questão 11:
void mystrrev (char s[]){
    int i= 0, j= 0, lenght= 0;
    for(; s[lenght]; lenght++);
    char aux[lenght];
    while(s[i]){
        aux[i]= s[i++];
    }
    while(i){
        s[j++]= aux[i--];
    }
    s[j]= '\0';
}

//Questão 12:
void strnoV (char t[]){
    int i= 0, j= 0;
    while(t[i]){
        if(t[i]== 'A' || t[i]== 'E' || t[i]== 'I' || t[i]== 'O' || t[i]== 'U' || t[i]== 'a' || t[i]== 'e' || t[i]== 'i' || t[i]== 'o' || t[i]== 'u') i++;
        else t[j++]= t[i++];
    }
    t[j]= '\0';
}

//Questão 13:
void truncW (char t[], int n){
    int i= 0, j= 0, count= 0;
    while(t[i]){
        if(count== n){
            while(t[i]!= ' ' && t[i]) i++;
            if(!t[i]) break;
            t[j++]= t[i++];
            count= 0;
        }
        else if(t[i]!= ' '){
            t[j++]= t[i++];
            count++;;
        }
        else{
            t[j++]= t[i++];
            count= 0;
        }
    }
    t[j]= '\0';
}

//Questão 14:
char charMaisfreq (char s[]){
    int i= 0, j, count= 0, acum= 0;
    char aux= '\0';
    for(; s[i]; i++){
        for(j= i; s[j]; j++){
            if(s[j]== s[i]) count++;
        }
        if(count> acum){
            acum= count;
            aux= s[i];
        }
        count= 0;
    }
    return aux;
}

//Questão 15:
int iguaisConsecutivos (char s[]){
    if(!s[0]) return 0;
    int count= 0, i= 0, acum= 0;
    char aux= '\0';
    while(s[i]){
        aux= s[i];
        while(s[i]== aux){
            count++; i++;
        }
        if(acum< count) acum= count;
        count= 0;
    }
    return acum;
}

//Questão 16:
int not_in_prev(char str[], int k, int n) {
    int ans = 1;
    for(int i = k; i < n; i++) {
        if(str[i] == str[n]) {
            return 0;
        }
    }
    return ans;
}

int difConsecutivos (char s[]){
    int ans = 0;
    for(size_t i = 0; s[i]; i++) {
        int consec = 0;
        for(size_t j = i; s[j]; j++) {
            if(not_in_prev(s,i,j)) consec++;
            else break;
        }
        if (consec > ans) ans = consec;
    }
    return ans;
}

//Questão 17:
int maiorPrefixo (char s1 [], char s2 []){
    int i= 0, count= 0;
    for(; s1[i] && s2[i]; i++){
        if(s1[i]!= s2[i]) break;
        if(s1[i]== s2[i]) count++;
    }
    return count;
}

//Questão 18:
int maiorSufixo (char s1 [], char s2 []){
    int i= 0, j= 0, count= 0;
    for(; s1[i]; i++);
    for(; s2[j]; j++);
    for(; s1[i]== s2[j]; i--, j--) count++;
    return count -1;
}

//Questão 19:
int sufPref (char s1[], char s2[]){
    int i= 0, j= 0, count= 0;
    for(; s1[i]; i++){
        if(s1[i]== s2[j++]) count++;
        else{
            count= 0; j= 0;
        }
    }
    return count;
}

//Questão 20:
int contaPal (char s[]){
    int i= 0, count= 0;
    while(s[i]){
        if(s[i]!= ' ' && s[i]!= '\n' && (s[i +1]== ' ' || s[i +1]== '\0')) count++;
        i++;
    }
    return count;
}

//Questão 21:
int contaVogais (char t[]){
    int i= 0, count= 0;
    while(t[i]){
        if(t[i]== 'A' || t[i]== 'E' || t[i]== 'I' || t[i]== 'O' || t[i]== 'U' || t[i]== 'a' || t[i]== 'e' || t[i]== 'i' || t[i]== 'o' || t[i]== 'u') count++;
        i++;
    }
    return count;
}

//Questão 22:
int contida (char a[], char b[]){
    int i= 0, j= 0;
    while(a[i] && b[j]){
        if(a[i]== b[j]){
            i++; j= 0;
        }
        else j++;
    }
    if(!b[j]) return 0;
    else return 1;
}

//Questão 23:
int palindorome (char s[]){
    int i= 0, j= 0, flag= 1;
    for(; s[i]; i++);
    i--;
    for(;s[j] && flag; j++, i--){
        if(s[i]!= s[j]) flag= 0;
    }
    if(!flag) return 0;
    return flag;
}

//Questão 24:
int remRep (char s[]){
    int i= 0, j= 0, count= 0;
    char aux= '\0';
    while(s[i]){
        if(s[i]!= aux){
            aux= s[i];
            s[j++]= s[i];
            count++;
        }
        i++;
    }
    s[j]= '\0';
    return count;
}

//Questão 25:
int limpaEspacos (char s[]){
    if(!s[0]) return 0;
    int i= 0, j= 0, size= 0;
    s[i++]= s[j++];
    size++;
    while(s[i]){
        if(s[i -1]== ' ' && s[i]== ' ') i++;
        else{
            s[j++]= s[i++];
            size++;
        }
    }
    s[j]= '\0';
    return size;
}

//Questão 26:
void insere (int s[], int N, int x){
    int i= 0, aux;
    while(i< N){
        if(s[i]> x){
            aux= s[i];
            s[i]= x;
            x= aux;
        }
        i++;
    }
    s[i]= x;
}

//Questão 27:
void merge (int r [], int a[], int b[], int na, int nb){
    int i= 0, j= 0, index= 0;
    while(i< na && j< nb){
        if(a[i]< b[j]) r[index++]= a[i++];
        else r[index++]= b[j++];
    }
    if(i== na && j!= nb){
        for(; j< nb; j++) r[index++]= b[j];
    }
    if(i!= na && j== nb){
        for(; i< na; i++) r[index++]= a[i];
    }
}

//Questão 28:
int crescente (int a[], int i, int j){
    int flag= 1;
    while(i< j && flag){
        if(a[i]> a[i +1]) flag= 0;
        else i++;
    }
    return flag;
}

//Questão 29:
int retiraNeg (int v[], int N){
    int i= 0, j= 0, count= 0;
    while(i< N){
        if(v[i]> 0){
            v[j++]= v[i++];
            count++;
        }
        else i++;
    }
    return count;
}

//Questão 30:
int menosFreq (int v[], int N){
    int i= 1, temp= v[0], count= 1, acum= N;
    while(i< N){
        if(v[i- 1]== v[i]) count++;
        else{
            if(count< acum){
                acum= count;
                temp= v[i- 1];
            }
            count= 1;
        }
        i++;
    }
    if(count< acum){
        acum= count;
        temp= v[i- 1];
    }
    return temp;
}

//Questão 31:
int maisFreq (int v[], int N){
    int i= 1, temp= v[0], count= 1, acum= 0;
    while(i< N){
        if(v[i- 1]== v[i]) count++;
        else{
            if(count> acum){
                acum= count;
                temp= v[i- 1];
            }
            count= 1;
        }
        i++;
    }
    if(count> acum){
        acum= count;
        temp= v[i- 1];
    }
    return temp;
}

//Questão 32:
int maxCresc (int v[], int N){
    int i= 0, count= 1, acum= 0;
    while(i< N){
        if(v[i]<= v[i +1]) count++;
        else{
            if(count> acum) acum= count;
            count= 1;
        }
        i++;
    }
    return acum;
}

//Questão 33:
int elimRep (int v[], int N){
    int i= 0, j= 1;
    while(i< N){
        int index= j;
        while(j< N){
            if(v[j]!= v[i]) v[index++]= v[j++];
            else j++;
        }
        N= N-(j- index);
        i++; j= i +1;
    }
    return N;
}

//Questão 34:
int elimRepOrd (int v[], int N){
    int i= 1, j= i, ans= v[0];
    while(i< N){
        if(v[i]!= ans){
            ans= v[i];
            v[j++]= v[i++];
        }
        else i++;
    }
    return j;
}

//Questão 35:
int comunsOrd (int a[], int na, int b[], int nb){
    int i= 0, j= 0, count= 0;
    while(i< na && j< nb){
        if(a[i]< b[j]) i++;
        else if(a[i]> b[j]) j++;
        else{
            count++; i++; j++;
        }
    }
    return count;
}

//Questão 36:
int comuns (int a[], int na, int b[], int nb){
    int i= 0, j= 0, count= 0;
    while(i< na){
        j= 0;
        while(j< nb){
            if(a[i]== b[j]){
                count++;
                break;
            }
            j++;
        }
        i++;
    }
    return count;
}

//Questão 37:
int minInd (int v[], int N){
    int i= 1, index= 0, menor= v[0];
    while(i< N){
        if(v[i]< menor){
            menor= v[i];
            index= i;
        }
        i++;
    }
    return index;
}

//Questão 38:
void somasAc (int v[], int Ac [], int N){
    int i= 0, somas= 0, j= 0;
    while(i< N){
        Ac[j++]= somas +v[i];
        somas+= v[i++];
    }
}

//Questão 39:
int triSup (int N, float m [N][N]){
    int line= 0, column= 0;
    while(line< N){
        while(column< line){
            if(m[line][column]){
                return 0;
            }
            column++;
        }
        line++;
    }
    return 1;
}

//Questão 40:
void transposta (int N, float m [N][N]){
    int line= 0, column= 0, temp;
    while(line< N){
        while(column< line){
            temp= m[line][column];
            m[line][column]= m[column][line];
            m[column][line]= temp;
            column++;
        }
        column= 0;
        line++;
    }
}

//Questão 41:
void addTo (int N, int M, int a [N][M], int b[N][M]){
    int line, column;
    for(line= 0; line< N; line++){
        for(column= 0; column< M; column++) a[line][column]+= b[line][column];
    }
}

//Questão 42:
int unionSet (int N, int v1[N], int v2[N], int r[N]){
    int i= 0, index= 0;
    for(; i< N; i++, index++){
        if(v1[i]== 1 || v2[i]== 1) r[index]= 1;
        else r[index]= 0;
    }
    return index;
}

//Questão 43:
int intersectSet (int N, int v1[N], int v2[N], int r[N]){
    int i= 0, index= 0;
    for(; i< N; i++, index++){
        if(v1[i]== 1 && v2[i]== 1) r[index]= 1;
        else r[index]= 0;
    }
    return index;
}

//Questão 44:
int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
    int i= 0, c= 0;
    for(; i< N; i++, c++){
        if(v1[i]== v2[i]) r[c]= v1[i];
        else if(v1[i]< v2[i]) r[c]= v1[i];
        else r[c]= v2[i];
    }
    return c;
}

//Questão 45:
int unionMSet (int N, int v1[N], int v2[N], int r[N]){
    int i= 0, c= 0;
    for(; i< N; i++, c++){
        if(v1[i]== v2[i]) r[c]= v1[i];
        else if(v1[i]< v2[i]) r[c]= v2[i];
        else r[c]= v1[i];
    }
    return c;
}

//Questão 46:
int cardinalMSet (int N, int v[N]){
    int i= 0, soma= 0;
    for(; i< N; i++){
        soma+= v[i];
    }
    return soma;
}

// Definições para representar as posições e movimentos de um robot
typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
    int x, y;
} Posicao;

//Questão 47:
Posicao posFinal (Posicao inicial, Movimento mov[], int N){
    int i= 0;
    for(; i< N; i++){
        if(mov[i]== Norte) inicial.y++;
        if(mov[i]== Sul) inicial.y--;
        if(mov[i]==Este) inicial.x++;
        if(mov[i]== Oeste) inicial.x--;
    }
    return inicial;
}

//Questão 48:
int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    int i= 0;
    for(; i< N; i++){
        if(final.y< inicial.y){
            mov[i]= Sul; inicial.y--;
        }
        else if(final.y> inicial.y){
            mov[i]= Norte; inicial.y++;
        }
        else break;
    }
    int j= i;
    for(; j< N; j++){
        if(final.x< inicial.x){
            mov[j]= Oeste;
            inicial.x--;
        }
        else if(final.x> inicial.x){
            mov[j]= Este;
            inicial.x++;
        }
        else break;
    }
    if(inicial.x!= final.x || inicial.y!= final.y) return -1;
    else return j;
}

//Questão 49:
int maisCentral (Posicao pos[], int N){
    int menor= abs(pos[0].x) + abs(pos[0].y), central= 0, i= 1;
    for(; i< N; i++){
        int temp= abs(pos[i].x) + abs(pos[i].y);
        if(temp< menor){
            menor= temp;
            central= i;
        }
    }
    return central;
}

//Questão 50:
int vizinhos (Posicao p, Posicao pos[], int N){
    int i= 0, count= 0;
    for(; i< N; i++){
        if((pos[i].x +1== p.x && pos[i].y== p.y) || (pos[i].x -1== p.x && pos[i].y== p.y) || (pos[i].y +1== p.y && pos[i].x== p.x) || (pos[i].y- 1== p.y && pos[i].x== p.x))count++;
    }
    return count;
}

//Tipo para representar listas ligadas de inteiros
typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

//Questão 51:
int length (LInt l){
    int size= 0;
    for(; l; l= l-> prox) size++;
    return size;
}

//Questão 52:
void freeL (LInt l){
    while(l){
        LInt ans= l;
        l= l-> prox;
        free(ans);
    }
}

//Questão 53:
void imprimeL (LInt l){
    while(l){
        printf("%d\n", l-> valor);
        l= l-> prox;
    }
}

//Questão 54:
LInt reverseL (LInt l){
    LInt l1= NULL, l2= NULL;
    while(l){
        l1= l-> prox;
        l-> prox= l2;
        l2= l;
        l= l1;
    }
    l= l2;
    return l;
}

//Questão 55:
void insertOrd (LInt *l, int x){
    for(; *l && (*l)-> valor< x; l= &((*l)-> prox));
    if(!(*l)){
        LInt new= malloc(sizeof(struct lligada));
        new-> valor= x;
        new-> prox= NULL;
        (*l)= new;
    }
    else{
        LInt new= malloc(sizeof(struct lligada));
        new-> valor= x;
        LInt temp= (*l);
        new-> prox= temp;
        (*l)= new;
    }
}

//Questão 56:
int removeOneOrd (LInt *l, int x){
    for(; (*l) && (*l)-> valor!= x; l= &((*l)-> prox));
    if(!(*l)) return 1;
    if((*l)-> valor== x){
        (*l)= (*l)-> prox;
        return 0;
    }
}

//Questão 57:
void mymerge(LInt *r, LInt l1, LInt l2){
    while(l1 && l2){
        if(l1-> valor< l2-> valor){
            (*r)= malloc(sizeof(struct lligada));
            (*r)-> valor= l1-> valor;
            (*r)-> prox= NULL;
            r= &((*r)-> prox);
            l1= l1-> prox;
        }
        else{
            (*r)= malloc(sizeof(struct lligada));
            (*r)-> valor= l2-> valor;
            (*r)-> prox= NULL;
            r= &((*r)-> prox);
            l2= l2-> prox;
        }
    }
    if(!l1) (*r)= l2;
    else (*r)= l1;
}

//Questão 58:
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    for(; l; l= l-> prox){
        if(l-> valor< x){
            *mx= l;
            mx= &((*mx)-> prox);
        }
        else{
            *Mx= l;
            Mx= &((*Mx)-> prox);
        }
    }
    (*mx)= (*Mx)= NULL;
}

//Questão 59:
LInt parteAmeio (LInt *l){
    int size= length(*l)/2;
    LInt lista= NULL, temp= NULL, nodo;
    while(size){
        nodo= malloc(sizeof(struct lligada));
        nodo-> valor= (*l)-> valor;
        nodo-> prox= NULL;
        if(!lista) lista= nodo;
        else{
            LInt temp= lista;
            for(; temp-> prox; temp= temp-> prox);
            temp-> prox= nodo;
        }
        *l= (*l)-> prox;
        size--;
    }
    return lista;
}

//Questão 60:
int removeAll (LInt *l, int x){
    int count= 0;
    while((*l)){
        if((*l)-> valor== x){
            *l= (*l)-> prox;
            count++;
        }
        else l= &((*l)-> prox);
    }
    return count;
}

//Questão 61:
int removeDups (LInt *l){
    int count= 0;
    while((*l)){
        int value= (*l)-> valor;
        l= &((*l)-> prox);
        LInt *aux= l;
        while((*aux)){
            if((*aux)-> valor== value){
                *aux= (*aux)-> prox;
                count++;
            }
            else aux= &((*aux)-> prox);
        }
    }
    return count;
}

//Questão 62:
int removeMaiorL (LInt *l){
    LInt aux= (*l)-> prox, big= (*l);
    int maior=(*l)-> valor;
    for(; aux; aux= aux-> prox){
        if(aux-> valor> maior){
            big= aux;
            maior= aux-> valor;
        }
    }
    for(; (*l)!= big; l=&((*l)-> prox));
    *l= (*l)-> prox;
    return maior;
}

//Questão 63:
void init (LInt *l){
    for(; (*l)-> prox; l= &((*l)-> prox));
    LInt temp= (*l);
    *l= NULL;
    free(temp);
}

//Questão 64:
void appendL (LInt *l, int x){
    for(; (*l); l= &((*l)-> prox));
    LInt nodo= malloc(sizeof(struct lligada));
    nodo-> valor= x;
    nodo-> prox= NULL;
    (*l)= nodo;
}

//Questão 65:
void concatL (LInt *a, LInt b){
    for(; (*a); a= &((*a)-> prox));
    *a= b;
}

//Questão 66:
LInt cloneL (LInt l){
    LInt nodo, lista= NULL, temp= NULL;
    for(; l; l= l-> prox){
        nodo= malloc(sizeof(struct lligada));
        nodo-> valor= l-> valor;
        nodo-> prox= NULL;
        if(!lista) lista= nodo;
        else{
            temp= lista;
            for(; temp-> prox; temp= temp-> prox);
            temp-> prox= nodo;
        }
    }
    return lista;
}

//Questão 67:
LInt cloneRev (LInt l){
    LInt lista= NULL, temp= NULL;
    for(; l; l= l-> prox){
        lista= malloc(sizeof(struct lligada));
        lista-> valor= l-> valor;
        lista-> prox= temp;
        temp= lista;
    }
    return lista;
}

//Questão 68:
int maximo (LInt l){
    int max= l-> valor;
    l= l-> prox;
    for(; l; l= l-> prox){
        if(l-> valor> max) max= l-> valor;
    }
    return max;
}

//Questão 69:
int take (int n, LInt *l){
    int size= 0;
    for(; n && (*l); l= &((*l)-> prox), n--) size++;
    if(!(*l)) return size;
    else{
        while((*l)){
            LInt temp= (*l);
            (*l)= (*l)-> prox;
            free(temp);
        }
        return size;
    }
}

//Questão 70:
int drop (int n, LInt *l){
    int count= 0;
    while(n && (*l)){
        LInt temp= (*l);
        (*l)= (*l)-> prox;
        free(temp);
        count++;
        n--;
    }
    return count;
}

//Questão 71:
LInt NForward (LInt l, int N){
    if(!N) return l;
    return NForward(l-> prox, --N);
}

//Questão 72:
int listToArray (LInt l, int v[], int N){
    if(!l || !N) return 0;
    *v= l-> valor;
    return 1+ listToArray(l-> prox, ++v, --N);
}

//Questão 73:
LInt arrayToList (int v[], int N){
    if(!N) return NULL;
    LInt lista= malloc(sizeof(struct lligada));
    lista-> valor= *v;
    lista-> prox= arrayToList(++v, --N);
    return lista;
}

//Questão 74:
LInt somasAcL (LInt l){
    int soma= 0;
    LInt lista= NULL, nodo= NULL, temp= NULL;
    for(; l; l= l-> prox){
        nodo= malloc(sizeof(struct lligada));
        nodo-> valor= l-> valor + soma;
        soma+= l-> valor;
        nodo-> prox= NULL;
        if(!lista) lista= nodo;
        else{
            temp= lista;
            for(; temp-> prox; temp= temp-> prox);
            temp-> prox= nodo;
        }
    }
    return lista;
}

//Questão 75:
void remreps (LInt l){
    if(l && l-> prox){
        while(l && l-> prox){
            if(l-> valor== l-> prox-> valor){
                LInt temp= l-> prox;
                l-> prox= l-> prox-> prox;
                free(temp);
            }
            else{
                l= l-> prox;
            }
        }
    }
}

//Questão 76:
LInt rotateL (LInt l){
    if(!l || !l-> prox) return l;
    LInt lista= l-> prox, last= l, temp= lista;
    last-> prox= NULL;
    for(; temp-> prox; temp= temp-> prox);
    temp-> prox= last;
    return lista;
}

//Questão 77:
LInt parte (LInt l){
    if(!l || !l-> prox) return NULL;
    LInt pares= l-> prox;
    l-> prox= l-> prox-> prox;
    pares-> prox= parte(l-> prox);
    return pares;
}

//Tipo para representar árvores binárias de inteiros
typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

//Questão 78:
int altura (ABin a){
    if(!a) return 0;
    if(!a-> esq && !a-> dir) return 1;
    int esq= 1+ altura(a-> esq);
    int dir= 1+ altura(a-> dir);
    return esq> dir? esq: dir;
}

//Questão 79:
ABin cloneAB (ABin a){
    if(!a) return NULL;
    ABin clone= malloc(sizeof(struct nodo));
    clone-> valor= a-> valor;
    clone-> esq= cloneAB(a-> esq);
    clone-> dir= cloneAB(a-> dir);
    return clone;
}

//Questão 80:
void mirror (ABin *a){
    if((*a)){
        ABin dir= (*a)-> dir;
        (*a)-> dir= (*a)-> esq;
        (*a)-> esq= dir;
        mirror(&((*a))-> dir);
        mirror(&((*a)-> esq));
    }
}

//Questão 81:
void inorderaux(ABin tree, LInt * list) {
    LInt aux;
    if(tree) {
        inorderaux(tree->dir,list);
        aux = malloc(sizeof(struct lligada));
        aux->valor = tree->valor;
        aux->prox = *list;
        *list = aux;
        inorderaux(tree->esq,list);
    }
}

void inorder (ABin tree, LInt * list) {
    *list = NULL;
    inorderaux(tree,list);
}

//Questão 82:
void preorderaux(ABin a, LInt *l){
    if(a){
        for(; (*l); l= &((*l)-> prox));
        (*l) = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        (*l)->prox = NULL;
        preorderaux(a-> esq, l);
        preorderaux(a-> dir, l);
    }
}

void preorder (ABin a, LInt * l) {
    *l= NULL;
    preorderaux(a, l);
}

//Questão 83:
void posorderaux(ABin a, LInt *l){
    if(a){
        LInt nodo= malloc(sizeof(struct lligada));
        nodo-> valor= a-> valor;
        nodo-> prox= *l;
        *l= nodo;
        posorderaux(a-> dir, l);
        posorderaux(a-> esq, l);
    }
}

void posorder (ABin a, LInt * l) {
    *l= NULL;
    posorderaux(a, l);
}

//Questão 84:
int depth (ABin a, int x){
    if(!a) return -1;
    if(a-> valor== x) return 1;
    int left= depth(a-> esq, x);
    int right= depth(a-> dir, x);
    if(left== -1 && right== -1) return -1;
    if(left== -1) return 1+ right;
    if(right== -1) return 1+ left;
    else{
        return left> right? 1+ right: 1+ left;
    }
}

//Questão 85:
int freeAB (ABin a){
    if(!a) return 0;
    ABin left= a-> esq;
    ABin right= a-> dir;
    free(a);
    return 1+ freeAB(left)+ freeAB(right);
}

//Questão 86:
int pruneAB (ABin *a, int x){
    if(!(*a)) return 0;
    if(!x){
        ABin left= (*a)-> esq, right= (*a)-> dir;
        free((*a));
        *a= left;
        int e= pruneAB(a, x);
        *a= right;
        int d= pruneAB(a, x);
        return 1+ e+ d;
    }
    else{
        return pruneAB(&((*a)-> esq),x- 1)+ pruneAB((&(*a)-> dir), x- 1);
    }
}

//Questão 87:
int iguaisAB (ABin a, ABin b){
    if(!a && ! b) return 1;
    if((!a && b) || (a && !b)) return 0;
    if(a-> valor!= b-> valor) return 0;
    return iguaisAB(a-> esq, b-> esq) && iguaisAB(a-> dir, b-> dir);
}

//Questão 88:
LInt nivelL(ABin a, int n){
    if (!a) return NULL;
    if (n == 1) {
        LInt lista = malloc(sizeof(struct lligada));
        lista->valor = a->valor;
        lista->prox = NULL;
        return lista;
    } else {
        LInt left = nivelL(a->esq, n - 1);
        LInt right = nivelL(a->dir, n - 1);
        concatL(&left, right);
        return left;
    }
}

//Questão 89:
int nivelV (ABin a, int n, int v[]){
    if(!a) return 0;
    if(n== 1){
        *v= a-> valor;
        return 1;
    }
    int e= nivelV(a-> esq, n- 1, v);
    int d= nivelV(a-> dir, n- 1, v+ e);
    return e+ d;
}

//Questão 90:
int dumpAbin (ABin a, int v[], int N){
    if(!a || !N) return 0;
    int e= dumpAbin(a-> esq, v, N);
    if(e< N){
        v[e]= a-> valor;
        return 1+ e+ dumpAbin(a-> dir, v+ e+ 1, N- 1- e);
    }
    else return N;
}

//Questão 91:
int somas(ABin a){
    if(!a) return 0;
    return a-> valor+ somas(a-> esq)+ somas(a-> dir);
}

ABin somasAcA(ABin a){
    if(!a) return NULL;
    ABin new= malloc(sizeof(struct nodo));
    new-> valor= somas(a);
    new-> esq= somasAcA(a-> esq);
    new-> dir= somasAcA(a-> dir);
    return new;
}

//Questão 92:
int contaFolhas (ABin a){
    if(!a) return 0;
    if(!a-> esq && !a-> dir) return 1;
    int right= contaFolhas(a-> dir);
    int left= contaFolhas(a-> esq);
    return left+ right;
}

//Questão 93:
ABin cloneMirror (ABin a){
    if(!a) return NULL;
    ABin new= malloc(sizeof(struct nodo));
    new-> valor= a-> valor;
    new-> dir= cloneMirror(a-> esq);
    new-> esq= cloneMirror(a-> dir);
    return new;
}

//Questão 94:
int addOrd (ABin *a, int x){
    while((*a) && (*a)-> valor!= x){
        if((*a)-> valor> x) a= &((*a)-> esq);
        else a= &((*a)-> dir);
    }
    if(!(*a)){
        ABin nodo= malloc(sizeof(struct nodo));
        nodo-> valor= x;
        nodo-> esq= nodo-> dir= NULL;
        *a= nodo;
        return 0;
    }
    return 1;
}

//Questão 95:
int lookupAB (ABin a, int x){
    while(a && a-> valor!= x){
        if(a-> valor> x) a= a-> esq;
        else a= a-> dir;
    }
    return !a? 0: 1;
}

//Questão 96:
int depthOrd (ABin a, int x){
    int deep= 1;
    while(a && a-> valor!= x){
        if(a-> valor> x) a= a-> esq;
        else a= a-> dir;
        deep++;
    }
    return !a? -1: deep;
}

//Questão 97:
int maiorAB (ABin a){
    if(!a-> dir) return a-> valor;
    return maiorAB(a-> dir);
}

//Questão 98:
void removeMaiorA (ABin *a){
    if(!(*a)-> dir) *a= (*a)-> esq;
    else{
        removeMaiorA(&((*a)-> dir));
    }
}

//Questão 99:
int quantosMaiores (ABin a, int x){
    if(!a) return 0;
    if(a-> valor<= x) return quantosMaiores(a-> dir, x);
    return 1+ quantosMaiores(a-> dir, x)+ quantosMaiores(a-> esq, x);
}

//Questão 100:
void listToBTree (LInt l, ABin *a) {
    if(!l) return;
    ABin new = malloc(sizeof(struct nodo));
    int meio = length(l) / 2;
    LInt temp = l, prev = NULL;
    int i;
    for(i = 0; i < meio; i++) {
        prev = temp;
        temp = temp->prox;
    }
    new->valor = temp->valor;
    new->esq = new->dir = NULL;
    if(prev) prev->prox = NULL;

    if(l != temp) listToBTree(l,&(new->esq));
    if(temp->prox) listToBTree(temp->prox,&(new->dir));
    (*a) = new;
}

//Questão 101:
int deProcuraAux(ABin a, int x, int maior) {
    if(!a) return 1;
    if((maior && a->valor < x) || (!maior && a->valor > x)) return 0;
    return deProcuraAux(a->esq,x,maior) && deProcuraAux(a->dir,x,maior);
}

int deProcura (ABin a) {
    if(!a) return 1;
    int b = deProcuraAux(a->esq,a->valor, 0) && deProcura(a->esq);
    int c = deProcuraAux(a->dir,a->valor, 1) && deProcura(a->dir);
    return b && c;
}
//------------------------------------------------------------------------------------------------------------------------//

int main() {
    return 0;
}
