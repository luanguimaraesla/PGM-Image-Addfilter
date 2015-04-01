#include "imagem.hpp"
#include "dimensoes.hpp"
#include <fstream>

using namespace std;

Imagem::Imagem(){
	setIdentificador("NONE");
	dimensoes.setDimensoes(0,0);
}

Imagem::Imagem(int identificador, int altura, int largura, int *pixels){
	setIdentificador(identificador);
	setPixels(pixels);
	setDimensoes(altura, largura);
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

