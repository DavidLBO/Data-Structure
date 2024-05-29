#include <stdio.h>
#include <stdlib.h>

#include "../includes/TADAVL.h"

struct avltree {
  AVLTree *esq;
  AVLTree *dir;
  int dado;
  void (*show)(AVLTree *avltree);
};

void exibir(AVLTree *avltree) {
  if(avltree) printf("(%d)", avltree->dado);
}

AVLTree *novaArvore(int dado) {
  AVLTree *raiz = malloc(sizeof(AVLTree));
  if(raiz) {
    raiz->dir = NULL;
    raiz->esq = NULL;
    raiz->dado = dado;
    raiz->show = exibir;
  }
  return raiz;
}

// a serem implementados
int balancingFactor(AVLTree *avltree) {
  if(!avltree) return 0;
  int avl_dir = height(avltree->dir) +1;
  int avl_esq = height(avltree->esq) +1;
  return(avl_esq - avl_dir);
}
unsigned int height(AVLTree *avltree) {
  if(!avltree) return -1;
  int avl_dir = height(avltree->dir);
  int avl_esq = height(avltree->esq);
  if(avl_esq > avl_dir) {
    return avl_esq +1;
  } else {
    return avl_dir +1;
  }
}
AVLTree *rotateLeft(AVLTree *avltree) {
  AVLTree *aux = avltree->dir;
  avltree->dir = aux->esq;
  aux->esq = avltree;
  return aux->dir;
}
AVLTree *rotateRight(AVLTree *avltree) {
  AVLTree *aux = avltree->esq;
  avltree->esq = aux->dir;
  aux->dir = avltree;
  return aux->esq;
}


// BALANCEAMENTO e VALOR MINIMO
AVLTree *balanceAVL(AVLTree *avltree) {
    int bf = balancingFactor(avltree);
    if (bf > 1) {
        if (balancingFactor(avltree->esq) < 0) {
            avltree->esq = rotateLeft(avltree->esq);
        }
        avltree = rotateRight(avltree);
    } else if (bf < -1) {
        if (balancingFactor(avltree->dir) > 0) {
            avltree->dir = rotateRight(avltree->dir);
        }
        avltree = rotateLeft(avltree);
    }
    return avltree;
}

AVLTree *minValue(AVLTree *node) {
    AVLTree *current = node;
    while (current->esq != NULL)
        current = current->esq;
    return current;
}


// INSERIR
AVLTree *insertNode(AVLTree *avltree, int dado) {
  if(!avltree) return novaArvore(dado);
  if(dado < avltree->dado) {
    avltree->esq = insertNode(avltree->esq, dado);
  } else if (dado > avltree->dado) {
    avltree->dir = insertNode(avltree->dir, dado);
  } else {
    return avltree;
  }
  return balanceAVL(avltree);
}


// DELETE
AVLTree *deleteNode(AVLTree *avltree, int dado){
  if (!avltree) return avltree;
  if (dado < avltree->dado) {
      avltree->esq = deleteNode(avltree->esq, dado);
  } else if (dado > avltree->dado) {
      avltree->dir = deleteNode(avltree->dir, dado);
  } else {
      if ((avltree->esq == NULL) || (avltree->dir == NULL)) {
          AVLTree *temp = avltree->esq ? avltree->esq : avltree->dir;
          if (temp == NULL) {
              temp = avltree;
              avltree = NULL;
          } else {
              *avltree = *temp;
          }
          free(temp);
      } else {
          AVLTree *temp = minValue(avltree->dir);
          avltree->dado = temp->dado;
          avltree->dir = deleteNode(avltree->dir, temp->dado);
      }
  }
  if (!avltree) return avltree;
  return balanceAVL(avltree);
}



// exibir
void preOrder(AVLTree *avltree){
  static AVLTree *primeiro_no = NULL;
  if(primeiro_no == NULL) primeiro_no = avltree;
  if(!avltree) return;
  printf("(%d)", avltree->dado);
  preOrder(avltree->esq);
  preOrder(avltree->dir);
  if(primeiro_no == avltree) {
    printf("\n");
  }
}
void inOrder(AVLTree *avltree) {
  static AVLTree *primeiro_no = NULL;
  if(primeiro_no == NULL) primeiro_no = avltree;
  if(!avltree) return;
  inOrder(avltree->esq);
  printf("(%d)", avltree->dado);
  inOrder(avltree->dir);
  if(primeiro_no == avltree) {
    printf("\n");
  }
}
void posOrder(AVLTree *avltree) {
  static AVLTree *primeiro_no = NULL;
  if(primeiro_no == NULL) primeiro_no = avltree;
  if(!avltree) return;
  posOrder(avltree->esq);
  posOrder(avltree->dir);
  printf("(%d)", avltree->dado);
  if(primeiro_no == avltree) {
    printf("\n");
  }
}

int main() {
  AVLTree *raiz = novaArvore(5);
  raiz = insertNode(raiz, 3);
  raiz = insertNode(raiz, 7);
  raiz = insertNode(raiz, 2);
  raiz = insertNode(raiz, 4);
  raiz = insertNode(raiz, 6);
  raiz = insertNode(raiz, 8);

  printf("preOrder:\n");
  preOrder(raiz);
  printf("\n");

  printf("inOrder:\n");
  inOrder(raiz);
  printf("\n");

  printf("posOrder:\n");
  posOrder(raiz);
  printf("\n");

  raiz = deleteNode(raiz, 7);

  printf("inOrder, sem 7:\n");
  inOrder(raiz);
  printf("\n");
  
  return 0;
}