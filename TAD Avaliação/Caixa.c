#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "Caixa.h"

struct Caixa {
    float comp;
    float largura;
    float altura;
};

Caixa* criar_caixa(float comp, float largura, float altura) {
    Caixa *c = (Caixa*) malloc(sizeof(Caixa));
    if (c != NULL) {
        c->comp = comp;
        c->largura = largura;
        c->altura = altura;
    }
    return c;
}

void liberar_caixa(Caixa *c) {
    free(c);
}

void exibir_caixa(Caixa *c) {
    printf(
        "Caixa: %.2f de comprimento, %.2f de largura, %.2f de altura\n",
     c->comp, c->largura, c->altura
    );
}

void area_caixa(Caixa *c){
    float area = ((c->comp * c->altura) + (c->largura * c->altura) + (c->comp * c->largura))*2;
    printf("A area da caixa e %.2f!\n", area);
}

void volume_caixa(Caixa *c){
    float volume = c->comp * c->largura * c->altura;
    printf("O volume da caixa e %.2f!\n", volume);
}