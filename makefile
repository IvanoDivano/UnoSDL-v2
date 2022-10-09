debug:
	g++ -c src/*.cpp -std=c++14 -g -Wall -m64 -I include && g++ *.o -o bin/debug/main -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf && ./bin/debug/main
release:
	g++ -c src/*.cpp -std=c++14 -O3 -Wall -m64 -I include && g++ *.o -o bin/release/main -s -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf && ./bin/release/main
