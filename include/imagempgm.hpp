#ifndef IMAGEMPGM_H
#define IMAGEMPGM_H

#include "imagem.hpp"
#include <iostream>
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
