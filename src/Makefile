CXX:= g++
CXXFLAGS:=-Wall
INCLUDES:= -Iinclude -Iuser
SOURCES:= src
FILES:=main.cpp angcorr_main.cpp angcorr_ggg.cpp functions.cpp a2a4.cpp
EXECUTABLES:=../bin/main	
OBJECTS:=$(FILES:.cpp=.o)

$(EXECUTABLES): $(OBJECTS) 
		$(CXX) $(INCLUDES) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLES)

%.o: $(SOURCES) /%.cpp $(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@

clean: 
	rm -rf $(EXECUTABLES) $(OBJECTS)


