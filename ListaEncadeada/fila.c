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

typedef struct fila Fila;
struct fila {  
  No *inicio;
  No *fim;
  uint length;
};

Fila *criar_fila() {
  Fila *fila = malloc(sizeof(Fila));
  if(fila) {
      fila->inicio = NULL;
      fila->fim = NULL;
      fila->length = 0;
  }
  return fila;
}

void enfileira(Fila *fila, uint dado) {
  if(!fila) return;
  No *novo = criar_no(dado);
  if(!novo) return;
  if(!fila->fim) {
    fila->fim = novo;
    fila->inicio = novo;
  } else {
    fila->fim->prox = novo;
    fila->fim = novo;
  }
  
  fila->length++;
}

int desinfileira(Fila *fila) {
  if(!fila || fila->length == 0) return -1;
  No *antigo = fila->inicio;
  int valor = fila->inicio->dado;
  fila->inicio = fila->inicio->prox;
  free(antigo);
  if(!fila->inicio) fila->fim = NULL;
  fila->length--;
  return valor;
}

int main(void) {


  return 0;
}