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

typedef struct lista Lista;
struct lista {
  No *inicio;
  No *fim;
  uint length;
};

Lista *criar_lista() {
  Lista *lista = malloc(sizeof(Lista));
  if(lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->length = 0;
  }
  return lista;
}

void inserir_inicio(Lista *lista, int dado) {
  if(!lista) return;
  No *inicio = criar_no(dado);
  if(!inicio) return;
  inicio->prox = lista->inicio;
  lista->inicio = inicio;
  if(lista->fim == NULL) lista->fim = inicio;
  lista->length++;
}

void inserir_fim(Lista *lista, int dado) {
  if(!lista) return;
  No *fim = criar_no(dado);
  if(!fim) return;
  if(!lista->fim) {
    lista->fim = fim;
    lista->inicio = fim;
  } else {
    lista->fim->prox = fim;
    lista->fim = fim;
  }
  lista->length++;
}


void inserir_ordenado(Lista **lista, int dado) {
  // Tentei fazer com auxilio de um tutorial da internet
  No *aux, *novo = malloc(sizeof(Lista));
  if(!novo) return;
  novo->dado = dado;

  if(*lista == NULL){ 
      novo->prox = NULL;
      (*lista)->inicio = novo;
  }
  else if(novo->dado < (*lista)->inicio->dado){ 
      novo->prox = (*lista)->inicio;
      (*lista)->inicio = novo;
  }
  else{
      aux = (*lista)->inicio;
      while(aux->prox && novo->dado > aux->prox->dado)
          aux = aux->prox;
      novo->prox = aux->prox;
      aux->prox = novo;
  }

  (*lista)->length++;
}

void deletar_inicio(Lista *lista) {
  if(!lista || lista->length == 0) return;
  No *antigo = lista->inicio;
  lista->inicio = lista->inicio->prox;
  free(antigo);
  if(!lista->inicio) lista->fim = NULL;
  lista->length--;
}

void deletar_fim(Lista *lista) {
  if(!lista || lista->length == 0) return;
  No *antigo = lista->fim;
  lista->fim = NULL;
  free(antigo);
  lista->length--;
}

int main(void) {
  
  
  return 0;
}