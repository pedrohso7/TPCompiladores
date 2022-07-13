#include "../headers/simbolo.h"
#include <string.h>

Simbolo* criaSimbolo(char* lexema, Tipo tipo){
    Simbolo* s = (Simbolo *) malloc(sizeof(Simbolo));
    
    if (!s) return NULL;

    s->lexema = lexema;
    s->tipo = tipo;
    s->prox = NULL;

    return s;
}

void imprimeSimbolo(Simbolo* s){
        printf("Endereco: %d, Lexema: %s, Tipo: %s\n", s->enderecoMemoria, s->lexema, retornaNomeTipo(s->tipo));
}

TabelaDeSimbolos* criaTabelaDeSimbolos(){
    TabelaDeSimbolos* t = malloc(sizeof(TabelaDeSimbolos));

    if (!t) return NULL;

    t->prox = NULL;
    t->contador = 0;
    return t;
}

void adicionaSimboloNaTabela(TabelaDeSimbolos* t, char* lexema, Tipo tipo){
    Simbolo *s = criaSimbolo(lexema, tipo);

    if (t->contador == 0) {
        t->prox = s;
        t->contador += 1;
        return;
    }

    Simbolo *atual = t->prox;
    
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = s;
    t->contador += 1;
    return;
}

Simbolo* pegarSimbolo(TabelaDeSimbolos* tabela, char* lexema){
    if (tabela == NULL) { return NULL; }

    SimboloPonteiro atual = tabela->prox;

    while(atual != NULL){
        if (strcmp(atual->lexema,lexema) == 0){
            return atual;
        }

        atual = atual->prox;
    }

    return NULL;
}

int simboloExiste(TabelaDeSimbolos* tabela, char* lexema){
    if (tabela == NULL) { return 0; }

    SimboloPonteiro atual = tabela->prox;

    while(atual != NULL){
        if (strcmp(atual->lexema,lexema) == 0){
            return 1;
        }

        atual = atual->prox;
    }

    return 0;
}


void imprimirTabeladeSimbolos(TabelaDeSimbolos* t){
    // int id = 1;
    Simbolo* atual = t->prox;
    printf("______________________________________________\n");
    printf("_______________Tabela de Símbolos_____________\n");
    printf("_____________ Num. Símbolos = %d _____________\n",t->contador);

    printf("______________________________________________\n");

    while(atual != NULL){
        imprimeSimbolo(atual/*, id*/);
        atual = atual->prox   ;
        // id+=1;
    }
    printf("\n______________________________________________\n");

}

