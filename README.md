# Filtros em Imagens PGM

Esse programa foi desenvolvido para aplicar filtros (*negativo*, *sharpen*, *smooth*) em imagens PGM (*Portable Gray Map*).

## Como Compilar e Executar

Para compilar e executar o programa em um sistema operacional Linux, siga as seguintes instruções:

* Abra o terminal;
* Encontre o diretório raiz do projeto; 
* Execute o Makefile: 
	**$ make**
* Abra a pasta bin:
	**$ cd ./bin**
* Execute o binário final:
	**$ ./finalBinary**

Obs.: para facilitar o teste desse programa, coloque a imagem pgm na pasta onde se encontra o binário final e digite apenas o nome do arquivo. Caso contrário, ao ser solicitado, insira o caminho relativo ao binário final.

## Funcionamento

O funcionamento do programa está descrito a seguir:

* O programa pedirá para inserir o diretório onde está a imagem.
* Escolha o tipo de filtro que deseja aplicar.
* Escolha entre as opções para salvar ou aplicar mais filtros a imagem.
* Abra o diretório onde a imagem foi salva e veja o resultado.

## Formato

É importante salientar que esse programa foi desenvolvido para trabalhar com imagens do tipo PGM cujo número mágico é **P5** e não **P2**.
 
Conhecido como *Plain PGM*, o formato **P2** corresponde a uma versão derivada do estilo **P5** (*Raw PGM*) e contém algumas diferenças estruturais que não garantem o funcionamento adequado desse programa.

Para mais informações a respeito do formato PGM, [clique aqui](http://netpbm.sourceforge.net/doc/pgm.html).


