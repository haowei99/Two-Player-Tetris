CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = game
OBJECTS = main.o game.o player.o cell.o gamedisplay.o numbergenerator.o blockgenerator.o commandinterpreter.o trie.o trienode.o board.o block.o iBlock.o jBlock.o lBlock.o oBlock.o sBlock.o starBlock.o tBlock.o zBlock.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

-include ${DEPENDS}