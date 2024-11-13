//
// Created by joaot on 16/04/2024.
//
#ifndef AVIAO_FUNCOES_H
#define AVIAO_FUNCOES_H
#include <iostream>
using namespace std;

struct passageiro {
    string num_bilhete;
    string pnome;
    string snome;
    string nacionalidade;
    passageiro* proximo;
};

struct aviao {
    string numero_voo;
    string modelo;
    string origem;
    string destino;
    int capacidade;

    passageiro *lista_de_pessoas;
};


struct listas {
    struct Item {
        aviao valor;
        Item*next;
    };
    string ultimo_numero_voo_processado;
    Item*primeiro;
};

struct lista1 { ;
    struct Item{
        string nacionalidade;
        Item *next;
    };
    Item*primeiro;

};

struct arvore{
    passageiro*valor;
    arvore*esquerda;
    arvore*direita;
};

void opcao(listas &l1,listas&l2,listas&l3,aviao elemento,string nome[], int& nnome, int& nsegundo, int& nnacionalidades, string ssegundo_nome[], string nacionalidade[], passageiro* pass, string voo[], int& nvoo, int& norigem, string origens[], string modelos[], int& nmodelo, int& ndestino, string destinos[], aviao*avia,int argc,char *argv[],bool aeroporto_aberto,lista1 &nacio,arvore*&raiz);





passageiro* criapassageiro(string nome[], int& nnome, int& nsegundo, int& nnacionalidades, string ssegundo_nome[], string nacionalidade[], listas& l1, listas& l2, listas& l3);
aviao *cria_aviao(string nome[], int& nnome, int& nsegundo, int& nnacionalidades, string ssegundo_nome[], string nacionalidade[], string voo[], int& nvoo, int& norigem, string origens[], string modelos[], int& nmodelo, int& ndestino, string destinos[],listas& l1, listas& l2, listas& l3,bool aeroporto_aberto);
void preenche(string nome[], int& nnome, int& nsegundo, int& nnacionalidades, string ssegundo_nome[], string nacionalidade[], string voo[], int& nvoo, int& norigem, string origens[], string modelos[], int& nmodelo, int& ndestino, string destinos[],int j,listas& l1, listas& l2, listas& l3,bool aeroporto_aberto);
void Nova(listas& l);
void nova2(lista1&nacio);
bool vazia (listas &l);

void escreve(listas &l,int &tamanhoapro);
void escreve2( int &tamanhopista, string destinos[], int ndestinos,  string nome[], int& nnome, int& nsegundo, int& nnacionalidades, string ssegundo_nome[], string nacionalidade[], listas& l1, listas& l2, listas& l3, passageiro* pass,arvore* &raiz) ;
void escreve3(listas &l3,int &tamanhodesc);

void entra(listas &l1,listas& l2,listas& l3, aviao elemento,string nome[], int& nnome, int& nsegundo, int& nnacionalidades, string ssegundo_nome[], string nacionalidade[], string voo[], int& nvoo, int& norigem, string origens[], string modelos[], int& nmodelo, int& ndestino, string destinos[],bool aeroporto_aberto);

void sai(listas& l1, listas& l2, listas& l3,bool aeroporto_aberto);
void sai2(listas& l2, listas& l3,bool aeroporto_aberto);


void menu(listas &l1,listas&l2,listas&l3,string nome[], int& nnome, int& nsegundo, int& nnacionalidades, string ssegundo_nome[], string nacionalidade[], passageiro* pass, string voo[], int& nvoo, int& norigem, string origens[], string modelos[], int& nmodelo, int& ndestino, string destinos[],bool aeroporto_aberto, arvore*&raiz);


string gerar_numero_bilhete(listas& l1, listas& l2, listas& l3);



void adicionar_passageiro(aviao* aviao, passageiro* novo_passageiro);





#endif //AVIAO_FUNCOES_H
