/**
*@file	Fila.h
*@brief	Cabecalho da classe Fila
*@author Luís Eduardo Rique (luiseduardorique@gmail.com)
*@since 09/05/2017
*@date  09/05/2017
*/

#ifndef FILA_H
#define FILA_H

#include <iostream>
#include <string>
#include "trata.h"
using std::cout;
using std::cerr;
using std::endl;
using std::string;

namespace edb1 {

/**
    * @class   Fila Fila.h
    * @brief   Classe que representa uma Fila
    * @details Os atributos da Fila são: tamanhomax, tamanho e Fila
	*/ 
    template<typename T>
    class Fila {
        private:
        int tamanhomax; /**< Tamanho maximo da Fila */
        int tamanho; /**< Tamanho */
        T *fila; /**< elementos */
        
        public:
        Fila(int tamanho); /**< Construtor padrao */
        int push(T el); /**< Insere no topo */
        T pop(); /**< Remove do topo */
    };

    /**
    *@details   É alocado um espaço de memoria necessario tamanho maximo
    *			recebe esse tamanho e o tamanho inicializa com 0
    *@param     n tamanho
    */
    template<typename T>
    Fila<T>::Fila(int n){
        fila = new T[n];
        tamanhomax = n;
        tamanho = 0;
    }

    /**
    *@details   O topo da lista recebe um elemento
    *@param     el elemento
    *@return    tamanho atual
    */
    template<typename T>
    int Fila<T>::push(T el){
        try{
            if(tamanho == tamanhomax) throw Cheio();
            else{
                fila[tamanho] = el;
                return tamanho++;
            }
        }
        catch (Cheio &c) {
            cerr << c.what() << endl;
        }
        return tamanho;
    }

    /**
    *@details   O elemento do topo é removido da Fila
    *@return    ultimo elemento
    */
    template<typename T>
    T Fila<T>::pop(){
        try{
            if(tamanho == 0) throw Vazio();
            else{
                tamanho--;
                T el = fila[0];
                for(int i = 0; i < tamanho; i++){
                    fila[i] = fila[i + 1];
                }
                return el;
            }
        }
        catch(Vazio &v){
            cerr << v.what() << endl;
        }
        return 0;
    }
}

#endif