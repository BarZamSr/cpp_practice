main.exe: main.cpp utils.o str.o
	clang++ main.cpp utils.o str.o -o main.exe

str.o: str.cpp str.h
	clang++ -c str.cpp -o str.o

utils.o: utils.cpp utils.h
	clang++ -c utils.cpp -o utils.o

clean:
	rm -f *.o main.exe
