cmake_minimum_required(VERSION 3.12)
project(Final_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Final_Project main.cpp block.h block.cpp cell.h cell.cpp board.h board.cpp
        oBlock.h oBlock.cpp iBlock.cpp iBlock.h sBlock.h sBlock.cpp zBlock.h
        zBlock.cpp lBlock.h lBlock.cpp tBlock.h tBlock.cpp jBlock.h jBlock.cpp starBlock.cpp starBlock.h)