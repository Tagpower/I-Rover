CXX=g++
CXXFLAGS=x
LOADLIBS=x
EXEC=irover
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp = .o)


.PHONY:clean

all:$(EXEC)

$(EXEC): $(OBJ)
	@$(CXX) -o $(EXEC) $(OBJ)
	
$(SRC): %.cpp: %.hpp
	touch $@
	
clean:
	-rm $(OBJ)
	-rm $(EXEC)
