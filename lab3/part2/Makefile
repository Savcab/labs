CXX = g++
CPPFLAGS = -Wall -g -Ilib
BIN_DIR = bin
LIB_DIR = lib
SRC_DIR = src

all: $(BIN_DIR)/.dirstamp $(BIN_DIR)/pokemon

$(BIN_DIR)/pokemon: $(SRC_DIR)/main.cpp $(BIN_DIR)/attackMove.o $(BIN_DIR)/battle.o $(BIN_DIR)/pokemon.o
	$(CXX) $(CPPFLAGS) $^ -o $@

$(BIN_DIR)/attackMove.o: $(SRC_DIR)/attackMove.cpp $(LIB_DIR)/attackMove.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR)/battle.o: $(SRC_DIR)/battle.cpp $(LIB_DIR)/battle.h $(LIB_DIR)/attackMove.h
	 $(CXX) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR)/pokemon.o: $(SRC_DIR)/pokemon.cpp $(LIB_DIR)/pokemon.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR)/.dirstamp: 
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp

.PHONY: clean
clean: 
	rm -rf $(BIN_DIR)