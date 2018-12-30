CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla -L/usr/X11R6/lib  
EXEC = biquadris -lX11
OBJECTS = window.o main.o game.o player.o cell.o gamedisplay.o numbergenerator.o blockgenerator.o commandinterpreter.o trie.o trienode.o board.o block.o iBlock.o jBlock.o lBlock.o oBlock.o sBlock.o starBlock.o tBlock.o zBlock.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

-include ${DEPENDS}