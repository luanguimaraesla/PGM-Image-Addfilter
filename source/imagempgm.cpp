#include "imagempgm.hpp"
#include <stdlib.h>

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
	int x, y, counter; //x armazena quantas colunas há na imagem, y, quantas linhas e counter é um contador
	int *pixels; // ponteiro que apontará para as posições alocadas para guardar os pixels
	int nivelMaximoDeCinza; // armazena o nível máximo de cinza da imagem PGM
	unsigned char reader; // necessário para ler corretamente o valor binário de 1byte lido do arquivo para cada pixel

	try{
		//tenta abrir a imagem com o caminho fornecido
		arquivo.open(caminho.c_str());
		
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
			pixels = (int *) malloc (sizeof(int) * x * y);		

			//lendo o resto do arquivo para conseguir os pixels
			for(counter = 0; counter < (x*y); counter++){
				arquivo >> reader; //ler o binário e armazenar em reader
				pixels[counter] = (int)reader; /*transformar o binário em inteiro e armazenar em pixels*/
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
	//CONSTRUIR MÉTODO
	cout << "CRIAR SALVAR";
}

void ImagemPGM::salvar(string nome, string caminho){
	//CONSTRUIR MÉTODO
	cout << "CRIAR SALVAR";
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

