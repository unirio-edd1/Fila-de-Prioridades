/* Heap binario */
#include "binheapmin.h"

/* Constroi heap vazio */
binHeapMin::binHeapMin(int tamanho)
/* aumenta o tamanho do vetor em uma unidade para iniciar do indice 1 */
: tam(tamanho), vetor(new int[tamanho+1]), n(0)
{}

/* Constroi heap a partir de vetor v */
binHeapMin::binHeapMin(int tamanho, const int * v)
: tam(tamanho), vetor(new int[tamanho+1]), n(tamanho)
{
    for( int i = 0; i < tamanho; i++ )
        vetor[ i + 1 ] = v[ i ];
    constroiHeap( );
}

/* Busca o menor item na fila de prioridades.
 Retorna o menor item em itemMin e true, ou falso se heap vazio */
bool binHeapMin::min(int &itemMin){
    if ( vazia() ){
        cout << "Fila de prioridades vazia!\n";
        return 0;
    }
    itemMin = vetor[1];
    return true;
}

/* Insere item x na fila de prioridade, mantendo a propriedade do heap.
 Eh permitido duplicadas. */
void binHeapMin::insere(const int &x) {
    int dir;
    
    if ( tam == n ){
        cout << "Fila de prioridades cheia!\n";
        return;
    }
    
    /* inicializa sentinela */
    vetor[ 0 ] = x;
    dir = ++n;
    
    /* Refaz heap (sobe elemento) */
    for( ; x < vetor[dir/2]; dir /= 2 )
        vetor[dir] = vetor[ dir/2 ];
    vetor[dir] = x;
}

/* Remove o menor item da fila de prioridades. */
void binHeapMin::removeMin( )
{
    if( vazia( ) ){
        cout << "Fila de prioridades vazia!\n";
        return;
    }
    
    vetor[ 1 ] = vetor[ n-- ];
    refaz( 1 , n );
}


/* Remove o menor item da lista de prioridades e coloca ele em itemMin. */
void binHeapMin::removeMin( int & itemMin )
{
    if( vazia( ) ){
        cout << "Fila de prioridades vazia!";
        return;
    }
    itemMin = vetor[1];
    vetor[ 1 ] = vetor[ n-- ];
    refaz( 1 , n );
}

/* Metodo interno para refazer o heap.
 esq eh o indice de onde inicia o processo para refazer */
void binHeapMin::refaz( int esq, int dir )
{
    int filho;
    int x = vetor[ esq ];
    
    for( ; esq * 2 <= dir; esq = filho )
    {
        filho = esq * 2;
        if( filho != dir && vetor[ filho + 1 ] < vetor[ filho ] )
            filho++;
        if( vetor[ filho ] < x )
            vetor[ esq ] = vetor[ filho ];
        else
            break;
    }
    vetor[ esq ] = x;
}

/* Estabelece a propriedade de ordem do heap a partir de um arranjo arbitrario dos itens. */
void binHeapMin::constroiHeap( )
{
    for( int i = n / 2; i > 0; i-- )
        refaz( i , n);
}

/* Testa se a fila de prioridade estah logicamente vazia.
 Retorna true se vazia, false caso contrario. */
bool binHeapMin::vazia( ) const
{
    return n == 0;
}

/* Faz a lista de prioridades logicamente vazia. */
void binHeapMin::fazVazia( )
{
    n = 0;
}

binHeapMin::~binHeapMin(){
    delete [] vetor;
}

void troca(int&a, int&b){
    int temp = a;
    a = b;
    b = temp;
}

void binHeapMin::heapsort(int n){
    int dir = n;
    
    for (int i = 1; i != dir;) {
        troca(vetor[i], vetor[dir]);
        refaz(i, --dir);
    }
}

void binHeapMin::imprime(){
    for(int i = 1; i<= n; i++)
        cout << vetor[i] << ' ';
    cout << '\n'; 
}