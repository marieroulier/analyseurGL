# Couleurs pour l'affichage
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BOLD = \033[1m
NC = \033[0m # Pas de couleur

# Compilateur
CC = g++

# Sources et objets
INTERFACE := $(wildcard *.h)
REALISATION := $(INTERFACE:.h=.cpp)
OBJETS := $(REALISATION:.cpp=.o) main.o

# Exécutables
EXE_BIN = automate

all: $(EXE_BIN)

$(EXE_BIN): $(OBJETS)
	@echo "$(YELLOW)Génération de $@...$(NC)"
	$(CC) -o $@ $^
	@echo "$(GREEN)$(BOLD)$@ a été généré avec succès !$(NC)\r\n"
%.o: %.cpp
	@echo "$(YELLOW)Compilation de $<...$(NC)"
	$(CC) -c $< -o $@

clean:
	@echo "$(RED)Suppression des fichiers objets et des exécutables...$(NC)"
	rm -f *.o $(EXE_BIN)

.PHONY: all clean
