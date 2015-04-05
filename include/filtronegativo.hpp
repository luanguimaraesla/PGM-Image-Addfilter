#ifndef FILTRO_NEGATIVO_H
#define FILTRO_NEGATIVO_H

#include "imagempgm.hpp"

class FiltroNegativo{
	public:
		FiltroNegativo();
		void aplicarFiltro(ImagemPGM &imagem);
		void aplicarFiltroEmCopia(ImagemPGM &imagem, ImagemPGM &copia);
};

#endif
