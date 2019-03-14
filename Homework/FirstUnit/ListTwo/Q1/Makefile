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
CFLAGS=	-Wall -pedantic -ansi -std=c++11

#Garante que os alvos desta lista não sejam confundidos com arquivos de mesmo nome 
.PHONY:	all	clean doc debug

#Ao final da compilacão, remove os arquivos objetos
all: init bisecao pontoFixo secante falsaPosicao newtonRaphson

debug:	CFLAGS += -g -O0
debug:	bisecao pontoFixo secante falsaPosicao newtonRaphson

# Cria a pasta/diretório bin e a obj
init:
	@mkdir -p $(OBJ_DIR)/Metodo_Bisecao
	@mkdir -p $(OBJ_DIR)/Metodo_FalsaPosicao
	@mkdir -p $(OBJ_DIR)/Metodo_NewtonRaphson
	@mkdir -p $(OBJ_DIR)/Metodo_PontoFixo
	@mkdir -p $(OBJ_DIR)/Metodo_Secante	
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(DOC_DIR)

# Alvo (target) para a construcao do executavel Metodo_Bisecao
# Define o arquivo bisecao.o como dependência
bisecao: CFLAGS+= -I$(INC_DIR)/Metodo_Bisecao
bisecao: $(OBJ_DIR)/Metodo_Bisecao/bisecao.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel Metodo_Bisecao criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto bisecao.o
# Define os arquivos bisecao.cpp e bisecao.h como dependencias.
$(OBJ_DIR)/Metodo_Bisecao/bisecao.o: $(SRC_DIR)/Metodo_Bisecao/bisecao.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do executavel Metodo_PontoFixo
# Define o arquivo bisecao.o como dependência
pontoFixo: CFLAGS+= -I$(INC_DIR)/Metodo_PontoFixo
pontoFixo: $(OBJ_DIR)/Metodo_PontoFixo/pontoFixo.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel Metodo_PontoFixo criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto pontoFixo.o
# Define os arquivos pontoFixo.cpp e pontoFixo.h como dependencias.
$(OBJ_DIR)/Metodo_PontoFixo/pontoFixo.o: $(SRC_DIR)/Metodo_PontoFixo/pontoFixo.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

secante: CFLAGS+= -I$(INC_DIR)/Metodo_Secante
secante: $(OBJ_DIR)/Metodo_Secante/secante.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel Metodo_Secante criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto secante.o
# Define o arquivo secante.cpp como dependência.
$(OBJ_DIR)/Metodo_Secante/secante.o:	$(SRC_DIR)/Metodo_Secante/secante.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

falsaPosicao: CFLAGS+= -I$(INC_DIR)/Metodo_FalsaPosicao
falsaPosicao: $(OBJ_DIR)/Metodo_FalsaPosicao/falsaPosicao.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel Metodo_FalsaPosicao criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto falsaPosicao.o
# Define o arquivo falsaPosicao.cpp como dependência.
$(OBJ_DIR)/Metodo_FalsaPosicao/falsaPosicao.o:	$(SRC_DIR)/Metodo_FalsaPosicao/falsaPosicao.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

newtonRaphson: CFLAGS+= -I$(INC_DIR)/Metodo_NewtonRaphson
newtonRaphson: $(OBJ_DIR)/Metodo_NewtonRaphson/newtonRaphson.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel Metodo_NewtonRaphson criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto newtonRaphson.o
# Define o arquivo newtonRaphson.cpp como dependência.
$(OBJ_DIR)/Metodo_NewtonRaphson/newtonRaphson.o:	$(SRC_DIR)/Metodo_NewtonRaphson/newtonRaphson.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

doc:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

#removendo os .o e os binários
clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/Metodo_Bisecao/*
	$(RM) $(OBJ_DIR)/Metodo_NewtonRaphson/*
	$(RM) $(OBJ_DIR)/Metodo_PontoFixo/*
	$(RM) $(OBJ_DIR)/Metodo_Secante/*
	$(RM) $(OBJ_DIR)/Metodo_FalsaPosicao/*
	$(RM) $(DOC_DIR)/*
	
#FIM DO MAKEFILE