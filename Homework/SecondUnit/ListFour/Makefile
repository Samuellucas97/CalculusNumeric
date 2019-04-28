RM = rm -rf
#Compilador
CC=g++

#Variaveis para os subdiretorios
#LIB_DIR=./lib Não haverá pois nenhuma biblioteca será usada
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc

#Opcoes de compilacao 
CFLAGS=	-Wall -pedantic -ansi -std=c++11 -lGL -GLU -lglut

#Garante que os alvos desta lista não sejam confundidos com arquivos de mesmo nome 
.PHONY:	all	clean doc debug

#Ao final da compilacão, remove os arquivos objetos
all: init curva

debug:	CFLAGS += -g -O0
debug:	curva  

# Cria a pasta/diretório bin e a obj
init:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(DOC_DIR)

# Alvo (target) para a construcao do executavel Jogo
# Define o arquivo game.o como dependência
curva: CFLAGS+= -I$(INC_DIR)/
curva: $(OBJ_DIR)/curva.o 
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel curva criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto servidor.o
# Define os arquivos servidor.cpp e servidor.h como dependencias.
$(OBJ_DIR)/curva.o: $(SRC_DIR)/Q4/curva.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

doc:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

#removendo os .o e os binários
clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
	$(RM) $(DOC_DIR)/*
	
#FIM DO MAKEFILE

