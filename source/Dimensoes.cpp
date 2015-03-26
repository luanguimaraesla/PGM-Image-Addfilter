#include "Dimensoes.hpp"

using namespace std;

Dimensoes::Dimensoes(){
	altura = 0;
	largura = 0;
}

Dimensoes::Dimensoes(int altura, int largura){
	this->altura = altura;
	this->largura = largura;
}

void Dimensoes::setAltura(int altura){
	this->altura = altura;
}

int Dimensoes::getAltura(){
	return altura;
}

void Dimensoes::setLargura(int largura){
	this->largura = largura;
}

int Dimensoes::getLargura(){
	return largura;
}
