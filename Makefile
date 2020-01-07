CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -g

SRCS =  pieces.cpp chessboard.cpp
OBJS = ${SRCS:.cpp=.o}
HEADERS = 

MAIN = chessgame

all: ${MAIN}
	        @echo   Project has been made

${MAIN}: ${OBJS}
	        ${CXX} ${CXXFLAGS} ${OBJS} -o ${MAIN}

.cpp.o:
	        ${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	        ${RM} ${PROGS} ${OBJS} *.o *~.
