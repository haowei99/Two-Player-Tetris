CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = interpreter
OBJECTS = main.o commandinterpreter.o trienode.o trie.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

-include ${DEPENDS}