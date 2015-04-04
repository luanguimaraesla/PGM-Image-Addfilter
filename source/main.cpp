#include <iostream>
#include "imagempgm.hpp"
#include "filtronegativo.hpp"
#include "filtrosmooth.hpp"
#include "filtrosharpen.hpp"

using namespace std;

int main(){	
	FiltroSharpen filter;
	ImagemPGM novaImagem("lena.pgm");
	ImagemPGM outraImagem;
	filter.aplicarFiltroEmCopia(novaImagem, outraImagem);
	outraImagem.salvar("lenacp4.pgm");
	return 0;
}
