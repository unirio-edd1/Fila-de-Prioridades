#ifndef BINHEAPMAX_H
#define BINHEAPMAX_H

#include <iostream>
using namespace std;

class binHeapMin{
private:
    int n;               /* Numero de elementos no heap */
    int tam;             /* Tamanho do heap */
    int *vetor;          /* vetor com elementos */
    void refaz(int esq, int dir); /* Refaz condicao do heap */
    void constroiHeap(); /* Constroi heap */
public:
    binHeapMin(int tamanho);                /* Constroi heap vazio */
    binHeapMin(int tamanho, const int * v); /* Constroi heap a partir de vetor nao ordenado */
    ~binHeapMin();
    bool min(int &item);
    void insere(const int &x);        /* Insere x */
    void removeMin();                 /* Remove menor item */
    void removeMin( int & itemMin );  /* Remove e retorna menor item */
    bool vazia() const;               /* Teste se FP vazia */
    void fazVazia();                  /* Remove logicamente todos os itens */
    void heapsort(int n);
    void imprime();
};
#endif