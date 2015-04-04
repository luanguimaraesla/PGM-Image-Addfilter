#ifndef FILTRO_NEGATIVO_H
#define FILTRO_NEGATIVO_H

#include "filtro.hpp"

class FiltroNegativo : public Filtro{
	public:
		FiltroNegativo();
		void aplicarFiltro(ImagemPGM &imagem);
		void aplicarFiltroEmCopia(ImagemPGM &imagem, ImagemPGM &copia);
};

#endif
