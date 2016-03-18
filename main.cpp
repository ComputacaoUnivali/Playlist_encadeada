#include <iostream>
using namespace std;
#include "musica.h"

int main(){
    // instancia
    TListaEnc<TMusica> playlist;
    // insere
    inserirFimTListaEnc(playlist, TMusica("1- OLOOO","NAO DA ERRO"));
    inserirFimTListaEnc(playlist, TMusica("2- ola","teste"));
    inserirFimTListaEnc(playlist, TMusica("3- hello","test"));
    inserirFimTListaEnc(playlist, TMusica("4- hello 333","test 333"));
    // imprime
    imprimirTListaEnc(playlist);
    cout << endl;
    removePosicaoTListaEnc(playlist, 1);
    inserirPosicaoTListaEnc(playlist, TMusica("Nova", "Ta tranquilo favoravel "), 1);
    // imprime
    imprimirTListaEnc(playlist);
    return 0;
}
