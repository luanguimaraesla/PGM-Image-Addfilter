#include <iostream>
#include "imagempgm.hpp"
#include "filtronegativo.hpp"

using namespace std;

int main(){	
	FiltroNegativo filter;
	ImagemPGM novaImagem("lena.pgm");
	ImagemPGM outraImagem;
	filter.aplicarFiltroEmCopia(novaImagem, outraImagem);
	novaImagem.salvar("olalena.pgm");
	outraImagem.salvar("lenacp4.pgm");
	return 0;
}
