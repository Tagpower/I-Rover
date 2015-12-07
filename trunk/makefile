CXX=gcc
CFXXLAGS=


main: main.o
robot.o: robot.cpp robot.hpp
ennemi.o: ennemi.cpp ennemi.hpp
ennemi.hpp robot.hpp: personnage.o
personnage.o: personnage.cpp personnage.hpp
coffre.o: coffre.cpp coffre.hpp
coffre.hpp: clef.o
clef.o: clef.cpp clef.hpp
