#include "filtrocommascara.hpp"
#include <math.h>

using namespace std;

FiltroComMascara::FiltroComMascara(){
	mascaraEspacial.resize(0);
}

FiltroComMascara::FiltroComMascara(vector<int> mascaraEspacial){	
	int tamanho = sqrt(mascaraEspacial.size());
	int limite = tamanho/2;

	setMascaraEspacial(mascaraEspacial);
	setTamanho(tamanho);
	setLimite(limite);
	setDivisor(1);
}

FiltroComMascara::FiltroComMascara(vector<int> mascaraEspecial, int divisor){
	int tamanho = sqrt(mascaraEspacial.size());
	int limite = tamanho/2;

	setMascaraEspacial(mascaraEspacial);
	setTamanho(tamanho);
	setLimite(limite);
	setDivisor(divisor);
}

void FiltroComMascara::aplicarFiltro(ImagemPGM &imagem){
	int i , j, x , y, valor;
	int *pixels = imagem.getPixels(); 
	
	for (i = getLimite(); i < (imagem.getLargura() - getLimite()); i++){
		for(j = getLimite(); j < (imagem.getAltura() - getLimite()); j++){
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

void FiltroComMascara::aplicarFiltroEmCopia(ImagemPGM &imagem, ImagemPGM &copia){
	copia.copiar(imagem);
	aplicarFiltro(copia);
}

void FiltroComMascara::setLimite(int limite){
	this->limite = limite;
}

int FiltroComMascara::getLimite(){
	return limite;
}

void FiltroComMascara::setMascaraEspacial(vector<int> &mascaraEspacial){
	int x;
	tamanho = mascaraEspacial.size();	
	for(x=0; x<tamanho; x++)
		(this->mascaraEspacial).push_back(mascaraEspacial[x]);
}

vector<int> FiltroComMascara::getMascaraEspacial(){
	return mascaraEspacial;
}

void FiltroComMascara::setTamanho(int tamanho){
	this->tamanho = tamanho;
}

int FiltroComMascara::getTamanho(){
	return tamanho;
}

void FiltroComMascara::setDivisor(int divisor){
	this->divisor = divisor;
}

int FiltroComMascara::getDivisor(){
	return divisor;
}
