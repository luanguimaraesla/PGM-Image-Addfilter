#ifndef MENU_H
#define MENU_H
#include "imagempgm.hpp"
#include <string>

class Menu{
	private:
		ImagemPGM imagem;
		void aplicarUmFiltro(int opcao, ImagemPGM &imagem, ImagemPGM &copia);
		int salvarImagem(int opcao, ImagemPGM &imagem, ImagemPGM &copia);
		int menuSalvar();
		string menuCaminho();
		int menuFiltros();
		int lerOpcao(int limiteInferior, int limiteSuperior);
	public:
		Menu();
		void iniciar();
		
};

#endif
