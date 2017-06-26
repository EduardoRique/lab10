#ifndef TRATA_H
#define TRATA_H

#include <stdexcept>

using std::overflow_error;
using std::underflow_error;
using std::domain_error;


class Cheio: public overflow_error {
	public:
		Cheio() : overflow_error("Operacao invalida: Container lotado") {}
};

class Vazio: public underflow_error {
	public:
		Vazio() : underflow_error("Operacao invalida: Container vazio") {}
};

class WrongType: public domain_error {
	public:
		WrongType() : domain_error("Operacao invalida: Não é possivel inserir elementos de outro tipo") {}
};

#endif