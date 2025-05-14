PROJ_NAME = feedforward_network
TEST_NAME = test_runner
SRC_DIR = src
INC_DIR = include
OBJ_DIR = objects

CXX =  g++ -std=c++11
CXXFLAGS = -c -W -Wall -pedantic -I$(INC_DIR)
RM = rm -rf

MAIN_OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/ffn.o $(OBJ_DIR)/layer.o $(OBJ_DIR)/neuron.o
TEST_OBJS = $(OBJ_DIR)/test_runner.o $(OBJ_DIR)/ffn.o $(OBJ_DIR)/layer.o $(OBJ_DIR)/neuron.o

all: $(OBJ_DIR) $(PROJ_NAME)

# === Compilação do programa principal ===
$(PROJ_NAME): $(MAIN_OBJS)
	$(CXX) -o $@ $^

test: $(OBJ_DIR) $(TEST_NAME)

$(TEST_NAME): $(TEST_OBJS)
	$(CXX) -o $@ $^

$(OBJ_DIR)/main.o: main.cpp $(INC_DIR)/ffn.h $(INC_DIR)/xor.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/test_runner.o: test_runner.cpp $(INC_DIR)/ffn.h $(INC_DIR)/xor.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/ffn.o: $(SRC_DIR)/ffn.cpp $(INC_DIR)/ffn.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/layer.o: $(SRC_DIR)/layer.cpp $(INC_DIR)/layer.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/neuron.o: $(SRC_DIR)/neuron.cpp $(INC_DIR)/neuron.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# === Limpeza ===
clean:
	@$(RM) $(OBJ_DIR) $(PROJ_NAME) $(TEST_NAME) resultados_xor.txt *~

.PHONY: all clean test
