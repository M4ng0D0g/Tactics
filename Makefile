CXX = g++
CXXFLAGS = -Wall -g
SRC = src/main.cpp src/Player.cpp src/Enemy.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = build/game.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
