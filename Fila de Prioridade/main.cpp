#include <iostream>
#include <cstdlib>
#include "binheapmin.h"

int main(int argc, char *argv[])
{
    int numItens = 1000;
    int v[10]={3,1,200,43,12,0,78,3,9,1000};
    binHeapMin h(numItens);
    binHeapMin h2(10, v);
    binHeapMin h3(10, v);
    int i, x;
    
    cout << "Insere 1000 inteiros (nao repetidos) no intervalo [0,999], de forma nao ordenada\n";
    for( i = 37; i != 0; i = ( i + 37 ) % numItens )
        h.insere( i );
    h.insere( 0 );
    
    cout << "Remove todos os itens da fila. Os itens sao removidos na ordem 0,1,2,...,999\n";
    for( i = 0; i < numItens; i++ )
    {
        h.removeMin( x );
        if( x != i )
            cout << "Oops! " << i << endl;
    }
    
    cout << "Insere novamente 1000 inteiros.\n";
    for( i = 37; i != 0; i = ( i + 37 ) % numItens )
        h.insere( i );
    h.insere( 0 );
    
    cout << "Tenta inserir na fila cheia.\n";
    h.insere( 0 );
    
    cout << "Testa construcao de heap a partir de vetor.\n";
    for( i = 0; i < 10; i++ )
    {
        h2.removeMin( x );
        cout << x << endl;
    }
    
    cout << "Testa Heapsort em ordem n�o crescente (do maior para o menor).\n";
    h3.heapsort(10);
    h3.imprime();
    
    system("PAUSE");
    return 0;
}