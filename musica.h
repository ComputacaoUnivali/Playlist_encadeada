#ifndef MUSICA_H_INCLUDED
#define MUSICA_H_INCLUDED

#include "lista_encadeada.h"

struct TMusica{
    string nome, autor;
    TMusica(){}
    TMusica(string nome, string autor){
        this->nome = nome;
        this->autor = autor;
    }
};

template<typename T>
void imprimirTListaEnc(TListaEnc<T> l){
    TElemento<T> *nav = l.inicio;
    cout << "Musicas:" << endl;
    while ( nav != NULL ) {
        cout << nav->elemento.nome << ": " << nav->elemento.autor << endl;
        nav = nav->prox;
    }
}

#endif
