#ifndef IMAGEMPGM_H
#define IMAGEMPGM_H

#define EXISTE 1
#define NAO_EXISTE 2

#include "imagem.hpp"
#include <string>
#include <fstream>


class ImagemPGM : public Imagem{
	private:
		int nivelMaximoDeCinza;
	
		void descompactarImagem(fstream arquivo);
		fstream abrirImagem(string caminho);
		void validarPGM(string identificador);
		
	public:
		explicit ImagemPGM(string caminho);
		void salvar();
		void salvar(string nome, string caminho);
		void setNivelMaximoDeCinza(int nivel);
		int getNivelMaximoDeCinza();
}

#endif
