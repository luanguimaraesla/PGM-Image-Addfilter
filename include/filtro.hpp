#ifndef FILTRO_H
#define FILTRO_H

#include "imagempgm.hpp"
#include <vector>

class Filtro{
	public:
		virtual void aplicarFiltro(ImagemPGM &imagem) = 0;
		virtual void aplicarFiltroEmCopia(ImagemPGM &imagem, ImagemPGM &copia) = 0;		
};

#endif
