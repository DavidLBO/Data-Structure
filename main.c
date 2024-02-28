#include <stdio.h>
#include "Calculadora.h"

int main(void) {
  
  Calculadora *c = criar();
  exibir(c);
  
  somar(c, 10);
  exibir(c);
  
  subtrair(c, 7);
  exibir(c);

  zerar(c);
  exibir(c);

  somar(c, 20);
  exibir(c);

  multiplicar(c, 5);
  exibir(c);

  dividir(c, 4);
  exibir(c);

  destruir(c);
  
  return 0;
}