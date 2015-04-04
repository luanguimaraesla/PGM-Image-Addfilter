#ifndef FILTRO_H
#define FILTRO_H

#include "imagempgm.hpp"
#include <vector>

class Filtro{
	private:
		vector<int> mascaraEspacial;
		int tamanho;		
		int limite;
		int divisor;

	public:
		Filtro();
		Filtro(vector<int> mascaraEspacial);
		Filtro(vector<int> mascaraEspacial, int div);
		void aplicarFiltro(ImagemPGM &imagem);
		void aplicarFiltroEmCopia(ImagemPGM &imagem, ImagemPGM &copia);
		void setMascaraEspacial(vector<int> &mascaraEspacial);
		vector<int> getMascaraEspacial();
		void setTamanho(int tamanho);
		int getTamanho();
		void setLimite(int limite);
		int getLimite();
		void setDivisor(int div);
		int getDivisor();		
};

#endif
