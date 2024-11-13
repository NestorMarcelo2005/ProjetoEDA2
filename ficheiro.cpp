#include "funcoes.h"
#include "submenus.h"
#include "ficheiro.h"
#include <iostream>
#include <fstream>
using namespace std;
/**
 * Função que lê os ficheiros dos primeiros nomes,segundos nomes, nacionalidades, numero de voo, origem,destino e modelo e coloca-os dentro de um array estatico
 * @param nome array em que os elementos são os primeiros nomes de cada passageiro
 * @param segundo_nome array em que os elementos são os segundos nomes de cada passageiro
 * @param nnomes inteiro que representa o número de primeiros nomes que existe nesse array, ou seja, dentro do ficheiro
 * @param nsegundo inteiro que representa o número de segundos nomes que existe nesse array, ou seja, dentro do ficheiro
 * @param nacionalidade array em que os elementos são as nacionalidades de cada passageiro
 * @param nnacio inteiro que representa o número de nacionalidades que existe nesse array, ou seja, dentro do ficheiro
 * @param voo array em que os elementos são os numeros de voo de cada aviao
 * @param nvoo inteiro que representa o número de numeros de voo que existe nesse array, ou seja, dentro do ficheiro
 * @param norigem inteiro que representa o número de origens que existe nesse array, ou seja, dentro do ficheiro
 * @param origens array em que os elementos são as origens de cada aviao
 * @param modelos array em que os elementos são os modelos de cada aviao
 * @param nmodelo inteiro que representa o número de modelos que existe nesse array, ou seja, dentro do ficheiro
 * @param ndestino inteiro que representa o número de destinos que existe nesse array, ou seja, dentro do ficheiro
 * @param destinos array em que os elementos são os destinos de cada aviao
 */
void lerficheiro(string nome[],string segundo_nome[], int& nnomes, int& nsegundo,string nacionalidade[],int& nnacio,string voo[],int& nvoo,int& norigem,string origens[],string modelos[],int& nmodelo,int& ndestino,string destinos[]) {
    const int MAX_nomes = 100;
    const int MAX_segundonome = 100;
    const int MAX_nacionalidade = 100;
    const int MAX_voo = 100;
    const int MAX_origem = 100;
    const int MAX_modelo = 100;
    const int MAX_destino = 100;
    string linha;

    fstream ficheiropnomes("primeiro_nome.txt", ios::in);
    if (ficheiropnomes.is_open()) {
        while (getline(ficheiropnomes, linha)) {
            if (nnomes < MAX_nomes) {
                nome[nnomes++] = linha;
            }
        }
        ficheiropnomes.close();
    } else {
        cerr << "deu erro ao abrir o ficheiro de marcas" << endl;
    }
    fstream ficheirosnomes("segundo_nome.txt", ios::in);
    if (ficheirosnomes.is_open()) {
        while (getline(ficheirosnomes, linha)) {
            if (nsegundo < MAX_segundonome) {
                segundo_nome[nsegundo++] = linha;
            }
        }
        ficheirosnomes.close();
    } else {
        cerr << "deu erro ao abrir o ficheiro de marcas" << endl;
    }

    fstream ficheirosnacio("nacionalidade.txt", ios::in);
    if (ficheirosnacio.is_open()) {
        while (getline(ficheirosnacio, linha)) {
            if (nnacio < MAX_nacionalidade) {
                nacionalidade[nnacio++] = linha;
            }
        }
        ficheirosnacio.close();
    } else {
        cerr << "deu erro ao abrir o ficheiro de marcas" << endl;
    }
    fstream ficheirovoo("voo.txt", ios::in);
    if (ficheirovoo.is_open()) {
        while (getline(ficheirovoo, linha)) {
            if (nvoo < MAX_voo) {
                voo[nvoo++] = linha;
            }
        }
        ficheirovoo.close();
    } else {
        cerr << "deu erro ao abrir o ficheiro de marcas" << endl;
    }


    fstream ficheirori("origem.txt", ios::in);
    if (ficheirori.is_open()) {
        while (getline(ficheirori, linha)) {
            if (norigem < MAX_origem) {
                origens[norigem++] = linha;
            }
        }
        ficheirori.close();
    } else {
        cerr << "deu erro ao abrir o ficheiro de marcas" << endl;
    }

    fstream ficheirodestino("destino.txt", ios::in);
    if (ficheirodestino.is_open()) {
        while (getline(ficheirodestino, linha)) {
            if (ndestino < MAX_destino) {
                destinos[ndestino++] = linha;
            }
        }
        ficheirodestino.close();
    } else {
        cerr << "deu erro ao abrir o ficheiro de marcas" << endl;
    }
    fstream ficheiromodelos("modelo.txt", ios::in);
    if (ficheiromodelos.is_open()) {
        while (getline(ficheiromodelos, linha)) {
            if (nmodelo < MAX_modelo) {
                modelos[nmodelo++] = linha;
            }
        }
        ficheiromodelos.close();
    } else {
        cerr << "deu erro ao abrir o ficheiro de marcas" << endl;
    }
}


/**
 * Função que grava o aeroporto EDA num txt
 * @param l1 lista que representa a fila de aviões que estão a se aproximar do aeroporto
 * @param l2 lista que representa a fila de aviões que estão na pista do aeroporto
 * @param l3 lista que representa a fila de aviões que estão a descolar do aeroporto
 */
void grava_aeroporto( listas &l1, listas &l2, listas &l3) {
    string nomeFicheiro = "aeroporto.txt";
    listas::Item *aux1 = l1.primeiro;
    listas::Item *aux2 = l2.primeiro;
    listas::Item *aux3 = l3.primeiro;
    int tamanhoapro = 0;
    int tamanhopista = 0;
    int tamanhodesc = 0;
    while (aux1 != NULL) {
        tamanhoapro++;
        aux1 = aux1->next;
    }
    while (aux2 != NULL) {
        tamanhopista++;
        aux2 = aux2->next;
    }
    while (aux3 != NULL) {
        tamanhodesc++;
        aux3 = aux3->next;
    }
    aux1 = l1.primeiro;
    aux2 = l2.primeiro;
    aux3 = l3.primeiro;
    fstream file(nomeFicheiro, ios::out);
    if (file.is_open()) {//percorre cada lista com um apontador para o inicio, depois grava os passageiros e os avioes
        file << tamanhoapro << endl;
        file << tamanhopista << endl;
        file << tamanhodesc << endl;
        if (!vazia(l1)) {
            while (aux1 != NULL) {
                file << aux1->valor.numero_voo << endl;
                file << aux1->valor.origem << endl;
                file << aux1->valor.destino << endl;
                file << aux1->valor.modelo <<endl;
                file << aux1->valor.capacidade << endl;
                if (aux1->valor.lista_de_pessoas != NULL) {
                    passageiro* passageiro_atual = aux1->valor.lista_de_pessoas;
                    while (passageiro_atual != NULL) {
                        file << passageiro_atual->pnome << endl;
                        file << passageiro_atual->snome << endl;
                        file << passageiro_atual->num_bilhete << endl;
                        file << passageiro_atual->nacionalidade << endl;
                        passageiro_atual = passageiro_atual->proximo;
                    }
                }
                aux1 = aux1->next;
            }
            while (aux2 != NULL) {
                file << aux2->valor.numero_voo << endl;
                file << aux2->valor.origem << endl;
                file << aux2->valor.destino << endl;
                file << aux2->valor.modelo <<endl;
                file << aux2->valor.capacidade << endl;
                if (aux2->valor.lista_de_pessoas != NULL) {
                    passageiro* passageiro_atual = aux2->valor.lista_de_pessoas;
                    while (passageiro_atual != NULL) {
                        file << passageiro_atual->pnome << endl;
                        file << passageiro_atual->snome << endl;
                        file << passageiro_atual->num_bilhete << endl;
                        file << passageiro_atual->nacionalidade << endl;
                        passageiro_atual = passageiro_atual->proximo;
                    }
                }
                aux2 = aux2->next;
            }
            while (aux3 != NULL) {
                file << aux3->valor.numero_voo << endl;
                file << aux3->valor.origem << endl;
                file << aux3->valor.destino << endl;
                file << aux3->valor.modelo <<endl;
                file << aux3->valor.capacidade << endl;
                if (aux3->valor.lista_de_pessoas != NULL) {
                    passageiro* passageiro_atual = aux3->valor.lista_de_pessoas;
                    while (passageiro_atual != NULL) {
                        file << passageiro_atual->pnome << endl;
                        file << passageiro_atual->snome << endl;
                        file << passageiro_atual->num_bilhete << endl;
                        file << passageiro_atual->nacionalidade << endl;
                        passageiro_atual = passageiro_atual->proximo;
                    }
                }
                aux3 = aux3->next;
            }

        } else {
            cerr << "ERRO AO ESCREVER NO FICHEIRO" << endl;
        }
        file.close();
        cout << "Dados do aeroporto gravados com sucesso" << endl;
    }
}

/**
 * Função que insere passageiros
 * @param aviao referencia para a struct aviao
 * @param pnome string do primeiro nome de cada passageiro
 * @param snome string do segundo nome de cada passageiro
 * @param num_bilhete string do bilhete de cada passageiro
 * @param nacionalidade string da nacionalidade de cada passageiro
 */
void inserir_passageiro(aviao& aviao, const string& pnome, const string& snome, const string& num_bilhete, const string& nacionalidade) {
    passageiro* novo_passageiro = new passageiro{num_bilhete, pnome, snome, nacionalidade, nullptr};//cria um novo passageiro

    if (aviao.lista_de_pessoas == nullptr) {//verifica se a lista ta vazia
        aviao.lista_de_pessoas = novo_passageiro;
    } else {
        passageiro* passageiro_atual = aviao.lista_de_pessoas;//cria um apontador para passageiro
        while (passageiro_atual->proximo != nullptr) { //passa o passageiro até ao fim da lista
            passageiro_atual = passageiro_atual->proximo; //coloca o passageiro na lista
        }
        passageiro_atual->proximo = novo_passageiro;
    }
}

/**
 * Função que insere os avioes na lista ligada
 * @param aux auxiliar para percorrer cada lista ligada
 * @param novo_aviao referencia para a struct aviao
 */
void inserir2(listas::Item*& aux, const aviao& novo_aviao) {//insere avioes na lista de avioes
    listas::Item* novo_item = new listas::Item{novo_aviao, aux};
    aux = novo_item;
}

/**
 * Função que grava a arvore binaria
 * @param file variavel que indica o nome do ficheiro que será gravado
 * @param raiz apontador para a raiz da arvore binaria
 */
void gravarArvore(fstream& file, arvore* raiz) {
    if (raiz == nullptr) {
        return;
    }
    gravarArvore(file, raiz->esquerda);//grava a parte esquerda da subarvore primeiro com uma chamada recursiva
    file << raiz->valor->nacionalidade << endl;
    file << raiz->valor->pnome <<endl;
    file << raiz->valor->snome <<endl;
    file << raiz->valor->num_bilhete << endl;
    gravarArvore(file, raiz->direita);//grava a parte direita da subarvore depois com uma chamda recursiva
}
/**
 * Função que auxilia a anterior, abre e fecha o ficheiro
 * @param raiz apontador para a raiz da arvore binaria
 */
void gravarArvores(arvore* raiz) {
    string nomeFicheiro = "arvores.txt";
    fstream file(nomeFicheiro, ios::out);
    if (file.is_open()) {
        gravarArvore(file, raiz);
        file.close();
        cout << "Dados da árvore gravados com sucesso" << endl;
    } else {
        cerr << "ERRO AO ABRIR O FICHEIRO" << endl;
    }
}

/**
 * Função parecida à opção, mas esta serve para ser usada depois do carregar
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
void opcao2(listas &l1,listas&l2,listas&l3,aviao elemento,string nome[], int& nnome, int& nsegundo, int& nnacionalidades, string ssegundo_nome[], string nacionalidade[], passageiro* pass, string voo[], int& nvoo, int& norigem, string origens[], string modelos[], int& nmodelo, int& ndestino, string destinos[], aviao*avia,int argc,char *argv[],bool aeroporto_aberto,lista1 &nacio,arvore*&raiz){
    bool sair =false;
    char op;
    int tamanhoapro = 0;
    int tamanhopista =0;
    int tamanhodesc = 0;
    int ciclo;

    do {
        cout << "ciclo (s)eguinte (e)mergencias (g)ravar (o)pcoes (c)arregar"  << endl;
        cout << "Escolha a sua opcao" << endl;
        cin >> op;
        switch (op) {
            case 'e':
                emergencia(l1, l2, l3);
                break;
            case 'o':
                outras(l2,l1,l3, nacio,raiz);

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
 * Função que carrega os aviões para as listas ligadas
 * @param file variavel que indica o nome do ficheiro que será gravado
 * @param l representa lista ligada
 * @param tamanho inteiro que representa o tamanho de cada lista, chegadas, pista e partidas
 */
void carregar_avioes(ifstream& file, listas& l, int tamanho) {
    string n_voo, orig, dest, mod, pn, sn, nb, nac;
    int cap;

    for (int i = 0; i < tamanho; i++) {
        file >> n_voo;
        file.ignore();
        getline(file, orig);
        getline(file, dest);
        getline(file, mod);
        file >> cap;
        file.ignore();

        aviao novo_aviao = {n_voo, mod, orig, dest, cap, nullptr};//estrutura que cria um novo aviao
        for (int j = 0; j < cap; j++) {
            getline(file, pn);
            getline(file, sn);
            getline(file, nb);
            getline(file, nac);
            inserir_passageiro(novo_aviao, pn, sn, nb, nac);//funçao que insere passageiros na lista de passageiros
        }

        inserir2(l.primeiro, novo_aviao);//insere avioes na lista de avioes
    }
}

/**
 * Funçao que carrega o aeroporto do ficheiro, apenas funciona caso seja passada separadamente no menu principal da função opção
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
void carregar_aeroporto(listas &l1, listas &l2, listas &l3, aviao elemento, string nome[], int& nnome, int& nsegundo, int& nnacionalidades,string ssegundo_nome[], string nacionalidade[], passageiro* pass, string voo[], int& nvoo, int& norigem,string origens[], string modelos[], int& nmodelo, int& ndestino, string destinos[], aviao* avia, int argc,char* argv[], bool aeroporto_aberto, lista1 &nacio, arvore*& raiz) {
    if (argc == 2) {
        string nomeFicheiro = argv[1];
        if (nomeFicheiro == "aeroporto.txt") {
            ifstream file(nomeFicheiro);
            if (file.is_open()) {
                int tamanhoapro, tamanhopista, tamanhodesc;
                file >> tamanhoapro >> tamanhopista >> tamanhodesc;

                Nova(l1);
                carregar_avioes(file, l1, tamanhoapro);

                Nova(l2);
                carregar_avioes(file, l2, tamanhopista);

                Nova(l3);
                carregar_avioes(file, l3, tamanhodesc);

                file.close();
                menu(l1,l2,l3,nome,nnome,nsegundo,nnacionalidades,ssegundo_nome,nacionalidade,pass,voo,nvoo,norigem,origens,modelos,nmodelo,ndestino,destinos,aeroporto_aberto,raiz);

                opcao2(l1, l2, l3, elemento, nome, nnome, nsegundo, nnacionalidades, ssegundo_nome, nacionalidade, pass, voo, nvoo, norigem,origens, modelos, nmodelo, ndestino, destinos, avia, argc, argv, aeroporto_aberto, nacio, raiz);

                cout << "Dados do aeroporto carregados com sucesso" << endl;
            } else {
                cerr << "Erro ao abrir o arquivo." << endl;
            }
        } else {
            cerr << "Nome do arquivo inválido." << endl;
        }
    } else {
        cerr << "Número de argumentos inválido." << endl;
    }
}