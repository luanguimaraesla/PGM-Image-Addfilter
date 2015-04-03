#include "imagem.hpp"
#include "dimensoes.hpp"

using namespace std;

Imagem::Imagem(){
	setIdentificador("NONE");
	setDimensoes(0,0);
}

Imagem::Imagem(string identificador, int altura, int largura, int *pixels){
	setIdentificador(identificador);
	setPixels(pixels);
	dimensoes.setDimensoes(altura, largura);
}

void Imagem::setIdentificador(string identificador){
	this->identificador = identificador;
}

string Imagem::getIdentificador(){
	return identificador;
}

void Imagem::setPixels(int *pixels){
	this->pixels = pixels;
}

int * Imagem::getPixels(){
	return pixels;
}

void Imagem::setCaminho(string caminho){
	this->caminho = caminho;
}

string Imagem::getCaminho(){
	return caminho;
}

void Imagem::setDimensoes(int largura, int altura){
	dimensoes.setAltura(altura);
	dimensoes.setLargura(largura);
}

int Imagem::getAltura(){
	return dimensoes.getAltura();
}

int Imagem::getLargura(){
	return dimensoes.getLargura();
}

