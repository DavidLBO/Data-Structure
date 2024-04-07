#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

typedef struct no No;
struct no {
  int dado;
  struct no *prox;
};
No *criar_no(int dado) {
  No *no = malloc(sizeof(No));
  if(no) {
    no->dado = dado;
    no->prox = NULL;
  }
  return no;
}

typedef struct pilha Pilha;
struct pilha {  
  No *topo;
  uint length;
};

Pilha *criar_pilha() {
  Pilha *pilha = malloc(sizeof(Pilha));
  if(pilha) {
      pilha->topo = NULL;
      pilha->length = 0;
  }
  return pilha;
}

int topo(Pilha *pilha) {
  if(!pilha || pilha->length == 0) return -1;
  int topo = pilha->topo->dado;
  return topo;
}

void empilhar(Pilha *pilha, uint dado) {
  if(!pilha) return;
  No *no_topo = criar_no(dado);
  if(!no_topo) return;
  pilha->topo = no_topo;
  pilha->topo->prox = no_topo->prox;
  pilha->length++;
}

int pop(Pilha *pilha) {
  if(!pilha || pilha->length == 0) return -1;
  int ex_topo = pilha->topo->dado;
  No *pop = pilha->topo;
  pilha->topo = pilha->topo->prox;
  free(pop);
  return ex_topo;
}

int main(void) {


  return 0;
}