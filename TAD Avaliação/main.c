#include <stdio.h>
#include "Caixa.h"

int main(void) {
  
  Caixa *c = criar_caixa(3, 5, 2);
  exibir_caixa(c);
  area_caixa(c);
  volume_caixa(c);
  liberar_caixa(c);

  return 0;
}