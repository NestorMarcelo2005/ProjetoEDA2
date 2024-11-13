//
// Created by nelso on 27/04/2024.
//
#include <iostream>
#include "funcoes.h"
#include "ficheiro.h"

#ifndef PROJETO2_SUBMENUS_H
#define PROJETO2_SUBMENUS_H

using namespace std;

void fechar_aeroporto(listas &l1, listas &l2, listas &l3, aviao elemento, int& ciclo, bool& aeroporto_aberto, int& tamanhoapro, int& tamanhopista, int& tamanhodesc,int& ndestino, string destinos[],int& nnome, int& nsegundo, int& nnacionalidades, string ssegundo_nome[], string nacionalidade[], string voo[], int& nvoo, int& norigem, string origens[], string modelos[], int& nmodelo,string nome[], arvore*&raiz,passageiro*pass,aviao*avia);

void emergencia(listas &l1, listas &l2, listas &l3);


void outras(listas &l2,listas &l1,listas &l3,lista1 &nacio, arvore*&raiz);

void cria_lista_nacionalidades(string nacionalidades[], int tamanho, lista1 &nacio);
void escrever_subarvore(arvore *raiz,lista1 &nacio);

void escre_passageiros_es_pista(listas &l2);

void pesquisa(listas &l1, listas &l3);
void editarnacionalidade(listas &l1);

arvore* removerCopia2(arvore* raiz, arvore* no, arvore* ant);


arvore* inserir(listas &l2, arvore* raiz);

void inverterPrioridadePista(listas &l2);

void processarAviaoNaPista(listas &l2, string nome[], int &nnome, int &nsegundo, int &nnacionalidades, string ssegundo_nome[], string nacionalidade[], listas &l1, listas &l3);

#endif //PROJETO2_SUBMENUS_H
