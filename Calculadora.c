#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "Calculadora.h"

struct calculadora {
  float memoria;
};

// Criar calculadora
Calculadora* criar(){
  Calculadora* c = (Calculadora*) malloc(sizeof(Calculadora));

  if(c != NULL){
    c->memoria = 0;
  }
  return c;
};

// Destruir calculadora
void destruir(Calculadora * c) {
  free(c);
};

// Exibir calculadora
void exibir(Calculadora *c){
  printf("Memoria: %.2f\n", c->memoria);
};

// Zerar a calculadora
void zerar(Calculadora *c) {
  c->memoria = 0;
};

// Somar
void somar(Calculadora * c, float n) {
  c->memoria += n;
};

// Subtrair
void subtrair(Calculadora * c, float n) {
  c->memoria -= n;
};

// Multiplicar
void multiplicar(Calculadora * c, float n){
  c->memoria *= n;
};

// Dividir
void dividir(Calculadora * c, float n){
  c->memoria /= n;
};