PROJ_NAME = feedforward_network
SRC_DIR = src
INC_DIR = include
OBJ_DIR = objects

CXX =  g++ -std=c++11
CXXFLAGS = -c -W -Wall -pedantic -I$(INC_DIR)
RM = rm -rf

OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/ffn.o $(OBJ_DIR)/layer.o $(OBJ_DIR)/neuron.o

all: $(OBJ_DIR) $(PROJ_NAME)

$(PROJ_NAME): $(OBJS)
	$(CXX) -o $@ $(OBJS)

$(OBJ_DIR)/main.o: main.cpp $(INC_DIR)/ffn.h $(INC_DIR)/xor.h
	$(CXX) $(CXXFLAGS) main.cpp -o $@

$(OBJ_DIR)/ffn.o: $(SRC_DIR)/ffn.cpp $(INC_DIR)/ffn.h 
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/ffn.cpp -o $@

$(OBJ_DIR)/layer.o: $(SRC_DIR)/layer.cpp $(INC_DIR)/layer.h
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/layer.cpp -o $@

$(OBJ_DIR)/neuron.o: $(SRC_DIR)/neuron.cpp $(INC_DIR)/neuron.h
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/neuron.cpp -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJ_DIR) $(PROJ_NAME) *~

.PHONY: all clean
