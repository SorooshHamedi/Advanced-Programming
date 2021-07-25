CC := g++ -std=c++11 -g
RSDLFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
RSDL_DIR = RSDL/src 
BUILD_DIR = build

.PHONY: all
all: makedir soccerStars.out

soccerStars.out: $(BUILD_DIR)/main.o $(BUILD_DIR)/SoccerStars.o $(BUILD_DIR)/Pawn.o $(BUILD_DIR)/Pitch.o $(BUILD_DIR)/rsdl.o $(BUILD_DIR)/Ball.o $(BUILD_DIR)/Player.o $(BUILD_DIR)/MathFunctions.o $(BUILD_DIR)/GeometricVector.o
	$(CC) $(BUILD_DIR)/main.o $(BUILD_DIR)/SoccerStars.o $(BUILD_DIR)/Pawn.o $(BUILD_DIR)/Pitch.o $(BUILD_DIR)/Ball.o $(BUILD_DIR)/Player.o $(BUILD_DIR)/MathFunctions.o $(BUILD_DIR)/GeometricVector.o $(BUILD_DIR)/rsdl.o $(RSDLFLAGS) -o soccerStars.out

$(BUILD_DIR)/main.o: main.cpp SoccerStars.hpp Pawn.hpp Pitch.hpp SoccerStarsConst.hpp Ball.hpp Player.hpp MathFunctions.hpp rsdl.hpp GeometricVector.hpp
	$(CC) -c main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/SoccerStars.o: SoccerStars.cpp SoccerStars.hpp Pawn.hpp Pitch.hpp rsdl.hpp SoccerStarsConst.hpp Ball.hpp Player.hpp MathFunctions.hpp GeometricVector.hpp
	$(CC) -c SoccerStars.cpp -o $(BUILD_DIR)//SoccerStars.o

$(BUILD_DIR)/Pawn.o: Pawn.hpp Pawn.cpp Pitch.hpp rsdl.hpp SoccerStarsConst.hpp MathFunctions.hpp GeometricVector.hpp Ball.hpp
	$(CC) -c Pawn.cpp -o $(BUILD_DIR)/Pawn.o

$(BUILD_DIR)/Pitch.o: Pitch.hpp Pitch.cpp Pawn.hpp rsdl.hpp SoccerStarsConst.hpp MathFunctions.hpp GeometricVector.hpp
	$(CC) -c Pitch.cpp -o $(BUILD_DIR)/Pitch.o

$(BUILD_DIR)/Ball.o: Ball.hpp Ball.cpp SoccerStarsConst.hpp Pitch.hpp rsdl.hpp MathFunctions.hpp GeometricVector.hpp 
	$(CC) -c Ball.cpp -o $(BUILD_DIR)/Ball.o

$(BUILD_DIR)/Player.o: Player.hpp Player.cpp Pawn.hpp SoccerStarsConst.hpp MathFunctions.hpp GeometricVector.hpp
	$(CC) -c Player.cpp -o $(BUILD_DIR)/Player.o

$(BUILD_DIR)/MathFunctions.o: MathFunctions.hpp MathFunctions.cpp rsdl.hpp GeometricVector.hpp
	$(CC) -c MathFunctions.cpp -o $(BUILD_DIR)/MathFunctions.o

$(BUILD_DIR)/GeometricVector.o: GeometricVector.hpp GeometricVector.cpp
	$(CC) -c GeometricVector.cpp -o $(BUILD_DIR)/GeometricVector.o

$(BUILD_DIR)/rsdl.o: rsdl.cpp rsdl.hpp
	$(CC) -c rsdl.cpp -o $(BUILD_DIR)/rsdl.o

makedir:
	mkdir -p $(BUILD_DIR)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
