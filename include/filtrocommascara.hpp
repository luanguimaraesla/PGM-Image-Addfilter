#ifndef FILTRO_MASCARA_H
#define FILTRO_MASCARA_H

#include "filtro.hpp"
#include "imagempgm.hpp"
#include <vector>

class FiltroComMascara : public Filtro{
	private:
		vector<int> mascaraEspacial;
		int tamanho;		
		int limite;
		int divisor;

	public:
		FiltroComMascara();
		FiltroComMascara(vector<int> mascaraEspacial);
		FiltroComMascara(vector<int> mascaraEspacial, int div);
		virtual void aplicarFiltro(ImagemPGM &imagem);
		virtual void aplicarFiltroEmCopia(ImagemPGM &imagem, ImagemPGM &copia);
		void setMascaraEspacial(vector<int> &mascaraEspacial);
		vector<int> getMascaraEspacial();
		void setTamanho(int tamanho);
		int getTamanho();
		void setLimite(int limite);
		int getLimite();
		void setDivisor(int div);
		int getDivisor();		
};

#endif
