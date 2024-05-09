#include <stdio.h>
#include <stdlib.h>

typedef struct no No;

struct no {
  int dado;
  No *esq;
  No *dir;
};

No *criar_no(int dado) {
  No *no = malloc(sizeof(No));
  if(no) {
    no->dado = dado;
    no->esq = no->dir = NULL;
  }
  return no;
}

void exibir_pre_ordem(No *arvore) {
  static No *primeiro_no = NULL;
  if(primeiro_no == NULL) primeiro_no = arvore;

  if(!arvore) return;
  printf("(%d)", arvore->dado);
  exibir_pre_ordem(arvore->esq);
  exibir_pre_ordem(arvore->dir);

  if(primeiro_no == arvore) {
    printf("\n");
  }
}

void exibir_nos_folha(No *arvore) {
  static No *primeiro_no = NULL;
  if(primeiro_no == NULL) primeiro_no = arvore;
  if(!arvore) return;
  if(arvore->esq == NULL && arvore->dir == NULL){
    printf("(%d)", arvore->dado);

    return;
  }
  exibir_nos_folha(arvore->esq);
  exibir_nos_folha(arvore->dir);
  if(primeiro_no == arvore) {
    printf("\n");
  }

}

void exibir_nos_internos(No *arvore) {
  static No *primeiro_no = NULL;
  if(primeiro_no == NULL) primeiro_no = arvore;
  if(!arvore) return;
  if(arvore->esq != NULL && arvore->dir != NULL)
    printf("(%d)", arvore->dado);
  exibir_nos_internos(arvore->esq);
  exibir_nos_internos(arvore->dir);
  if(primeiro_no == arvore) {
    printf("\n");
  }
}

int total_de_nos(No *arvore) {
  // static int contador;
  // if(arvore != NULL) {
  //     contador++;
  //     total_de_nos(arvore->esq);
  //     total_de_nos(arvore->dir);
  // }
  // return contador;


  if(!arvore) return 0;
  if(!arvore->esq && !arvore->dir) return 1;
  return total_de_nos(arvore->esq) + total_de_nos(arvore->dir) + 1;

}



 //       (5)
 //      /   \
 //   (3)     (8)  
 //  /   \       \
 // (0) (4)     (9)

// AVALIAÇÃO - Questão 04

void exibir_em_ordem(No *arvore) {
  static No *primeiro_no = NULL;
  if(primeiro_no == NULL) primeiro_no = arvore;
  
  if(!arvore) return;

  exibir_em_ordem(arvore->esq);
  
  printf("(%d)", arvore->dado);

  exibir_em_ordem(arvore->dir);
  
  if(primeiro_no == arvore) {
    printf("\n");
  }
}

void exibir_pos_ordem(No *arvore) {
  static No *primeiro_no = NULL;
  if(primeiro_no == NULL) primeiro_no = arvore;

  if(!arvore) return;

  exibir_em_ordem(arvore->esq);

  exibir_em_ordem(arvore->dir);
  
  printf("(%d)", arvore->dado);


  if(primeiro_no == arvore) {
    printf("\n");
  }
}


// AVALIAÇÃO - Questão 03

void inserir_ordenado(No *arvore, int dado) {
  if(!arvore) {
    No *arvore = criar_no(dado);
    return;
  }
  
    if(dado > arvore->dado) {
      if(arvore->dir == NULL) arvore->dir = criar_no(dado);
      inserir_ordenado(arvore->dir, dado);
    } else if (dado < arvore->dado){
      if(arvore->esq == NULL) arvore->esq = criar_no(dado);
      inserir_ordenado(arvore->esq, dado);
    } else if (dado == arvore->dado) {
      return;
    }
  
}

int altura(No *arvore) {
  if(!arvore) return -1;
  static int h = 0;
  
  if(arvore->dir != NULL) {
    h++;
    altura(arvore->dir);
  } else if(arvore->esq != NULL) {
    h++;
    altura(arvore->esq);
  }

  return h;
}

int caminho(No *arvore, int dado) {
  if(!arvore) return -1;
  
  if(caminho(arvore->esq, dado)) {
    printf("(%d)", arvore->dado);
    return 1;
  }
  if(caminho(arvore->dir, dado)) {
    printf("(%d)", arvore->dado);
    return 1;
  }
  if(arvore->dado == dado) return 1;
  
  return 0;
}



int main(void) {
  No *raiz = criar_no(5);
  raiz->esq = criar_no(3);
    raiz->esq->esq = criar_no(0);
    raiz->esq->dir = criar_no(4);
  raiz->dir = criar_no(8);
    raiz->dir->dir = criar_no(9);

  // exibir_pre_ordem(raiz);
  // exibir_nos_folha(raiz);
  // exibir_nos_internos(raiz);
  // printf("%d\n", total_de_nos(raiz));

  // exibir_em_ordem(raiz);
  // exibir_pos_ordem(raiz);

  printf("%d\n", altura(raiz));
  inserir_ordenado(raiz, 7);
  exibir_em_ordem(raiz);
  caminho(raiz, 0);

  

  return 0;
}