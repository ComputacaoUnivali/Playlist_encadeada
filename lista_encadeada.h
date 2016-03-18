#ifndef LISTA_ENCADEADA_H_INCLUDED
#define LISTA_ENCADEADA_H_INCLUDED
#include <iostream>
using namespace std;

template<typename T>
struct TElemento{
    T elemento;
    TElemento *prox;
    TElemento(){
        this->elemento = NULL;
        prox = NULL;
    }
    TElemento(T elemento){
        this->elemento = elemento;
        prox = NULL;
    }
};

template<typename T>
struct TListaEnc{
    TElemento<T> *inicio;
    int qtd;
    TListaEnc(){
        inicio = NULL;
        qtd = 0;
    }
};

/// INSERE
template<typename T>
bool inserirInicioTListaEnc(TListaEnc<T> &l, T dado){
    TElemento<T> *novo = new TElemento<T>(dado);
    if ( novo == NULL ) return false;
    novo->prox = l.inicio;
    l.inicio = novo;
    l.qtd++;
    return true;
}

template<typename T>
bool inserirFimTListaEnc(TListaEnc<T> &l, T dado){
	if ( l.qtd == 0 ) return inserirInicioTListaEnc(l, dado);
    TElemento<T> *novo = new TElemento<T>(dado);
    if ( novo == NULL ) return false;
    TElemento<T> *nav = l.inicio;
    while ( nav->prox != NULL )
        nav = nav->prox;
    nav->prox = novo;
    l.qtd++;
    return true;
}
template<typename T>
bool inserirPosicaoTListaEnc(TListaEnc<T> &l, T dado, int pos){
    if ( pos == 0 ) return inserirInicioTListaEnc(l,dado);
    if ( pos == l.qtd) return inserirFimTListaEnc(l,dado);
    if ( pos > l.qtd) return false;
    TElemento<T> *novo = new TElemento<T>(dado);
    if ( novo == NULL ) return false;
    TElemento<T> *nav = l.inicio;
    // anterior da posicao
    for ( int i = 1; i < pos; i++ )
        nav = nav->prox;
    TElemento<T> *proxDeAntes = nav->prox;
    nav->prox = novo;
    novo->prox = proxDeAntes;
    l.qtd++;
    return true;
}

/// REMOVE
template<typename T>
bool removeInicioTListaEnc(TListaEnc<T> &l){
    if ( l.qtd == 0 ) return false;
    TElemento<T> *save = l.inicio;
    l.inicio = save->prox;
    delete save;
    l.qtd--;
    return true;
}
template<typename T>
bool removeFimTListaEnc(TListaEnc<T> &l){
    if ( l.qtd == 0 ) return false;
    if ( l.qtd == 1 ) return removeInicioTListaEnc(l);
    TElemento<T> *nav = l.inicio;
    // penultimo
    while ( nav->prox->prox != NULL )
        nav = nav->prox;
    delete nav->prox;
    nav->prox = NULL;
    l.qtd--;
    return true;
}
template<typename T>
bool removePosicaoTListaEnc(TListaEnc<T> &l, int pos){
    if ( l.qtd == 0 ) return false;
    if ( l.qtd == 1 || pos == 0 ) return removeInicioTListaEnc(l);
    if ( pos >= l.qtd) return false;
    TElemento<T> *nav = l.inicio;
    // anterior da posicao
    for ( int i = 1; i < pos; i++ )
        nav = nav->prox;
    TElemento<T> *remover = nav->prox;
    nav->prox = nav->prox->prox;
    delete remover;
    l.qtd--;
    return true;
}

#endif
