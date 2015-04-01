#ifndef DIMENSOES_H
#define DIMENSOES_H

using namespace std;

class Dimensoes{
	private:
		int altura;
		int largura;
	public:
		Dimensoes();
		Dimensoes(int altura, int largura);
		void setAltura(int altura);
		int getAltura();
		void setLargura(int largura);
		int getLargura();
		void setDimensoes(int altura, int largura);
};


#endif
