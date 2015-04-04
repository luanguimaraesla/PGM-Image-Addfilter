#include "imagempgm.hpp"
#include <stdlib.h>
#include <cstdlib>

using namespace std;

ImagemPGM::ImagemPGM():Imagem(){
	setCaminho("NONE");
}

ImagemPGM::ImagemPGM(string caminho){
	abrirImagem(caminho);	
}

/*
 *	Método que copia uma imagemPGM para a outra.
 *	NOTA: Implementar sobrescrita do operador "=" para realizar essa função.
 *
 */

void ImagemPGM::copiar(ImagemPGM &imagem){
	int c;
	int *pixelsToCopy = imagem.getPixels();
	int *pixels;

	pixels = (int *) new int [sizeof(int) * imagem.getAltura() * imagem.getLargura()];
	for(c = 0; c < imagem.getAltura() * imagem.getLargura();c++)
		pixels[c] = pixelsToCopy[c];

	this->setPixels(pixels);
	this->setIdentificador(imagem.getIdentificador());
	this->setDimensoes(imagem.getLargura(), imagem.getAltura());
	this->setComentario(imagem.getComentario());
	this->setNivelMaximoDeCinza(imagem.getNivelMaximoDeCinza());
}

void ImagemPGM::abrirImagem(string caminho){

	ifstream arquivo; 	// Variável que armazenará o arquivo da imagem.
	string id; 		// Armazena o identificador da imagem, no caso da PGM ANSI, o identificador é P5.
	string comentario; 	// Armazena os comentários da imagem.
	int x, y, contador; 	// x armazena quantas colunas há na imagem, y, quantas linhas e contador é auto explicativo.
	int *pixels; 		// Ponteiro que apontará as posições alocadas para guardar os pixels.
	int nivelMaximoDeCinza; // Armazena o nível máximo de cinza da imagem PGM.
	unsigned char *reader; 	// Necessário para interpretar corretamente o valor binário de 1byte lido do arquivo para cada pixel.

	try{
		// Tenta abrir o arquivo PGM com o caminho fornecido.
		arquivo.open(caminho.c_str(), ios::in | ios::binary);
		
		// Lê a linha que contém o identificador da imagem.
		getline(arquivo, id);

		// Compara a primeira linha com "P5" para verificar se é uma imagem do tipo PGM
		if(id.compare("P5") != 0){
			// Se não for, imprime-se uma mensagem de erro e nada do que vem a seguir será executado.
			cout << "Desculpe, abra um arquivo PGM!" <<endl;
		}
		else{
			cout << "Arquivo PGM!" <<endl;
			// Lendo a linha que contém o comentário.
			getline(arquivo, comentario);
			cout << "Comentario: " <<comentario <<endl;
			
			// Lendo dimensões e nível máximo de cinza da imagem.
			arquivo >> x;
			arquivo >> y;
			arquivo >> nivelMaximoDeCinza;
			cout << "X: " << x << " Y: " << y << " Nivel: "<< nivelMaximoDeCinza <<endl;

			// Criando o vetor que armazenará os pixels.
			pixels = (int *) new int [sizeof(int) * x * y];

			// Criando o vetor que irá ler o binário dos pixels.
			reader = (unsigned char *) new unsigned char [sizeof(unsigned char) * x * y];
			
			// Armazenando pixel por pixel dentro de cada posição do vetor reader.
			arquivo.read(reinterpret_cast<char *>(reader), (y*x)*sizeof(unsigned char));		

			// Convertendo os valores lidos para inteiro e armazenando na variável pixels.
			for(contador = 0; contador < x * y; contador++) 
				pixels[contador] = (int) reader[contador];
				
			
			// Setando atributos do objeto criado.
			setCaminho(caminho);
			setDimensoes(x,y);
			setComentario(comentario);
			setIdentificador(id);
			setNivelMaximoDeCinza(nivelMaximoDeCinza);
			setPixels(pixels);

			delete [] reader; // Libera o espaço de memória do vetor.
	
		}
	}
	catch (int e){
		//em caso de qualquer erro, apresentar essa mensagem para o usuário
		cout << "Desculpe, operacao falhou! Exception Nº " << e << endl;
	}

	arquivo.close();	
}

/*
 *	Salva o arquivo PGM no mesmo caminho em que ele foi aberto.
 */

void ImagemPGM::salvar(){
	salvar(getCaminho());
}

/*
 *	Salva o arquivo com um caminho personalizado.
 *	Esse método é muito semelhante ao método de leitura e realiza exatamente o procedimento inverso.
 *	Note que usa-se o método write para escrever cada posição do vetor que contém os pixels no arquivo.
 */

void ImagemPGM::salvar(string caminho){
	ofstream novoArquivo;
	int contador;
	int *pixels = getPixels();
	unsigned char *pixelsBits;
	
	pixelsBits = (unsigned char *) new unsigned char [getAltura() * getLargura()];
	for(contador = 0; contador < getLargura() * getAltura(); contador++)
		pixelsBits[contador] = (unsigned char) pixels[contador];
	
	try{
		novoArquivo.open(caminho.c_str(), ios::out | ios::binary);
		
		novoArquivo << getIdentificador() << endl;
		novoArquivo << getComentario() << endl;
		novoArquivo << getLargura() << " " << getAltura() << endl;
		novoArquivo << getNivelMaximoDeCinza() << endl;
		novoArquivo.write(reinterpret_cast<char *>(pixelsBits), (getAltura() * getLargura())*sizeof(unsigned char));
	}
	catch(int e){
		cout << "Desculpe, arquivo nao foi salvo!" << endl;
	}

	delete [] pixelsBits;
	novoArquivo.close();
}

void ImagemPGM::setNivelMaximoDeCinza(int nivel){
	this->nivelMaximoDeCinza = nivel;
}

int ImagemPGM::getNivelMaximoDeCinza(){
	return nivelMaximoDeCinza;
}

void ImagemPGM::setComentario(string comentario){
	this->comentario = comentario;
}

string ImagemPGM::getComentario(){
	return comentario;
}
