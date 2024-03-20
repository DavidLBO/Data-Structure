#include "pilha.h"
#include <stdio.h>

int main() {
  Pilha *p = criarPilha(4);

  // espaço para testes das operações criadas pelo aluno
  push(p, 1);
  push(p, 3);

  printf("%d\n", top(p));
  
  push(p, 5);
  push(p, 7);

  printf("%d\n", top(p));

  printf("%d\n", pop(p));
  printf("%d\n", pop(p));
  printf("%d\n", pop(p));
  printf("%d\n", pop(p));

  liberarPilha(p);
  return 0;
}