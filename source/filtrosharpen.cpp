#include "filtrosharpen.hpp"
#include <vector>

FiltroSharpen::FiltroSharpen(){
	/* Inicializando máscara */
	int x;	
	int mascara[] = {0,-1,0,-1,5,-1,0,-1,0};
	vector<int> mascaraSharpen;
	for(x = 0; x < 9; x++)
		mascaraSharpen.push_back(mascara[x]);
 
	setMascaraEspacial(mascaraSharpen);
	setTamanho(3);
	setDivisor(9);
	setLimite(1);
}
