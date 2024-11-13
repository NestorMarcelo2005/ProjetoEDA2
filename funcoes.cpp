#include <iostream>
#include <fstream>
#include "funcoes.h"
#include "submenus.h"
#include "ficheiro.h"

using namespace std;



/**
 * Função que gera o bulhete de cada passageiro e garante que o mesmo é unico
 * @param l1 lista que representa a fila de aviões que estão a se aproximar do aeroporto
 * @param l2 lista que representa a fila de aviões que estão na pista do aeroporto
 * @param l3 lista que representa a fila de aviões que estão a descolar do aeroporto
 * @return retorna o numero de bulhete único
 */
string gerar_numero_bilhete(listas& l1, listas& l2, listas& l3) {
    listas::Item* aux1 = l1.primeiro;
    listas::Item* aux2 = l2.primeiro;
    listas::Item* aux3 = l3.primeiro;
    string numero_bilhete = "TK";
    for (int i = 0; i < 10; ++i) {
        numero_bilhete += to_string(rand() % 10);
    }
    bool numero_existente = true;
    while (numero_existente) {
        numero_existente = false;
        while (aux1 != NULL) {
            passageiro* passageiro_atual = aux1->valor.lista_de_pessoas;
            while (passageiro_atual != NULL) {
                if (numero_bilhete == passageiro_atual->num_bilhete) {
                    numero_bilhete = "TK";
                    for (int j = 0; j < 10; ++j) {
                        numero_bilhete += to_string(rand() % 10);
                    }
                    numero_existente = true;
                    break;
                }
                passageiro_atual = passageiro_atual->proximo;
            }
            if (numero_existente) {
                break;
            }
            aux1 = aux1->next;
        }
        if (!numero_existente) {
            while (aux2 != NULL) {
                passageiro* passageiro_atual = aux2->valor.lista_de_pessoas;
                while (passageiro_atual != NULL) {
                    if (numero_bilhete == passageiro_atual->num_bilhete) {
                        numero_bilhete = "TK";
                        for (int j = 0; j < 10; ++j) {
                            numero_bilhete += to_string(rand() % 10);
                        }
                        numero_existente = true;
                        break;
                    }
                    passageiro_atual = passageiro_atual->proximo;
                }
                if (numero_existente) {
                    break;
                }
                aux2 = aux2->next;
            }
        }
        if (!numero_existente) {
            while (aux3 != NULL) {
                passageiro* passageiro_atual = aux3->valor.lista_de_pessoas;
                while (passageiro_atual != NULL) {
                    if (numero_bilhete == passageiro_atual->num_bilhete) {
                        numero_bilhete = "TK";
                        for (int j = 0; j < 10; ++j) {
                            numero_bilhete += to_string(rand() % 10);
                        }
                        numero_existente = true;
                        break;
                    }
                    passageiro_atual = passageiro_atual->proximo;
                }
                if (numero_existente) {
                    break;
                }
                aux3 = aux3->next;
            }
        }
    }
    return numero_bilhete;
}

/**
 * Função que cria cada passageiro, ou seja, escolhe aleatoriamente, uma nacionalidade, um primeiro e segundo nome e um numero de bilhete, de cada um dos arrays da função lerficheiro e coloca-o na lista ligada correspondente
 * @param nome array em que os elementos são os primeiros nomes de cada passageiro
 * @param nnome inteiro que representa o número de primeiros nomes que existe nesse array, ou seja, dentro do ficheiro
 * @param nsegundo inteiro que representa o número de segundos nomes que existe nesse array, ou seja, dentro do ficheiro
 * @param nnacionalidades inteiro que representa o número de nacionalidades que existe nesse array, ou seja, dentro do ficheiro
 * @param ssegundo_nome array em que os elementos são os segundos nomes de cada passageiro
 * @param nacionalidade array em que os elementos são as nacionalidades de cada passageiro
 * @param pass apontador para a struct passageiro que tem as carateriscas de cada um deles
 * @param l1 lista que representa a fila de aviões que estão a se aproximar do aeroporto
 * @param l2 lista que representa a fila de aviões que estão na pista do aeroporto
 * @param l3 lista que representa a fila de aviões que estão a descolar do aeroporto
 */
passageiro* criapassageiro(string nome[], int& nnome, int& nsegundo, int& nnacionalidades, string ssegundo_nome[], string nacionalidade[], listas& l1, listas& l2, listas& l3) {

    int indice_aleatorio = rand() % nnacionalidades;
    int indice = rand() % nnome;
    int indice2 = rand() % nsegundo;

    string nat = nacionalidade[indice_aleatorio];
    string pnome = nome[indice];
    string snome = ssegundo_nome[indice2];
    string nbilhete = gerar_numero_bilhete(l1, l2, l3);

    passageiro* novo_passageiro = new passageiro;
    novo_passageiro->num_bilhete = nbilhete;
    novo_passageiro->pnome = pnome;
    novo_passageiro->snome = snome;
    novo_passageiro->nacionalidade = nat;
    novo_passageiro->proximo = NULL;

    return novo_passageiro;
}


/**
 * Função que cria cada aviao aleatoriamente que é colocado nas aproximações
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
 * @param avia apontador para a struct aviao que tem as carateriscas de cada aviao
 * @param l1 lista que representa a fila de aviões que estão a se aproximar do aeroporto
 * @param l2 lista que representa a fila de aviões que estão na pista do aeroporto
 * @param l3 lista que representa a fila de aviões que estão a descolar do aeroporto
 * @return retorna um apontador para a struct aviao que adiciona os novos avioes que foram criados à lista ligada correspondente
 */
aviao *cria_aviao(string nome[], int& nnome, int& nsegundo, int& nnacionalidades, string ssegundo_nome[], string nacionalidade[], string voo[], int& nvoo, int& norigem, string origens[], string modelos[], int& nmodelo, int& ndestino, string destinos[],listas& l1, listas& l2, listas& l3,bool aeroporto_aberto) {

    int capacidade = aeroporto_aberto ? (rand() % 11 + 5) : INT_MAX;

    aviao* novo_aviao = new aviao;
    novo_aviao->capacidade = capacidade;
    novo_aviao->destino = "Aeroporto EDA";
    novo_aviao->modelo = modelos[rand() % nmodelo];
    novo_aviao->numero_voo = voo[rand() % nvoo];
    novo_aviao->origem = origens[rand() % norigem];
    novo_aviao->lista_de_pessoas = NULL;
    for (int i = 0; i < capacidade; i++) {
        passageiro* novo_passageiro = criapassageiro(nome, nnome, nsegundo, nnacionalidades, ssegundo_nome, nacionalidade, l1, l2, l3);
        adicionar_passageiro(novo_aviao, novo_passageiro);
    }

    return novo_aviao;

}

/**
 * Função que adiciona passageiros lista ligada
 * @param aviao apontador para a struct aviao
 * @param novo_passageiro apontador para a struct passageiro
 */
void adicionar_passageiro(aviao* aviao, passageiro* novo_passageiro) {
    if (aviao == NULL || novo_passageiro == NULL) {
        return;
    }
    if (aviao->lista_de_pessoas == NULL) {
        aviao->lista_de_pessoas = novo_passageiro;
    } else {
        passageiro* ultimo_passageiro = aviao->lista_de_pessoas;
        while (ultimo_passageiro->proximo != NULL) {
            ultimo_passageiro = ultimo_passageiro->proximo;
        }
        ultimo_passageiro->proximo = novo_passageiro;
    }
}

/**
 * Função que cria um array de 20 objetos do tipo aviao, alocando memória dinamicamente para armazená-los. Em seguida, ela chama a função cria_aviao para preencher cada objeto do array com dados fornecidos como argumentos para a função
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
 * @param l1 lista que representa a fila de aviões que estão a se aproximar do aeroporto
 * @param l2 lista que representa a fila de aviões que estão na pista do aeroporto
 * @param l3 lista que representa a fila de aviões que estão a descolar do aeroporto
 */
void preenche(string nome[], int& nnome, int& nsegundo, int& nnacionalidades, string ssegundo_nome[], string nacionalidade[], string voo[], int& nvoo, int& norigem, string origens[], string modelos[], int& nmodelo, int& ndestino, string destinos[],int j,listas& l1, listas& l2, listas& l3,bool aeroporto_aberto){
    aviao*avia_criado=new aviao[20];
    cria_aviao(nome, nnome, nsegundo, nnacionalidades, ssegundo_nome, nacionalidade, voo, nvoo, norigem, origens, modelos, nmodelo, ndestino, destinos,l1,l2,l3,aeroporto_aberto);
}

/**
 * Função que escreve os aviões que tão a se aproximar
 * @param l lista que representa a fila de aviões que estão a se aproximar do aeroporto
 * @param tamanhoapro int que conta quantos aviões estão a aproximar-se do aeroporto
 */
void escreve(listas &l, int &tamanhoapro) {
    listas::Item* aux = l.primeiro;
    if (!vazia(l)) {
        while (aux != NULL) {
            aux->valor.destino = "Aeroporto EDA";
            cout << "Voo: " << aux->valor.numero_voo << endl;
            cout << "Modelo: " << aux->valor.modelo << endl;
            cout << "Origem: " << aux->valor.origem << endl;
            cout << "Destino: " << aux->valor.destino << endl;
            cout << "Passageiros: "<<endl;
            if (aux->valor.lista_de_pessoas != NULL) {
                passageiro* passageiro_atual = aux->valor.lista_de_pessoas;
                while (passageiro_atual != NULL) {
                    cout << "Nome: "<<passageiro_atual->pnome<<" "<< passageiro_atual->snome << " Nacionalidade: " << passageiro_atual->nacionalidade<<endl;

                    passageiro_atual = passageiro_atual->proximo;
                }

            } else {
                cout << "Nenhum passageiro";
            }

            cout << endl << endl;
            tamanhoapro++;
            aux = aux->next;
        }
    } else {
        cout << "Nenhum aviao a aterrar" << endl;
    }
}

/**
 * Função que imprime a lista de chegada
 * @param tamanhopista int que conta quantos aviões estão na pista do aeroporto
 * @param ndestino inteiro que representa o número de destinos que existe nesse array, ou seja, dentro do ficheiro
 * @param destinos array em que os elementos são os destinos de cada aviao
 * @param nome array em que os elementos são os primeiros nomes de cada passageiro
 * @param nnome inteiro que representa o número de primeiros nomes que existe nesse array, ou seja, dentro do ficheiro
 * @param nsegundo inteiro que representa o número de segundos nomes que existe nesse array, ou seja, dentro do ficheiro
 * @param nnacionalidades inteiro que representa o número de nacionalidades que existe nesse array, ou seja, dentro do ficheiro
 * @param ssegundo_nome array em que os elementos são os segundos nomes de cada passageiro
 * @param nacionalidade array em que os elementos são as nacionalidades de cada passageiro
 * @param l1 lista que representa a fila de aviões que estão nas chegadas do aeroporto
 * @param l2 lista que representa a fila de aviões que estão na pista do aeroporto
 * @param l3 lista que representa a fila de aviões que estão nas partidas do aeroporto
 */
void escreve2( int &tamanhopista, string destinos[], int ndestinos, string nome[], int& nnome, int& nsegundo, int& nnacionalidades, string ssegundo_nome[], string nacionalidade[], listas& l1, listas& l2, listas& l3, passageiro* pass,arvore* &raiz) {
    listas::Item* aux = l2.primeiro;
    raiz=NULL;

     processarAviaoNaPista(l2, nome, nnome, nsegundo, nnacionalidades, ssegundo_nome,  nacionalidade, l1, l3);
    raiz= inserir(l2,raiz);
    if (!vazia(l2)) {
        while (aux != NULL) {
            aux->valor.destino = destinos[rand() % ndestinos];
            aux->valor.origem = "Aeroporto EDA";
            cout << "Voo: " << aux->valor.numero_voo << endl;
            cout << "Modelo: " << aux->valor.modelo << endl;
            cout << "Origem: " << aux->valor.origem << endl;
            cout << "Destino: " << aux->valor.destino << endl;
            cout << "Passageiros: ";

            if (aux->valor.lista_de_pessoas != NULL) {
                passageiro* passageiro_atual = aux->valor.lista_de_pessoas;
                while (passageiro_atual != NULL) {
                    cout << passageiro_atual->pnome << ", ";
                    passageiro_atual = passageiro_atual->proximo;
                }
            } else {
                cout << "Nenhum passageiro";
            }
            cout << endl << endl;
            tamanhopista++;
            aux = aux->next;
        }

    } else {
        cout << "Nenhum aviao na pista" << endl;
    }


}

/**
 * Função que escreve os aviões que tão a descolar
 * @param l3 lista que representa a fila de aviões que estão a descolar do aeroporto
 * @param tamanhodesc int que conta quantos aviões estão na descolagem
 */
void escreve3(listas &l3, int &tamanhodesc) {
    listas::Item* aux = l3.primeiro;
    if (!vazia(l3)) {
        while (aux != NULL) {
            aux->valor.origem = "Aeroporto EDA";
            cout << "Voo: " << aux->valor.numero_voo << endl;
            cout << "Modelo: " << aux->valor.modelo << endl;
            cout << "Origem: " << aux->valor.origem << endl;
            cout << "Destino: " << aux->valor.destino << endl;
            cout << "Passageiros: "<<endl;

            if (aux->valor.lista_de_pessoas != NULL) {
                passageiro* passageiro_atual = aux->valor.lista_de_pessoas;
                while (passageiro_atual != NULL) {
                    cout << "Nome: "<<passageiro_atual->pnome<<" "<< passageiro_atual->snome << " Nacionalidade: " << passageiro_atual->nacionalidade<<endl;
                    passageiro_atual = passageiro_atual->proximo;
                }
            } else {
                cout << "Nenhum passageiro";
            }

            cout << endl << endl;
            tamanhodesc++;
            aux = aux->next;
        }
    } else {
        cout << "Nenhum aviao a descolar" << endl;
    }
}

/**
 * Função que realiza as mudanças entre a aproximação e a pista quando a aproximção tá cheia
 * @param l1 lista que representa a fila de aviões que estão a se aproximar do aeroporto
 * @param l2 lista que representa a fila de aviões que estão na pista do aeroporto
 * @param l3 lista que representa a fila de aviões que estão a descolar do aeroporto
 */
void sai(listas& l1, listas& l2, listas& l3,bool aeroporto_aberto){

    if (!aeroporto_aberto) {
        cout << "Aeroporto fechado. Não é possível transferir aviões." << endl;
        return;
    }

    if (vazia(l1)) {
        cout << "Erro: Lista vazia!" << endl;
        return;
    }

    listas::Item* aux = l1.primeiro;
    l1.primeiro = aux->next;

    if (vazia(l2)) {
        l2.primeiro = aux;
        aux->next = NULL;
    } else {
        int conta = 1;
        listas::Item* ultimo = l2.primeiro;
        while (ultimo->next != NULL && conta < 7) {
            ultimo = ultimo->next;
            conta++;
        }
        if (conta < 7) {
            ultimo->next = aux;
            aux->next = NULL;
        } else {
            conta--;
            sai2(l2, l3,aeroporto_aberto);
        }
    }
}




/**
 * Função que realiza as mudanças entre a pista e a descolagem, quando a pista tá cheia
 * @param l2 lista que representa a fila de aviões que estão na pista do aeroporto
 * @param l3 lista que representa a fila de aviões que estão a descolar do aeroporto
 */
void sai2(listas& l2, listas& l3,bool aeroporto_aberto) {


    if (aeroporto_aberto) {
        if (vazia(l2)) {
            cout << "Erro: Lista vazia!" << endl;
            return;
        }

        int conta = 1;
        listas::Item* aux = l2.primeiro;
        l2.primeiro = aux->next;

        if (vazia(l3)) {
            l3.primeiro = aux;
            aux->next = NULL;
        } else {
            listas::Item* ultimo = l3.primeiro;
            while (ultimo->next != NULL && conta < 5) {
                ultimo = ultimo->next;
                conta++;
            }
            if (conta < 5) {
                ultimo->next = aux;
                aux->next = NULL;
            } else {
                delete aux;
            }
        }
    }
}



/**
 * Função que cria uma lista ligada nova ou esvazia a mesma
 * @param l nome da lista ligada
 */
void Nova(listas& l){
    l.primeiro=NULL;
}
/**
 * Função que cria uma lista ligada nova ou esvazia a mesma, para a struct lista1
 * @param nacio nome da lista ligada
 */
void nova2(lista1&nacio){
    nacio.primeiro=NULL;
}

/**
 * Função que verifica se uma lista ligada tá vazia ou não
 * @param l nome da lista ligada
 * @return retorna true caso a lista ligada teja vazia e false caso contrário
 */
bool vazia (listas &l){
    return (l.primeiro==NULL);
}

/**
 * Função que coloca aviões dentro de cada uma das listas ligadas
 * @param l1 lista que representa a fila de aviões que estão a se aproximar do aeroporto
 * @param l2 lista que representa a fila de aviões que estão na pista do aeroporto
 * @param l3 lista que representa a fila de aviões que estão a descolar do aeroporto
 * @param elemento elemento da struct aviao que é colocado dentro da lista ligada
 */
void entra(listas &l1,listas& l2,listas& l3, aviao elemento,string nome[], int& nnome, int& nsegundo, int& nnacionalidades, string ssegundo_nome[], string nacionalidade[], string voo[], int& nvoo, int& norigem, string origens[], string modelos[], int& nmodelo, int& ndestino, string destinos[],bool aeroporto_aberto){
    listas::Item *novoItem = new listas::Item;
    novoItem->valor = elemento;
    novoItem->next =NULL;

    if (!aeroporto_aberto) {



    } else {

        if (vazia(l1)) {
            l1.primeiro = novoItem;
        } else {
            listas::Item* aux = l1.primeiro;
            int conta = 0;
            while (aux->next != NULL && conta < 9) {
                aux = aux->next;
                conta++;
            }
            if (conta < 9) {
                aux->next = novoItem;
            } else {

                sai(l1, l2, l3,aeroporto_aberto);
                cria_aviao(nome, nnome, nsegundo, nnacionalidades, ssegundo_nome, nacionalidade, voo, nvoo, norigem, origens, modelos, nmodelo, ndestino, destinos,l1,l2,l3,aeroporto_aberto);
                aux->next= novoItem;
            }
        }
    }
}


/**
 * Função que cria as opções de emergencias, passar para o proximo ciclo, opções, gravar e entrar no menu de opções
 * @param l1 lista que representa a fila de aviões que estão a se aproximar do aeroporto
 * @param l2 lista que representa a fila de aviões que estão na pista do aeroporto
 * @param l3 lista que representa a fila de aviões que estão a descolar do aeroporto
 * @param nome array em que os elementos são os primeiros nomes de cada passageiro
 * @param nnome inteiro que representa o número de primeiros nomes que existe nesse array, ou seja, dentro do ficheiro
 * @param nsegundo inteiro que representa o número de segundos nomes que existe nesse array, ou seja, dentro do ficheiro
 * @param nnacionalidades inteiro que representa o número de nacionalidades que existe nesse array, ou seja, dentro do ficheiro
 * @param ssegundo_nome array em que os elementos são os segundos nomes de cada passageiro
 * @param nacionalidade array em que os elementos são as nacionalidades de cada passageiro
 * @param pass apontador para a struct passageiro que tem as carateriscas de cada um deles
 * @param voo array em que os elementos são os numeros de voo de cada aviao
 * @param nvoo inteiro que representa o número de numeros de voo que existe nesse array, ou seja, dentro do ficheiro
 * @param norigem inteiro que representa o número de origens que existe nesse array, ou seja, dentro do ficheiro
 * @param origens array em que os elementos são as origens de cada aviao
 * @param modelos array em que os elementos são os modelos de cada aviao
 * @param nmodelo inteiro que representa o número de modelos que existe nesse array, ou seja, dentro do ficheiro
 * @param ndestino inteiro que representa o número de destinos que existe nesse array, ou seja, dentro do ficheiro
 * @param destinos array em que os elementos são os destinos de cada aviao
 * @param avia apontador para a struct aviao que tem as carateriscas de cada aviao
 * @param argc inteiro que conta a quantidade de argumentos que são passados por argumentos na execução do programa
 * @param argv char que permite acessar os argumentos que são passados por argumentos na execução do programa
 * @param aeroporto_aberto variavel booleana que indica se o aeroporto ta aberto ou fechado
 * @param nacio lista que contém as possiveis nacionalidades de passageiros na pista do aeroporto
 * @param raiz apontador para a raiz da arvore de pesquisa binaria
 */
void opcao(listas &l1,listas&l2,listas&l3,aviao elemento,string nome[], int& nnome, int& nsegundo, int& nnacionalidades, string ssegundo_nome[], string nacionalidade[], passageiro* pass, string voo[], int& nvoo, int& norigem, string origens[], string modelos[], int& nmodelo, int& ndestino, string destinos[], aviao*avia,int argc,char *argv[],bool aeroporto_aberto,lista1 &nacio,arvore*&raiz){
    bool sair =false;
    char op;
    int tamanhoapro = 0;
    int tamanhopista =0;
    int tamanhodesc = 0;
    int ciclo;
    for(int i=0;i<10;i++){
        entra(l1, l2, l3, *cria_aviao(nome, nnome, nsegundo, nnacionalidades, ssegundo_nome, nacionalidade, voo, nvoo, norigem, origens, modelos, nmodelo, ndestino, destinos,l1,l2,l3,aeroporto_aberto),nome, nnome, nsegundo, nnacionalidades, ssegundo_nome, nacionalidade, voo, nvoo, norigem, origens, modelos, nmodelo, ndestino, destinos,aeroporto_aberto);
    }

    cout<<endl;
    cout<<"---------------"<<endl;
    cout<<"Em aproximacao"<<endl;
    cout<<"---------------"<<endl;
    escreve(l1,tamanhoapro);
    cout<< tamanhoapro<<endl;
    cout<<endl;
    cout << "---------------" << endl;
    cout << "Na pista " << endl;
    cout << "---------------" << endl;
    escreve2(tamanhopista,destinos,ndestino,nome,nnome,nsegundo,nnacionalidades,ssegundo_nome,nacionalidade,l1,l2,l3,pass,raiz);
    cout<< tamanhopista<<endl;
    cout << endl;
    cout<<"---------------"<<endl;
    cout<<"A descolar"<<endl;
    cout<<"---------------"<<endl;
    escreve3(l3,tamanhodesc);
    cout<< tamanhodesc<<endl;
    cout<<endl;

    do {
        cout << "ciclo (s)eguinte (e)mergencias (g)ravar (o)pcoes (f)echar"  << endl;
        cout << "Escolha a sua opcao" << endl;
        cin >> op;
        switch (op) {
            case 'e':
                emergencia(l1, l2, l3);
                break;
            case 'o':
                outras(l2,l1,l3 ,nacio,raiz);

                break;
            case 'g':
                grava_aeroporto(l1,l2,l3);
                gravarArvores(raiz);
                break;
            case 's':
                preenche(nome, nnome, nsegundo, nnacionalidades, ssegundo_nome, nacionalidade, voo, nvoo, norigem, origens, modelos, nmodelo, ndestino, destinos,10,l1,l2,l3,aeroporto_aberto);
                menu(l1,l2,l3,nome,nnome,nsegundo,nnacionalidades,ssegundo_nome,nacionalidade,pass,voo,nvoo,norigem,origens,modelos,nmodelo,ndestino,destinos,aeroporto_aberto,raiz);
                break;
            case'f':
                fechar_aeroporto(l1,l2,l3,elemento,ciclo,aeroporto_aberto,tamanhoapro,tamanhopista,tamanhodesc,ndestino,destinos,nnome,nsegundo,nnacionalidades,ssegundo_nome,nacionalidade,voo,nvoo,norigem,origens,modelos,nmodelo,nome,raiz,pass,avia);
                break;
            default:
                cout << "Escolha uma opcao valida." << endl;
        }
    } while (!sair);
}

/**
 * Função que serve para o menu ser chamado sempre que preciso
 * @param l1 lista que representa a fila de aviões que estão a se aproximar do aeroporto
 * @param l2 lista que representa a fila de aviões que estão na pista do aeroporto
 * @param l3 lista que representa a fila de aviões que estão a descolar do aeroporto
 * @param nome array em que os elementos são os primeiros nomes de cada passageiro
 * @param nnome inteiro que representa o número de primeiros nomes que existe nesse array, ou seja, dentro do ficheiro
 * @param nsegundo inteiro que representa o número de segundos nomes que existe nesse array, ou seja, dentro do ficheiro
 * @param nnacionalidades inteiro que representa o número de nacionalidades que existe nesse array, ou seja, dentro do ficheiro
 * @param ssegundo_nome array em que os elementos são os segundos nomes de cada passageiro
 * @param nacionalidade array em que os elementos são as nacionalidades de cada passageiro
 * @param pass apontador para a struct passageiro que tem as carateriscas de cada um deles
 * @param voo array em que os elementos são os numeros de voo de cada aviao
 * @param nvoo inteiro que representa o número de numeros de voo que existe nesse array, ou seja, dentro do ficheiro
 * @param norigem inteiro que representa o número de origens que existe nesse array, ou seja, dentro do ficheiro
 * @param origens array em que os elementos são as origens de cada aviao
 * @param modelos array em que os elementos são os modelos de cada aviao
 * @param nmodelo inteiro que representa o número de modelos que existe nesse array, ou seja, dentro do ficheiro
 * @param ndestino inteiro que representa o número de destinos que existe nesse array, ou seja, dentro do ficheiro
 * @param destinos array em que os elementos são os destinos de cada aviao
 * @param avia apontador para a struct aviao que tem as carateriscas de cada aviao
 */
void menu(listas &l1,listas&l2,listas&l3,string nome[], int& nnome, int& nsegundo, int& nnacionalidades, string ssegundo_nome[], string nacionalidade[], passageiro* pass, string voo[], int& nvoo, int& norigem, string origens[], string modelos[], int& nmodelo, int& ndestino, string destinos[],bool aeroporto_aberto, arvore*&raiz){
    int tamanhoapro = 0;
    int tamanhopista = 0;
    int tamanhodesc = 0;
    entra(l1, l2, l3, *cria_aviao(nome, nnome, nsegundo, nnacionalidades, ssegundo_nome, nacionalidade, voo, nvoo, norigem, origens, modelos, nmodelo, ndestino, destinos, l1,l2,l3, aeroporto_aberto),nome, nnome, nsegundo, nnacionalidades, ssegundo_nome, nacionalidade, voo, nvoo, norigem, origens, modelos, nmodelo, ndestino, destinos,aeroporto_aberto);
    cout<<endl;
    cout<<"---------------"<<endl;
    cout<<"Em aproximacao"<<endl;
    cout<<"---------------"<<endl;
    escreve(l1,tamanhoapro);
    cout<<endl;
    cout << "---------------" << endl;
    cout << "Na pista " << endl;
    cout << "---------------" << endl;
    escreve2(tamanhopista,destinos,ndestino,nome,nnome,nsegundo,nnacionalidades,ssegundo_nome,nacionalidade,l1,l2,l3,pass,raiz);
    cout << endl;
    cout<<"---------------"<<endl;
    cout<<"A descolar"<<endl;
    cout<<"---------------"<<endl;
    escreve3(l3,tamanhodesc);
    cout<<endl;
}





