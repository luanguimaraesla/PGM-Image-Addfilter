#include "filtrosmooth.hpp"
#include <vector>

FiltroSmooth::FiltroSmooth(){
	vector<int> mascaraSmooth(9,1);
	setMascaraEspacial(mascaraSmooth);
	setTamanho(3);
	setDivisor(9);
	setLimite(1);
}
