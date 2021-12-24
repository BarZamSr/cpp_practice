CXXFLAGS=-std=c++11

program.exe: main.cpp utils.o list.o
	clang++ $(CXXFLAGS) main.cpp list.o -o program.exe

%.o: %.c
	clang++ $(CXXFLAGS) -c %< -o %@

clean:
	rm -f *.o *.exe
