CXX=g++
CXXFLAGS=x
LOADLIBS=x
EXEC=irover
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp = .o)
PACKAGES = clanCore-4.0 clanDisplay-4.0 clanApp-4.0 clanGL-4.0 LIBS = `pkg-config --cflags --libs $(PACKAGES)`

.PHONY:clean

all:$(EXEC)

$(EXEC): $(OBJ)
	@$(CXX) -o $(EXEC) $(OBJ) -pthread $(OBJS) $(LIBS) 
	
$(SRC): %.cpp: %.hpp
	touch $@
	
clean:
	-rm $(OBJ)
	-rm $(EXEC)


 
