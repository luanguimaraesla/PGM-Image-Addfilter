#ifndef IMAGEM_H
#define IMAGEM_H

#include "dimensoes.hpp"
#include <string>

using namespace std;

class Imagem{
	private:
		string caminho;
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
		void setCaminho(string caminho);
		string getCaminho();
		virtual void abrirImagem(string caminho);
		virtual void salvar();
		virtual void salvar(string nome, string caminho);	
};

#endif
