#ifndef IMAGEM_H
#define IMAGEM_H

#include "dimensoes.hpp"
#include <string>



class Imagem{
	private:
		string identificador;
		Dimensoes dimensoes;
		int *pixels;
		
	public:
		Imagem();
		Imagem(int identificador, int altura, int largura, int *pixels);
		void setIdentificador(string identificador);
		string getIdentificador();
		void setPixels(int *pixels);
		int *getPixels();
		virtual FILE *abrirImagem(string caminho);	
};

#endif
