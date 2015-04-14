#include "menu.hpp"
#include "filtro.hpp"
#include "filtronegativo.hpp"
#include "filtrosmooth.hpp"
#include "filtrosharpen.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

Menu::Menu(){

}

void Menu::iniciar(){
	ImagemPGM copia;
	
	cout << "--------BEM VINDO AO APLICADOR DE FILTROS PGM-------" <<endl;

	imagem.abrirImagem(menuCaminho());
	aplicarUmFiltro(menuFiltros(), imagem, copia);
}

void Menu::aplicarUmFiltro(int opcao, ImagemPGM &imagem, ImagemPGM &copia){
	Filtro *filtro;	

	switch(opcao){
		case 1:
			filtro = (Filtro *) new FiltroNegativo();
			filtro->aplicarFiltroEmCopia(imagem, copia);
			break;
		case 2:
			filtro = (Filtro *) new FiltroSmooth();
			filtro->aplicarFiltroEmCopia(imagem, copia);
			break;
		case 3:
			filtro = (Filtro *) new FiltroSharpen();
			filtro->aplicarFiltroEmCopia(imagem, copia);
			break;
		default:
			cout << "Tchau!" <<endl;
			exit(0);
	}
	
	salvarImagem(menuSalvar(), imagem, copia);
}

int Menu::salvarImagem(int opcao, ImagemPGM &imagem, ImagemPGM &copia){
	switch(opcao){
		case 1:
			copia.salvar();
			break;
		case 2:
			copia.salvar(menuCaminho());
			break;
		case 3:
			copia.salvar(menuCaminho());
			aplicarUmFiltro(menuFiltros(), this->imagem, copia);
			break;
		case 4:
			aplicarUmFiltro(menuFiltros(), copia, copia);		
	}

	cout << "Tchau!" <<endl;
	exit(0);
}

int Menu::menuSalvar(){
	cout <<endl;	
	cout << "Selecione uma opção de salvamento: " <<endl;
	cout <<endl;
	cout << "0. Sair sem salvar.\n1. Sobrescrever arquivo original.\n2. Salvar em outro caminho.\n3. Salvar e testar outros filtros.\n4. Aplicar mais filtros a esta imagem antes de salvar."<<endl;
	
	return lerOpcao(0,4);
}

	

string Menu::menuCaminho(){
	string caminho;	
	
	cout <<endl;
	cout <<"Digite o caminho relativo do arquivo: ";
	cin >> caminho;
	
	return caminho;
}

int Menu::menuFiltros(){
	cout <<endl;
	cout << "-------------------MENU DE FILTROS------------------" <<endl;
	cout <<endl;
	cout << "0. Sair\n1. Aplicar Negativo\n2. Aplicar Smooth\n3. Aplicar Sharpen"<<endl;
	
	return lerOpcao(0,3);
}

int Menu::lerOpcao(int limiteInferior, int limiteSuperior){
	int opcao;
	
	cout <<endl;
	cout << "Escolha: ";
	cin >> opcao;
	while(opcao > limiteSuperior || opcao < limiteInferior){
		cout << "Erro, essa alternativa nao existe! Tente de novo: ";
		cin >> opcao;
	}
	
	return opcao;
}
