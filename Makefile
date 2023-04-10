CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = watopoly
OBJECTS = main.o textdisplay.o residence.o gym.o property.o nonproperty.o board.o brown.o ltblue.o pink.o orange.o red.o yellow.o green.o blue.o slc.o needles.o coopfee.o dctims.o goose.o gototims.o osap.o player.o tuition.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
