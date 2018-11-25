CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = generator
OBJECTS = main.o blockgenerator.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

-include ${DEPENDS}