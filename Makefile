CXXFLAGS=-std=c++11

program.exe: main.cpp utils.o str.o
	clang++ $(CXXFLAGS) main.cpp utils.o str.o -o program.exe

str.o: str.cpp str.h
	clang++ $(CXXFLAGS) -c str.cpp -o str.o

utils.o: utils.cpp utils.h
	clang++ $(CXXFLAGS) -c utils.cpp -o utils.o

clean:
	rm -f *.o *.exe
