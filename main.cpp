#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"
#include "submenus.h"
#include "ficheiro.h"
using namespace std;
/*
    Grupo 6- João Vieira-Nº2107923,Tiago Oliveira Freitas-Nº2131223,Nelson Rodrigues-Nº2143723, Guilherme Basílio-Nº2100123
*/

int main(int argc,char *argv[]) {
    bool aeroporto_aberto=true;
    srand(time(nullptr));
    listas l1,l2,l3;
    lista1 nacio;
    Nova(l3);
    Nova(l2);
    nova2(nacio);


    const int MAX_coisas = 100;
    string nome[MAX_coisas];
    string segundo_nome[MAX_coisas];
    string nacionalidade[MAX_coisas];

    aviao *avia = new aviao;
    passageiro *pass = new passageiro;
    arvore *raiz =new arvore;

    string voo[MAX_coisas];
    string origens[MAX_coisas];
    string modelos[MAX_coisas];
    string destinos[MAX_coisas];
    int nnomes, nsegundo, nnacio, nvoo, norigem, ndestino, nmodelo;
    aviao elemento;
    string nomeFicheiro;
    lerficheiro(nome, segundo_nome, nnomes, nsegundo, nacionalidade, nnacio, voo, nvoo, norigem, origens, modelos,nmodelo, ndestino, destinos);
    cria_lista_nacionalidades(nacionalidade,nnacio,nacio);

    /*if(argc == 2){
        carregar_aeroporto(l1,l2,l3,elemento,nome,nnomes,nsegundo,nnacio,segundo_nome,nacionalidade,pass,voo,nvoo,norigem,origens,modelos,nmodelo,ndestino,destinos,avia,argc,argv,aeroporto_aberto,nacio,raiz);
    }*/
    opcao(l1, l2, l3, elemento, nome, nnomes, nsegundo, nnacio, segundo_nome, nacionalidade, pass, voo, nvoo,norigem, origens, modelos, nmodelo, ndestino, destinos, avia, argc, argv, aeroporto_aberto, nacio, raiz);

    return 0;
}
