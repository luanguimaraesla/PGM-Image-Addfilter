#ifndef IMAGEM_H
#define IMAGEM_H
#include <string>
#include "dimensoes.hpp"


//using namespace std;

class Imagem{
	private:
		string caminho;
		string identificador;
		Dimensoes dimensoes;
		int *pixels;
		
	public:
		Imagem();
		Imagem(string identificador, int altura, int largura, int *pixels);
		void setIdentificador(string identificador);
		string getIdentificador();
		void setPixels(int *pixels);
		int *getPixels();
		void setCaminho(string caminho);
		string getCaminho();
		void setDimensoes(int largura, int altura);
		int getAltura();
		int getLargura();
		virtual void abrirImagem(string caminho) = 0;
		virtual void salvar() = 0;
		virtual void salvar(string caminho) = 0;	
};

#endif
