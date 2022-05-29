vector: source file_gen.o funkcijos_file.o funkcijos_manual.o 
	g++ -o source source.o file_gen.o funkcijos_file.o funkcijos_manual.o -O2 
source:
	g++ -c Source.cpp
file_gen:
	g++ -c file_gen.cpp
funkcijos_file:
	g++ -c funkcijos_file.cpp
funkcijos_manual:
	g++ -c funkcijos_manual.cpp
test: file_gen.o funkcijos_file.o funkcijos_manual.o 
	g++ -o test tests.cpp file_gen.o funkcijos_file.o funkcijos_manual.o
	