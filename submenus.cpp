#include "submenus.h"
#include <iostream>
#include <fstream>
#include "funcoes.h"
#include <iomanip>
using namespace std;
bool aeroporto_aberto = true;
/**
 * Função que irá poder mudar a prioridade dos aviões, em situações de emergência, será completamente implementada no segundo projeto
 * @param l1 lista que representa a fila de aviões que estão a se aproximar do aeroporto
 * @param l2 lista que representa a fila de aviões que estão na pista do aeroporto
 * @param l3 lista que representa a fila de aviões que estão nas partidas
 */
void emergencia(listas &l1, listas &l2, listas &l3) {
    string aterrar, pista;
    listas::Item *aux1;
    listas::Item *aux2;
    listas::Item *val = NULL;
    listas::Item* val2 = NULL;
    int conta;
    int conta2;
    int conta3=0;
    bool encontrouvoo;
    bool encontroupista;

    do {
        aux1 = l1.primeiro;
        conta = 0;
        encontrouvoo = false;

        cout << "Indique o numero do voo que precisa de aterrar de emergencia:" << endl;
        cin >> aterrar;

        while (aux1 != NULL) {
            conta++;
            if (aterrar == aux1->valor.numero_voo) {
                cout << "Voo encontrado" << endl;
                encontrouvoo = true;

                if (conta == 1) {
                    l1.primeiro = aux1->next;
                    val = aux1;
                } else {
                    listas::Item *prev = l1.primeiro;
                    for (int i = 1; i < conta - 1; i++) {
                        prev = prev->next;
                    }
                    prev->next = aux1->next;
                    val = aux1;
                }
                break;
            }
            aux1 = aux1->next;
        }

        if (!encontrouvoo) {
            cout << "Indique um numero de voo valido" << endl;
            continue;
        }
        listas::Item *ler = l2.primeiro;
        conta3 = 0;
        while (ler != NULL) {
            conta3++;
            ler = ler->next;
        }

        if (conta3 == 0) {
            val->next = l2.primeiro;
            l2.primeiro = val;
        } else if (conta3 < 7) {
            ler = l2.primeiro;
            while (ler->next != NULL) {
                ler = ler->next;
            }
            ler->next = val;
            val->next = NULL;
        } else{

            cout << "Indique o numero do voo da pista que deve levantar voo para que o que está em emergencia aterre:"
                 << endl;
            cin >> pista;

            aux2 = l2.primeiro;
            conta2 = 0;
            encontroupista = false;

            while (aux2 != NULL) {
                conta2++;
                if (pista == aux2->valor.numero_voo) {
                    cout << "Voo na pista encontrado" << endl;
                    encontroupista = true;

                    if (conta2 == 1) {
                        l2.primeiro = val;
                        val->next = aux2->next;
                    } else {
                        listas::Item *prev = l2.primeiro;
                        for (int i = 1; i < conta2 - 1; i++) {
                            prev = prev->next;
                        }
                        prev->next = val;
                        val->next = aux2->next;
                    }

                    val2 = aux2;
                    val2->next = NULL;
                    break;
                }
                aux2 = aux2->next;
            }

            if (val2 != NULL) {
                int conta4 = 1;

                if (vazia(l3)) {
                    l3.primeiro = val2;
                } else {
                    listas::Item *ultimo = l3.primeiro;
                    while (ultimo->next != NULL && conta4 < 5) {
                        ultimo = ultimo->next;
                        conta4++;
                    }
                    if (conta4 < 5) {
                        ultimo->next = val2;
                    } else {

                        listas::Item *aux5 = l3.primeiro;
                        l3.primeiro = aux5->next;
                        delete aux5;

                        ultimo = l3.primeiro;
                        while (ultimo->next != NULL) {
                            ultimo = ultimo->next;
                        }
                        ultimo->next = val2;
                    }
                }
                val2->next = NULL;
            }


            if (!encontroupista) {
                cout << "Indique um numero de pista valido" << endl;
            }
        }
    }
    while (!encontrouvoo);

}
/**
 * Função que insere os passageiros que chegam à pista nas arvores de pesquisa binaria
 * @param l2 lista que representa a fila de aviões que estão na pista do aeroporto
 * @param raiz apontador para a raiz da arvore de pesquisa binaria
 * @return retorna a raiz da arvore binaria
 */
arvore* inserir(listas &l2, arvore* raiz) {
    listas::Item* aux = l2.primeiro;

    while (aux != NULL) {//percorre a lista l2, que a é a lista da pista
        passageiro* passageiroAtual = aux->valor.lista_de_pessoas;

        while (passageiroAtual != NULL) {//percorre a lista de passageiros
            if (raiz == NULL) {
                raiz = new arvore();
                raiz->valor = passageiroAtual;// se a arvore tiver vazia define o passageiro atual como nó
                raiz->esquerda = NULL;
                raiz->direita = NULL;
            } else {
                arvore* atual = raiz;
                arvore* pai = nullptr;
                while (atual != NULL) {// percorre a arvore e vê em que lugar deve ser colocado o nome, por causa da nacionalidade e nome
                    pai = atual;
                    if (passageiroAtual->nacionalidade == atual->valor->nacionalidade && passageiroAtual->pnome == atual->valor->pnome) {

                        if (passageiroAtual->pnome < atual->valor->pnome) {
                            atual = atual->esquerda;
                        } else {
                            atual = atual->direita;
                        }
                    } else if (passageiroAtual->nacionalidade == atual->valor->nacionalidade) {
                        if (passageiroAtual->pnome < atual->valor->pnome) {
                            atual = atual->esquerda;
                        } else {
                            atual = atual->direita;
                        }
                    } else {
                        if (passageiroAtual->nacionalidade < atual->valor->nacionalidade) {
                            atual = atual->esquerda;
                        } else {
                            atual = atual->direita;
                        }
                    }
                }
                arvore* novoNo = new arvore();//criação de um nó novo
                novoNo->valor = passageiroAtual;
                novoNo->esquerda = NULL;
                novoNo->direita = NULL;
                //insere o novoNo na posição correta na árvore
                //Se a nacionalidade for igual decide onde ser inserido pelo primeiro nome

                if (passageiroAtual->nacionalidade == pai->valor->nacionalidade && passageiroAtual->pnome == pai->valor->pnome) {
                    if (passageiroAtual->pnome < pai->valor->pnome) {
                        pai->esquerda = novoNo;
                    } else {
                        pai->direita = novoNo;
                    }
                } else if (passageiroAtual->nacionalidade == pai->valor->nacionalidade) {
                    if (passageiroAtual->pnome < pai->valor->pnome) {
                        pai->esquerda = novoNo;
                    } else {
                        pai->direita = novoNo;
                    }
                } else {
                    if (passageiroAtual->nacionalidade < pai->valor->nacionalidade) {
                        pai->esquerda = novoNo;
                    } else {
                        pai->direita = novoNo;
                    }
                }
            }
            passageiroAtual = passageiroAtual->proximo;
        }
        aux = aux->next;
    }

    return raiz;
}

/**
 * Função que cria a lista de nacionalidades, logo quando é rodado o programa
 * @param nacionalidades array em que os elementos são as nacionalidades de cada passageiro
 * @param tamanho inteiro que representa o número de nacionalidades que existe nesse array, ou seja, dentro do ficheiro
 * @param nacio lista que contém as possiveis nacionalidades de passageiros na pista do aeroporto
 */
void cria_lista_nacionalidades(string nacionalidades[], int tamanho, lista1 &nacio) {
    for (int i = 0; i < tamanho; i++) {
        if (nacionalidades[i] == "Portuguese") {
            continue;
        }
        lista1::Item* novo_no = new lista1::Item;
        novo_no->nacionalidade = nacionalidades[i];
        novo_no->next = nullptr;

        if (nacio.primeiro == nullptr) {
            nacio.primeiro = novo_no;
        } else {
            lista1::Item* atual = nacio.primeiro;
            while (atual->next != nullptr) {
                atual = atual->next;
            }
            atual->next = novo_no;
        }
    }
}

/**
 * Função que imprime a arvore binaria
 * @param raiz apontador para a raiz da arvore de pesquisa binaria
 */
void escrever_arvore(arvore *raiz) {
    if (raiz != NULL) {
        escrever_arvore(raiz->esquerda);
        cout << "Nome: " << raiz->valor->pnome << ", Nacionalidade: " << raiz->valor->nacionalidade << endl;
        escrever_arvore(raiz->direita);
    }
}
/**
 * Função que escreve em forma de arvore a arvore binaria
 * @param raiz apontador para a raiz da arvore de pesquisa binaria
 * @param nivel numero de niveis que a arvore binaria contem
 */

void escrever_emformadearvore(arvore *raiz, int nivel = 0) {
    if (raiz != NULL) {
        escrever_emformadearvore(raiz->direita, nivel + 1);
        for (int i = 0; i < nivel; i++) {
            cout << " ->  ";
        }
        cout << raiz->valor->pnome << " (" << raiz->valor->nacionalidade << ")" << endl;
        escrever_emformadearvore(raiz->esquerda, nivel + 1);
    }
}

/**
 * Função que compara a nacionalidade do passageiro que chega com a raiz da arvore e coloca o passageiro no seu sitio
 * @param raiz apontador para a raiz da arvore de pesquisa binaria
 * @param nacionalidade string que é inserida a nacionalidade
 * @return da return para nulo da raiz
 */
arvore* encontrar_nacionalidade(arvore *raiz, const string &nacionalidade) {
    while (raiz != NULL) {
        if (nacionalidade == raiz->valor->nacionalidade) {
            return raiz;
        } else if (nacionalidade <= raiz->valor->nacionalidade) {
            raiz = raiz->esquerda;
        } else {
            raiz = raiz->direita;
        }
    }
    return NULL;
}
/**
 * Função que escreve a sub árvore até encontra me um nacionalidade diferente
 * @param raiz apontador para a raiz da arvore de pesquisa binaria
 * @param nacionalidade string que é inserida a nacionalidade
 * @param nivel número de niveis que a arvore binaria contem
 */
void escrever_subarvore_ate_diferente(arvore *raiz, const string &nacionalidade, int nivel = 0) {
    if (raiz != NULL && raiz->valor->nacionalidade == nacionalidade) {
        escrever_subarvore_ate_diferente(raiz->direita, nacionalidade, nivel + 1);
        for (int i = 0; i < nivel; i++) {
            cout << " ->  ";
        }
        cout << raiz->valor->pnome << " (" << raiz->valor->nacionalidade << ")" << endl;
        escrever_subarvore_ate_diferente(raiz->esquerda, nacionalidade, nivel + 1);
    }
}

/**
 * Função que escreve as subarvores da arvore principal
 * @param raiz apontador para a raiz da arvore de pesquisa binaria
 * @param nacio lista que contem as nacionalidades possiveis de passageiros para a pista
 */
void escrever_subarvore(arvore *raiz,lista1 &nacio) {
    lista1::Item* aux = nacio.primeiro;
    string nacionalidade;
    while(aux!=NULL){
        nacionalidade=aux->nacionalidade;

        arvore *subraiz = encontrar_nacionalidade(raiz, nacionalidade);

        if (subraiz != NULL) {
            cout << "Subarvore para a nacionalidade " << nacionalidade << ":" << endl;
            escrever_subarvore_ate_diferente(subraiz, nacionalidade);
        } else {
            cout << "Nacionalidade " << nacionalidade << " nao encontrada na arvore." << endl;

        }
        cout<<endl;
    aux=aux->next;
    };
}

/**
 * Função que escreve os passageiros que estão em pista
 * @param l2 lista que representa a fila de aviões que estão na pista do aeroporto
 */
void escre_passageiros_es_pista(listas &l2){
    listas::Item*aux=l2.primeiro;
    while(aux!=NULL){
        passageiro* passageiro_atual = aux->valor.lista_de_pessoas;
        while (passageiro_atual != NULL) {
            cout << passageiro_atual->pnome << ", ";
            passageiro_atual = passageiro_atual->proximo;
        }
        aux=aux->next;
    }
}
/**
 * Função que compara nomes
 * @param nome1 string de nome que queremos comparar
 * @param nome2 string de nome que queremos comparar
 * @return retorna o inteiro correspondente à ordem do numero, alfabetica
 */
int comparar_nomes(const string& nome1, const string& nome2) {
    int resultado = nome1.compare(nome2);

    return resultado;
}
/**
 * Função que troca os ponteiros
 * @param a primeiro ponteiro para trocar
 * @param b segundo ponteiro que queremos trocar
 */
void trocar_ponteiros(arvore* &a, arvore* &b) {
    arvore* temp = a;
    a = b;
    b = temp;
}
/**
 * Função que ordena por ordem alfabetica os nodos da arvore
 * @param raiz apontador para a raiz da arvore de pesquisa binaria
 */
void ordenar_por_ordem_alfabetica(arvore* &raiz) {
    if (raiz != nullptr) {
        ordenar_por_ordem_alfabetica(raiz->esquerda);
        arvore* iter = raiz->direita;
        while (iter != nullptr && comparar_nomes(raiz->valor->pnome, iter->valor->pnome) > 0) {
            trocar_ponteiros(raiz, iter);
            iter = raiz->direita;
        }
        ordenar_por_ordem_alfabetica(raiz->direita);
    }
}

/**
 * Função que imprime a nacionalidade e o nome de cda passageiro
 * @param raiz apontador para a raiz da arvore de pesquisa binaria
 */
void imprimir_em_ordem(arvore* raiz) {
    if (raiz != NULL) {
        imprimir_em_ordem(raiz->esquerda);
        cout << "Nacionalidade: " << raiz->valor->nacionalidade << endl;
        cout << "Nome: " << raiz->valor->pnome << endl;
        imprimir_em_ordem(raiz->direita);
    }
}


/**
 * Função que processa os aviões na pista, retira eles da arvore, coloca no aviao e gera novos passageiros
 * @param l2 lista que representa a fila de aviões que estão na pista do aeroporto
 * @param nome array em que os elementos são os primeiros nomes de cada passageiro
 * @param nnome inteiro que representa o número de primeiros nomes que existe nesse array, ou seja, dentro do ficheiro
 * @param nsegundo inteiro que representa o número de segundos nomes que existe nesse array, ou seja, dentro do ficheiro
 * @param nnacionalidades inteiro que representa o número de nacionalidades que existe nesse array, ou seja, dentro do ficheiro
 * @param ssegundo_nome array em que os elementos são os segundos nomes de cada passageiro
 * @param nacionalidade array em que os elementos são as nacionalidades de cada passageiro
 * @param l1 lista que representa a fila de aviões que estão a se aproximar do aeroporto
 * @param l3 lista que representa a fila de aviões que estão a descolar do aeroporto
 */
void processarAviaoNaPista(listas &l2, string nome[], int &nnome, int &nsegundo, int &nnacionalidades, string ssegundo_nome[], string nacionalidade[], listas &l1, listas &l3) {
    listas::Item* aux = l2.primeiro;

    while (aux != nullptr) {
        if (aux->valor.lista_de_pessoas != nullptr && aux->valor.numero_voo != l2.ultimo_numero_voo_processado) {
            passageiro* p = aux->valor.lista_de_pessoas;
            while (p != nullptr) {
                passageiro* temp = p;
                p = p->proximo;
                delete temp;
            }
            aux->valor.lista_de_pessoas = nullptr;

            passageiro* current = nullptr;
            for (int i = 0; i < aux->valor.capacidade; ++i) {
                passageiro* novo = criapassageiro(nome, nnome, nsegundo, nnacionalidades, ssegundo_nome, nacionalidade, l1, l2, l3);
                if (current == nullptr) {
                    aux->valor.lista_de_pessoas = novo;
                } else {
                    current->proximo = novo;
                }
                current = novo;
            }

            l2.ultimo_numero_voo_processado = aux->valor.numero_voo;

            break;
        }
        aux = aux->next;
    }
}

/**
 * Função que conta o numero de nos de uma arvore binaria
 * @param raiz apontador para a raiz da arvore de pesquisa binaria
 * @return retorna um inteiro que representa o numero de nos de uma arvore binaria
 */
int contarNos(arvore* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}
/**
 * Função que realiza uma travessia recursiva na árvore binária, diminuindo o valor de k a cada nó visitado
 * @param raiz apontador para a raiz da arvore de pesquisa binaria
 * @param k Um ponteiro para um inteiro k, que indica o número do nó que queremos encontrar
 * @return Se o nó atual (raiz) for NULL, a função retorna NULL, senao retorna o valor da raiz
 */
arvore* encontrarENo(arvore* raiz, int* k) {
    if (raiz == NULL) {
        return NULL;
    }
    (*k)--;
    if (*k == 0) {
        return raiz;
    }
    arvore* no = encontrarENo(raiz->esquerda, k);
    if (no != NULL) {
        return no;
    }
    return encontrarENo(raiz->direita, k);
}

/**
 * Função que retira por copia nodos das arvores
 * @param raiz apontador para a raiz da arvore de pesquisa binaria
 * @return retorna a raiz da arvore
 */
arvore* removerCopia(arvore* raiz) {
    if (raiz == NULL) {
        return NULL;
    }

    int totalNos = contarNos(raiz);
    if (totalNos == 0) {
        return raiz;
    }

    int aleatorio = rand() % totalNos + 1;

    int k = aleatorio;
    arvore* no = encontrarENo(raiz, &k);

    if (no != NULL) {
        raiz = removerCopia2(raiz, no, NULL);
    }

    return raiz;
}

/**
 * Função axiliar para tirar o nodo por copia da arvore
 * @param raiz apontador para a raiz da arvore de pesquisa binaria
 * @param no apontador para o no que queremos retirar
 * @param ant apontador para o nodo anterior que foi retirado
 * @return retorna a raiz da arvore binaria
 */
arvore* removerCopia2(arvore* raiz, arvore* no, arvore* ant) {
    if (no == NULL) {
        return raiz;
    }

    if (no->esquerda == NULL && no->direita == NULL) { // Nó folha
        if (ant == NULL) { // Removendo a raiz
            free(no);
            return NULL;
        }
        if (ant->esquerda == no) {
            ant->esquerda = NULL;
        } else {
            ant->direita = NULL;
        }
        free(no);
    } else if (no->esquerda == NULL || no->direita == NULL) {
        arvore* filho = no->esquerda ? no->esquerda : no->direita;
        if (ant == NULL) {
            free(no);
            return filho;
        }
        if (ant->esquerda == no) {
            ant->esquerda = filho;
        } else {
            ant->direita = filho;
        }
        free(no);
    } else {
        arvore* sucessor = no->direita;
        arvore* paiSucessor = no;
        while (sucessor->esquerda != NULL) {
            paiSucessor = sucessor;
            sucessor = sucessor->esquerda;
        }
        no->valor = sucessor->valor;
        if (paiSucessor->esquerda == sucessor) {
            paiSucessor->esquerda = sucessor->direita;
        } else {
            paiSucessor->direita = sucessor->direita;
        }
        free(sucessor);
    }

    return raiz;
}



/**
 * Função que permite escolher opção do menu outros
 * @param l2 lista que representa a fila de aviões que estão na pista do aeroporto
 * @param l1 lista que representa a fila de aviões que estão a se aproximar do aeroporto
 * @param l3 lista que representa a fila de aviões que estão a descolar do aeroporto
 * @param lista_de_passageiros apontador para a struct passageiro que tem as carateriscas de cada um deles
 * @param avia apontador para a struct aviao que tem as carateriscas de cada aviao
 * @param nome array em que os elementos são os primeiros nomes de cada passageiro
 * @param nnome inteiro que representa o número de primeiros nomes que existe nesse array, ou seja, dentro do ficheiro
 * @param nsegundo inteiro que representa o número de segundos nomes que existe nesse array, ou seja, dentro do ficheiro
 * @param nnacionalidades inteiro que representa o número de nacionalidades que existe nesse array, ou seja, dentro do ficheiro
 * @param ssegundo_nome array em que os elementos são os segundos nomes de cada passageiro
 * @param nacionalidade array em que os elementos são as nacionalidades de cada passageiro
 * @param voo array em que os elementos são os numeros de voo de cada aviao
 * @param nvoo inteiro que representa o número de numeros de voo que existe nesse array, ou seja, dentro do ficheiro
 * @param norigem inteiro que representa o número de origens que existe nesse array, ou seja, dentro do ficheiro
 * @param origens array em que os elementos são as origens de cada aviao
 * @param modelos array em que os elementos são os modelos de cada aviao
 * @param nmodelo inteiro que representa o número de modelos que existe nesse array, ou seja, dentro do ficheiro
 * @param ndestino inteiro que representa o número de destinos que existe nesse array, ou seja, dentro do ficheiro
 * @param destinos array em que os elementos são os destinos de cada aviao
 * @param nacio lista que contém as possiveis nacionalidades de passageiros na pista do aeroporto
 * @param raiz apontador para a raiz da arvore de pesquisa binaria
 */
void outras(listas &l2,listas &l1,listas &l3,lista1 &nacio, arvore*&raiz) {
    bool sair = true;
    int tamanhoapro = 0;
    int tamanhopista = 0;
    int tamanhodesc = 0;
    char op;
    int ciclo = 1;
        do {
            cout << "(1) Mostrar passageiros em pista" << endl;
            cout << "(2) Ordenar por ordem alfabetica " << endl;
            cout << "(3) Mostrar todos os passageiros em pista em arvore" << endl;
            cout << "(4) Mudar a nacionalidade de um passageiro nas chegadas" << endl;
            cout << "(5) Inverter prioridade"<<endl;
            cout << "(6) pesquisa de passageiro nas chegadas ou partidas"<<endl;
            cout << "(7) sair"<<endl;
            cout << "Escolha a sua opcao" << endl;
            cin >> op;
            switch (op) {
                case '1':
                    cout<<"Passageiros em pista:"<<endl;
                    escre_passageiros_es_pista(l2);
                    cout<<endl;
                    cout<<endl;
                    cout<<"passageiros em arvore: "<<endl;
                    escrever_arvore(raiz);
                    cout<<endl;
                    cout<<endl;
                    escrever_emformadearvore(raiz);
                    break;
                case '2':
                    ordenar_por_ordem_alfabetica( raiz);
                    imprimir_em_ordem( raiz);
                    break;
                case '3':
                    escrever_subarvore(raiz, nacio);
                    break;
                case '4':
                    editarnacionalidade(l1);
                    break;
                case '5':
                    inverterPrioridadePista(l2);
                    break;
                case '6':
                    pesquisa(l1,l3);
                    break;
                case '7':
                    sair = false;
                    break;
                default:
                    cout << "Escolha uma opcao valida." << endl;
            }
        } while (!sair);

}



/**
 * Função que fecha o aeroporto pelo numero de ciclos pedido ao utilizador
 * @param l1 lista que representa a fila de aviões que estão a se aproximar do aeroporto
 * @param l2 lista que representa a fila de aviões que estão na pista do aeroporto
 * @param l3 lista que representa a fila de aviões que estão a descolar do aeroporto
 * @param elemento copia de um elemento da struct aviao
 * @param ciclo inteiro que representa o numero de ciclo em que o aeroporto ficara fechado
 * @param aeroporto_aberto variavel booleana que representa se o aeroporto ta fechado ou aberto
 * @param tamanhoapro inteiro que representa o tamanho das chegadas
 * @param tamanhopista inteiro que representa o tamanho da pista
 * @param tamanhodesc inteiro que representa o tamanho das partidas
 * @param ndestino inteiro que representa o número de destinos que existe nesse array, ou seja, dentro do ficheiro
 * @param destinos array em que os elementos são os destinos de cada aviao
 * @param nome array em que os elementos são os primeiros nomes de cada passageiro
 * @param nnome inteiro que representa o número de primeiros nomes que existe nesse array, ou seja, dentro do ficheiro
 * @param nsegundo inteiro que representa o número de segundos nomes que existe nesse array, ou seja, dentro do ficheiro
 * @param nnacionalidades inteiro que representa o número de nacionalidades que existe nesse array, ou seja, dentro do ficheiro
 * @param ssegundo_nome array em que os elementos são os segundos nomes de cada passageiro
 * @param nacionalidade array em que os elementos são as nacionalidades de cada passageiro
 * @param voo array em que os elementos são os numeros de voo de cada aviao
 * @param nvoo inteiro que representa o número de numeros de voo que existe nesse array, ou seja, dentro do ficheiro
 * @param norigem inteiro que representa o número de origens que existe nesse array, ou seja, dentro do ficheiro
 * @param origens array em que os elementos são as origens de cada aviao
 * @param modelos array em que os elementos são os modelos de cada aviao
 * @param nmodelo inteiro que representa o número de modelos que existe nesse array, ou seja, dentro do ficheiro
 * @param raiz apontador para a raiz da arvore de pesquisa binaria
 * @param pass apontador para a struct passageiro que tem as carateriscas de cada um deles
 * @param avia apontador para a struct aviao que tem as carateriscas de cada aviao
 */

void fechar_aeroporto(listas &l1, listas &l2, listas &l3, aviao elemento, int& ciclo, bool& aeroporto_aberto, int& tamanhoapro, int& tamanhopista, int& tamanhodesc,int& ndestino, string destinos[],int& nnome, int& nsegundo, int& nnacionalidades, string ssegundo_nome[], string nacionalidade[], string voo[], int& nvoo, int& norigem, string origens[], string modelos[], int& nmodelo,string nome[], arvore*&raiz,passageiro*pass,aviao*avia) {
    if (!aeroporto_aberto) {
        cout << "O aeroporto ja esta fechado." << endl;
        return;
    }

    cout << "Quantos ciclos deseja fechar o aeroporto?(max.5) ";
    int numero_de_ciclos;
    cin >> numero_de_ciclos;
    if (numero_de_ciclos > 5) {
        cout << "Numero de ciclos ajustado para 5." << endl;
        numero_de_ciclos = 5;
    }
    bool primeiro_ciclo = true;
    for (int i = 0; i < numero_de_ciclos; ++i) {
        if (!primeiro_ciclo) {
            char resposta;
            cout << "Ciclo (s)eguinte ";
            cin >> resposta;

            if (resposta != 's') {
                cout << "Abortando operacao. Aeroporto sera aberto antes do esperado" << endl;
                cout<< endl;
                return;
            }
        }

        aeroporto_aberto = false;
        entra(l1, l2, l3, elemento,nome, nnome, nsegundo, nnacionalidades, ssegundo_nome, nacionalidade, voo, nvoo, norigem, origens, modelos, nmodelo, ndestino, destinos, aeroporto_aberto);
        cout << endl;
        cout << "Ciclo " << ciclo << " - Aeroporto Fechado:" << endl;

        cout << endl;
        cout << "---------------" << endl;
        cout << "Em aproximacao" << endl;
        cout << "---------------" << endl;
        escreve(l1, tamanhoapro);
        cout << tamanhoapro << endl;
        cout << endl;

        cout << "---------------" << endl;
        cout << "Na pista " << endl;
        cout << "---------------" << endl;
        escreve2(tamanhopista,destinos,ndestino,nome,nnome,nsegundo,nnacionalidades,ssegundo_nome,nacionalidade,l1,l2,l3,pass,raiz);
        cout << tamanhopista << endl;
        cout << endl;

        cout << "---------------" << endl;
        cout << "A descolar" << endl;
        cout << "---------------" << endl;
        escreve3(l3, tamanhodesc);
        cout << tamanhodesc << endl;
        cout << endl;

        ciclo++;
        primeiro_ciclo = false;
        tamanhoapro = 0;
        tamanhopista = 0;
        tamanhodesc = 0;
    }

    cout << "Aeroporto aberto." << endl;
    aeroporto_aberto = true;

    if (tamanhoapro > 10) {
        for (int i = 0; i < 2; ++i) {
            sai(l1, l2, l3, aeroporto_aberto);
        }
    } else {
        sai(l1, l2, l3, aeroporto_aberto);
    }

    cout << endl;
}

/**
 * Função que inverte a pista, troca o primeiro da mesma com o ultimo e assim sucessivamente
 * @param l2 lista que representa a fila de aviões que estão na pista do aeroporto
 */
void inverterPrioridadePista(listas &l2) {
    listas::Item *anter = nullptr;
    listas::Item *current = l2.primeiro;
    listas::Item *next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = anter;
        anter = current;
        current = next;
    }

    l2.primeiro = anter;
    cout<<"Prioridade Invertida com sucesso"<<endl;
}

/**
 * Função que permite pesquisar um passageiro nas chegadas ou partidas
 * @param l1 lista que representa a fila de aviões que estão a se aproximar do aeroporto
 * @param l3 lista que representa a fila de aviões que estão a descolar do aeroporto
 */
void pesquisa(listas &l1, listas &l3) {
    bool encontrou = false;
    while (!encontrou) {
        string pnome, snome, naci;
        cout <<"Pesquise um passageiro entre as chegadas e as partidas: "<<endl;
        cout << "Insira o primeiro nome do passageiro: ";
        cin >> pnome;
        cout << "Insira o segundo nome do passageiro: ";
        cin >> snome;
        cout << "Insira a nacionalidade do passageiro: ";
        cin >> naci;

        listas::Item* aux1 = l1.primeiro;
        while (aux1 != nullptr) {
            passageiro* passageiro_atual = aux1->valor.lista_de_pessoas;
            while (passageiro_atual != nullptr) {
                if (passageiro_atual->pnome == pnome &&
                    passageiro_atual->snome == snome &&
                    passageiro_atual->nacionalidade == naci) {
                    cout << "Informacoes do aviao (chegadas):" << endl;
                    cout << "Numero de voo: " << aux1->valor.numero_voo << endl;
                    cout << "Capacidade do aviao: " << aux1->valor.capacidade << endl;
                    cout << "Modelo: " << aux1->valor.modelo << endl;
                    cout << "Destino: " << aux1->valor.destino << endl;
                    cout << "Origem: " << aux1->valor.origem << endl;
                    cout << endl;
                    cout << "Informacoes do passageiro :" << endl;
                    cout << "Nome: " << passageiro_atual->pnome << " " << passageiro_atual->snome << endl;
                    cout << "Numero Bilhete: " << passageiro_atual->num_bilhete << endl;
                    cout << "Nacionalidade: " << passageiro_atual->nacionalidade << endl;
                    cout << endl;
                    encontrou = true;
                    break;
                }
                passageiro_atual = passageiro_atual->proximo;
            }
            aux1 = aux1->next;
        }

        listas::Item* aux3 = l3.primeiro;
        while (aux3 != nullptr) {
            passageiro* passageiro_atual = aux3->valor.lista_de_pessoas;
            while (passageiro_atual != nullptr) {
                if (passageiro_atual->pnome == pnome &&
                    passageiro_atual->snome == snome &&
                    passageiro_atual->nacionalidade == naci) {
                    cout << "Informacoes do aviao (partidas):" << endl;
                    cout << "Numero de voo: " << aux3->valor.numero_voo << endl;
                    cout << "Capacidade do aviao: " << aux3->valor.capacidade << endl;
                    cout << "Modelo: " << aux3->valor.modelo << endl;
                    cout << "Destino: " << aux3->valor.destino << endl;
                    cout << "Origem: " << aux3->valor.origem << endl;
                    cout << endl;
                    cout << "Informacoes do passageiro:" << endl;
                    cout << "Nome: " << passageiro_atual->pnome << " " << passageiro_atual->snome << endl;
                    cout << "Numero Bilhete: " << passageiro_atual->num_bilhete << endl;
                    cout << "Nacionalidade: " << passageiro_atual->nacionalidade << endl;
                    cout << endl;
                    encontrou = true;
                    break;
                }
                passageiro_atual = passageiro_atual->proximo;
            }
            aux3 = aux3->next;
        }

        if (!encontrou) {
            cout << "Passageiro não encontrado. Deseja tentar novamente? (s/n): ";
            char resposta;
            cin >> resposta;
            if (resposta != 's') {
                break;
            }
        }
    }
}

/**
 * Função que permite editar a nacionalidade de um passageiro das chegadas
 * @param l1 lista que representa a fila de aviões que estão a se aproximar do aeroporto
 */
void editarnacionalidade(listas &l1) {
    bool encontrou = false;
    while (!encontrou) {
        string pnome, snome, naci,nova_naci;
        cout << "Edite a nacionalidade de um passageiro das chegadas "<<endl;
        cout << "Insira o primeiro nome do passageiro: ";
        cin >> pnome;
        cout << "Insira o segundo nome do passageiro: ";
        cin >> snome;
        cout << "Insira a nacionalidade atual do passageiro: ";
        cin >> naci;
        cout << "Insira a nova nacionalidade para o passageiro: ";
        cin >> nova_naci;
        listas::Item* aux1 = l1.primeiro;
        while (aux1 != nullptr) {
            passageiro* passageiro_atual = aux1->valor.lista_de_pessoas;
            while (passageiro_atual != nullptr) {
                if (passageiro_atual->pnome == pnome &&
                    passageiro_atual->snome == snome &&
                    passageiro_atual->nacionalidade == naci) {
                    encontrou = true;
                    passageiro_atual->nacionalidade = nova_naci;
                    cout << "Nacionalidade do passageiro alterada com sucesso!" << endl;
                    break;
                }
                passageiro_atual = passageiro_atual->proximo;
            }
            aux1 = aux1->next;
        }

        if (!encontrou) {
            cout << "Passageiro nao encontrado. Deseja tentar novamente? (s/n): ";
            char resposta;
            cin >> resposta;
            if (resposta != 's') {
                break;
            }
        }
    }
}
