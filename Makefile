#VARIAVEIS
BINFOLDER := ./bin/
INCFOLDER := ./include/
SRCFOLDER := ./source/
OBJFOLDER := ./obj/

COMPILER := g++
FLAGS := -Wall -ansi -I$(INCFOLDER)

SRCFILES := $(wildcard source/*.cpp) #retorna uma espécie de vetor com todos os arquivos .cpp da pasta src

# $ copia uma variavel na linha, como um echo
#Dimensoes.o imagem.o imagempgm.o main.o
all:	 $(SRCFILES:source/%.cpp=obj/%.o)
		$(COMPILER) $(FLAGS) $(OBJFOLDER)*.o -o $(BINFOLDER)finalBinary

# &@ subtitui pelo nome do alvo / $< pega o primeiro argumento da lista de dependencias
#Cada elemento é definido
obj/%.o:	source/%.cpp
				$(COMPILER) $(FLAGS) -c $< -o $@ 


#cria uma função
.PHONY: clean
clean:
	rm -rf $(OBJFOLDER)*.o

run:
	$(BINFOLDER)finalBinary
