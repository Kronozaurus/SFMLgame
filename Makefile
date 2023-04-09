all: compile link

clean:
	rm -r main.o, game.o, gameobject.o, player.o, enemy.o, missle.o, missle.exe

compile:
	g++ -I src/include -c main.cpp game.cpp gameobject.cpp player.cpp enemy.cpp missle.cpp

link:
	g++ main.o -o main game.o -o game gameobject.o -o gameobject player.o -o player enemy.o -o enemy missle.o -o missle -L src/lib -l sfml-graphics -l sfml-window -l sfml-system