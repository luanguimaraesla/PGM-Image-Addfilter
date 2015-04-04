#include "filtro.hpp"
#include <math.h>
#include <iostream>

using namespace std;

Filtro::Filtro(){
	mascaraEspacial.resize(0);
}

Filtro::Filtro(vector<int> mascaraEspacial){	
	int tamanho = sqrt(mascaraEspacial.size());
	int limite = tamanho/2;

	setMascaraEspacial(mascaraEspacial);
	setTamanho(tamanho);
	setLimite(limite);
	setDivisor(1);
}

Filtro::Filtro(vector<int> mascaraEspecial, int divisor){
	int tamanho = sqrt(mascaraEspacial.size());
	int limite = tamanho/2;

	setMascaraEspacial(mascaraEspacial);
	setTamanho(tamanho);
	setLimite(limite);
	setDivisor(divisor);
}

void Filtro::aplicarFiltro(ImagemPGM &imagem){
	int i , j, x , y, valor;
	int *pixels = imagem.getPixels(); 
	
	for (i = limite; i < imagem.getLargura() - limite; i++){
		for(j = limite; imagem.getAltura() - limite; i++){
			valor = 0;
			for(x = -1; x <= 1; x++){
				for(y = -1; y <= 1; y++){
					valor += mascaraEspacial[(x+1) + tamanho*(y+1)] *
						 pixels[(i+x) + (y + j)*imagem.getLargura()];
				}
			}
			
			valor /= divisor;

			valor = valor < 0 ? 0 : valor;
			valor = valor > 255 ? 255 : valor;

			pixels[i + j * imagem.getLargura()] = valor;		
		}
	}
}

void Filtro::aplicarFiltroEmCopia(ImagemPGM &imagem, ImagemPGM &copia){
	copia.copiar(imagem);
	aplicarFiltro(copia);
}

void Filtro::setLimite(int limite){
	this->limite = limite;
}

int Filtro::getLimite(){
	return limite;
}

void Filtro::setMascaraEspacial(vector<int> &mascaraEspacial){
	this->mascaraEspacial = mascaraEspacial;
}

vector<int> Filtro::getMascaraEspacial(){
	return mascaraEspacial;
}

void Filtro::setTamanho(int tamanho){
	this->tamanho = tamanho;
}

int Filtro::getTamanho(){
	return tamanho;
}

void Filtro::setDivisor(int divisor){
	this->divisor = divisor;
}

int Filtro::getDivisor(){
	return divisor;
}
