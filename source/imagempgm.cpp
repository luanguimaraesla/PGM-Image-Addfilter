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

void ImagemPGM::abrirImagem(string caminho){

	ifstream arquivo; //variável que armazena o arquivo da imagem
	string id; //armazena o identificador da imagem, no caso da PGM (P5)
	string comentario; //armazena os comentarios feitos
	int x, y, contador; //x armazena quantas colunas há na imagem, y, quantas linhas e contador é auto explicativo
	int *pixels; // ponteiro que apontará para as posições alocadas para guardar os pixels
	int nivelMaximoDeCinza; // armazena o nível máximo de cinza da imagem PGM
	unsigned char *reader; // necessário para ler corretamente o valor binário de 1byte lido do arquivo para cada pixel

	try{
		//tenta abrir a imagem com o caminho fornecido
		arquivo.open(caminho.c_str(), ios::in | ios::binary);
		// verificando identidade da imagem
		getline(arquivo, id);
		//compara a primeira linha com P5 para verificar
		if(id.compare("P5") != 0){
			cout << "Desculpe, abra um arquivo PGM!" <<endl;
		}
		else{
			cout << "Arquivo PGM!" <<endl;
			//lendo comentario
			getline(arquivo, comentario);
			cout << "Comentario: " <<comentario <<endl;
			//lendo dimensões e nível máximo de cinza da imagem
			arquivo >> x;
			arquivo >> y;
			arquivo >> nivelMaximoDeCinza;
			cout << "X: " << x << " Y: " << y << " Nivel: "<< nivelMaximoDeCinza <<endl;

			//alocando espaço na memória para o vetor que armazenará os pixels
			//NOTA: otimizar essa operação para arrays em C++
			pixels = (int *) new int [sizeof(int) * x * y];
			reader = (unsigned char *) new unsigned char [sizeof(unsigned char) * x * y];
			arquivo.read(reinterpret_cast<char *>(reader), (y*x)*sizeof(unsigned char));		

			for(contador = 0; contador < x * y; contador++){
				 pixels[contador] = (int) reader[contador];
				 cout << pixels[contador];
			}
			//setando atributos do objeto
			setCaminho(caminho);
			setDimensoes(x,y);
			setComentario(comentario);
			setIdentificador(id);
			setNivelMaximoDeCinza(nivelMaximoDeCinza);
			setPixels(pixels);
	
		}
	}
	catch (int e){
		//em caso de qualquer erro, apresentar essa mensagem para o usuário
		cout << "Desculpe, operacao falhou! Exception Nº " << e << endl;
	}

	//fecha o arquivo
	arquivo.close();
	
}

void ImagemPGM::salvar(){
	salvar(getCaminho());
}

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

