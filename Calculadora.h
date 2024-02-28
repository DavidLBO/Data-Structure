#ifndef CALCULADORA_H
#define CALCULADORA_H 1

typedef struct calculadora Calculadora;


Calculadora* criar();
void destruir(Calculadora *c);
void exibir(Calculadora *c);
void zerar(Calculadora *c);

void somar(Calculadora *c, float n);
void subtrair(Calculadora *c, float n);
void multiplicar(Calculadora *c, float n);
void dividir(Calculadora *c, float n);

#endif