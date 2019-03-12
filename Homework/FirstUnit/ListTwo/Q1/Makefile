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
CFLAGS=	-Wall -pedantic -ansi -std=c++11 -pthread

#Garante que os alvos desta lista não sejam confundidos com arquivos de mesmo nome 
.PHONY:	all	clean	doxy	debug	doc

#Ao final da compilacão, remove os arquivos objetos
all: init questao1 questao2

debug:	CFLAGS += -g -O0
debug:	questao1 questao2

# Cria a pasta/diretório bin e a obj
init:
	@mkdir -p $(OBJ_DIR)/questao1
	@mkdir -p $(OBJ_DIR)/questao2	
	@mkdir -p $(BIN_DIR)

# Alvo (target) para a construcao do executavel questao1
# Define o arquivo forkBomba.o como dependência
questao1: CFLAGS+= -I$(INC_DIR)/questao1
questao1: $(OBJ_DIR)/questao1/forkBomba.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel questao1 criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto forkBomba.o
# Define os arquivos forkBomba.cpp e forkBomba.h como dependencias.
$(OBJ_DIR)/questao1/forkBomba.o: $(SRC_DIR)/questao1/forkBomba.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

questao2: CFLAGS+= -I$(INC_DIR)/questao2
questao2: $(OBJ_DIR)/questao2/hierarquiaProcessos.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel questao2 criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto hierarquiaProcessos.o
# Define o arquivo hierarquiaProcessos.cpp como dependência.
$(OBJ_DIR)/questao2/hierarquiaProcessos.o:	$(SRC_DIR)/questao2/hierarquiaProcessos.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

# Gera a documentação e remove a documentações anterior existentes
doxy:
	doxygen -g

doc:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

#removendo os .o e os binários
clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/questao1/*
	$(RM) $(OBJ_DIR)/questao2/*
	$(RM) html
	
#FIM DO MAKEFILE
