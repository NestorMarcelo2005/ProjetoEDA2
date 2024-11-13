#ifndef PROJECT2_FICHEIRO_H
#define PROJECT2_FICHEIRO_H
#include "funcoes.h"
void lerficheiro(string nome[], string segundo_nome[], int& nnomes, int& nsegundo, string nacionalidade[], int& nnacio, string voo[], int& nvoo, int& norigem, string origens[], string modelos[], int& nmodelo, int& ndestino, string destinos[]);

void grava_aeroporto( listas &l1, listas &l2, listas &l3);

void carregar_aeroporto(listas &l1,listas&l2,listas&l3,aviao elemento,string nome[], int& nnome, int& nsegundo, int& nnacionalidades, string ssegundo_nome[], string nacionalidade[], passageiro* pass, string voo[], int& nvoo, int& norigem, string origens[], string modelos[], int& nmodelo, int& ndestino, string destinos[], aviao*avia,int argc,char *argv[],bool aeroporto_aberto,lista1 &nacio,arvore*&raiz);

void gravarArvores(arvore* raiz);
void gravarArvore(fstream& file, arvore* raiz);
void inserir_passageiro(aviao& aviao, const string& pnome, const string& snome, const string& num_bilhete, const string& nacionalidade);
void opcao2(listas &l1,listas&l2,listas&l3,aviao elemento,string nome[], int& nnome, int& nsegundo, int& nnacionalidades, string ssegundo_nome[], string nacionalidade[], passageiro* pass, string voo[], int& nvoo, int& norigem, string origens[], string modelos[], int& nmodelo, int& ndestino, string destinos[], aviao*avia,int argc,char *argv[],bool aeroporto_aberto,lista1 &nacio,arvore*&raiz);

void inserir2(listas::Item*& aux, const aviao& novo_aviao) ;

















#endif //PROJECT2_FICHEIRO_H
