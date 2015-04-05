#include "filtronegativo.hpp"

using namespace std;

FiltroNegativo::FiltroNegativo():Filtro(){
	setTamanho(0);
	setLimite(0);
	setDivisor(1);
}

void FiltroNegativo::aplicarFiltro(ImagemPGM &imagem){
	int *pixels = imagem.getPixels();
	int i;

	for(i = 0; i < imagem.getLargura() * imagem.getAltura(); i++)
		pixels[i] = imagem.getNivelMaximoDeCinza() - pixels[i];
}

void FiltroNegativo::aplicarFiltroEmCopia(ImagemPGM &imagem, ImagemPGM &copia){
	copia.copiar(imagem);
	aplicarFiltro(copia);
}		
