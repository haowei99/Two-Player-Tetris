CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = interface
OBJECTS = main.o game.o player.o display.o cell.o gamedisplay.o numbergenerator.o blockgenerator.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

-include ${DEPENDS}