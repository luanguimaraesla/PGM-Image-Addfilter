#include <iostream>
#include "imagempgm.hpp"

using namespace std;

int main(){
	
	ImagemPGM novaImagem("lena.pgm");
	novaImagem.salvar("lenacp.pgm");
	return 0;
}
