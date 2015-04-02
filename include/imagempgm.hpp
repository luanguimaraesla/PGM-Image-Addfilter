#ifndef IMAGEMPGM_H
#define IMAGEMPGM_H

#define EXISTE 1
#define NAO_EXISTE 2

#include "imagem.hpp"
#include <iostream>
#include <string>
#include <fstream>


class ImagemPGM : public Imagem{
	private:
		int nivelMaximoDeCinza;
		string comentario;
		
	public:
		ImagemPGM();
		ImagemPGM(string caminho);
		void abrirImagem(string caminho);
		void salvar();
		void salvar(string nome, string caminho);
		void setNivelMaximoDeCinza(int nivel);
		int getNivelMaximoDeCinza();
		void setComentario(string comentario);
		string getComentario();
}

#endif
