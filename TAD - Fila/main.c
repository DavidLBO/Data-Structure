#include "fila.h"

int main() {
  Fila *f = criarFila(4);

  // espaço para testes das operações criadas pelo aluno
  enfileira(f, 2);
  enfileira(f, 4);
  enfileira(f, 6);
  enfileira(f, 8);

  desenfileira(f);
  desenfileira(f);
  desenfileira(f);
  desenfileira(f);

  liberarFila(f);
  return 0;
}