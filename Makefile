CXXFLAGS=-std=c++11

program.exe: main.cpp *.o
	clang++ $(CXXFLAGS) main.cpp *.o -o program.exe

%.o: %.c
	clang++ $(CXXFLAGS) -c %< -o %@

clean:
	rm -f *.o *.exe
