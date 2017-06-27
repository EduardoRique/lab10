/** 
*@file main.cpp
*@brief Arquivo fonte para execução do projeto
*@author Luís Eduardo Rique (luiseduardorique@gmail.com)
*@since 20/06/2017
*@date  20/06/2017
*/

#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include "eduardo.h"

using namespace std;
using namespace edb1;

/**
* @brief        Função principal do programa
* @return		Retorno
*/

int main(){

    char t = 'a';

    //Testa a classe lista
    cout << "---------------------" << endl;
    cout << "Teste de lista ligada" << endl;
    cout << "---------------------" << endl;
    Lista<int> *lista = new Lista<int>();
    lista->Inserir(10);
    lista->Print();
    //Erro de insercao
    try{
            if(typeid(int) != typeid(t)) throw WrongType();
            else{
                lista->Inserir(t);
            }
        }
        catch(WrongType &w){
            cerr << w.what() << endl;
        }
    //Erro de remocao para elemento que nao esta na lista
    lista->Remover(20);


    //Testa a classe pilha
    cout << "--------------" << endl;
    cout << "Teste de pilha" << endl;
    cout << "--------------" << endl;
    Pilha<int> pilha(2);
    pilha.push(10);
    pilha.push(12);
    pilha.push(20);
    //Erro de insercao
    try{
            if(typeid(int) != typeid(t)) throw WrongType();
            else{
                pilha.push(t);
            }
        }
        catch(WrongType &w){
            cerr << w.what() << endl;
        }

    cout << pilha.pop() << endl;
    cout << pilha.pop() << endl;
    //erro pilha vazia
    pilha.pop();

    //Testa a classe pilha
    cout << "-------------" << endl;
    cout << "Teste de fila" << endl;
    cout << "-------------" << endl;
    Fila<int> fila(2);
    fila.push(10);
    fila.push(12);
    fila.push(20);
    //Erro de insercao
    try{
            if(typeid(int) != typeid(t)) throw WrongType();
            else{
                pilha.push(t);
            }
        }
        catch(WrongType &w){
            cerr << w.what() << endl;
        }

    cout << fila.pop() << endl;
    cout << fila.pop() << endl;
    //erro fila vazia
    fila.pop();

    //Testa as buscas
    cout << "----------------" << endl;
    cout << "Testes de buscas" << endl;
    cout << "----------------" << endl;
    int V[100];
    for(int i = 0; i < 100; i++){ 
        V[i] = i + 1;
    }
    cout <<  busca_seq_i(V, 0, 100, 9) << endl;
    cout <<  busca_seq_r(V, 0, 100, 87) << endl;
    cout <<  busca_bin_i(V, 0, 100, 12) << endl;
    cout <<  busca_bin_r(V, 0, 100, 65) << endl;
    cout <<  busca_ter_i(V, 0, 100, 85) << endl;
    cout <<  busca_ter_r(V, 0, 100, 10) << endl;
    
    //Erro para elemento não encontrado no vetor
    try{
        if(busca_seq_i(V, 0, 100, 111) == -1) throw NaoEncontrado();
        else{
            cout << busca_seq_i(V, 0, 100, 111) << endl;
        }
    }
    catch(NaoEncontrado &n){
        cerr << n.what() << endl;
    }

    try{
        if(busca_seq_r(V, 0, 100, 111) == -1) throw NaoEncontrado();
        else{
            cout << busca_seq_r(V, 0, 100, 111) << endl;
        }
    }
    catch(NaoEncontrado &n){
        cerr << n.what() << endl;
    }

    try{
        if(busca_bin_i(V, 0, 100, 111) == -1) throw NaoEncontrado();
        else{
            cout << busca_bin_i(V, 0, 100, 111) << endl;
        }
    }
    catch(NaoEncontrado &n){
        cerr << n.what() << endl;
    }

    try{
        if(busca_bin_r(V, 0, 100, 111) == -1) throw NaoEncontrado();
        else{
            cout << busca_bin_r(V, 0, 100, 111) << endl;
        }
    }
    catch(NaoEncontrado &n){
        cerr << n.what() << endl;
    }

    try{
        if(busca_ter_i(V, 0, 100, 111) == -1) throw NaoEncontrado();
        else{
            cout << busca_ter_i(V, 0, 100, 111) << endl;
        }
    }
    catch(NaoEncontrado &n){
        cerr << n.what() << endl;
    }

    try{
        if(busca_ter_r(V, 0, 100, 111) == -1) throw NaoEncontrado();
        else{
            cout << busca_ter_r(V, 0, 100, 111) << endl;
        }
    }
    catch(NaoEncontrado &n){
        cerr << n.what() << endl;
    }

    return 0;
}