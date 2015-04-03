#ifndef FILTRO_H
#define FILTRO_H

#include "imagempgm.hpp"
#include <vector>

class Filtro{
	private:
		vector<int> mascaraEspacial;
	public:
		Filtro();
		Filtro(int *mascaraEspacial);
		void setMascaraEspacial(int *mascaraEspacial);
		vector<int> getMascara();
		void aplicarFiltro(ImagemPGM &imagem);		
};

#endif
