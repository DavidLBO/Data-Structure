#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

struct fila
{
  unsigned int *dados;
  int length;
  int limit;
};

Fila *criarFila(int limit)
{
  Fila *f = malloc(sizeof(Fila));
  if (f == NULL)
    return NULL;
  f->dados = malloc(sizeof(unsigned int) * limit);
  if (f->dados == NULL)
  { // Erro na inicialização da fila
    free(f);
    return;
  }
  f->length = 0;
  f->limit = limit;
  return f;
}

void liberarFila(Fila *f)
{
  free(f->dados);
  free(f);
}

// a ser implementado pelo aluno
// int desenfileira(Fila *f);
// void enfileira(Fila *f, unsigned int dado);

void enfileira(Fila *f, unsigned int dado)
{
  if (f->length < f->limit)
  {
    f->dados[f->length] = dado;
    f->length++;
  }
  else
  {
    printf("Erro, limite atingido!");
  }
  // Para testes:
  // for (int i = 0; i < f->length; i++) {
  //   printf("%d ", f->dados[i]);
  // }
  // printf("\n");
}

int desenfileira(Fila *f) {
  if(f->length == 0) {
    printf("A fila está vazia!");
    return -1;
  }
  int elemento = f->dados[0];
  for(int i = 0; i < f->length - 1; i++) {
    f->dados[i] = f->dados[i+1];
  }
  f->length--;
  // Para testes:
  // for (int i = 0; i < f->length; i++) {
  //   printf("%d ", f->dados[i]);
  // }
  // printf("\n");
  return elemento;
}