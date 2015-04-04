#include <iostream>
#include "imagempgm.hpp"
#include "filtronegativo.hpp"
#include "filtrosmooth.hpp"

using namespace std;

int main(){	
	FiltroSmooth filter;
	ImagemPGM novaImagem("lena.pgm");
	ImagemPGM outraImagem;
	filter.aplicarFiltroEmCopia(novaImagem, outraImagem);
	outraImagem.salvar("lenacp4.pgm");
	return 0;
}
