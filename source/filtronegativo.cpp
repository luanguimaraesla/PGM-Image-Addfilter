#include "filtronegativo.hpp"

using namespace std;

FiltroNegativo::FiltroNegativo(){
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
