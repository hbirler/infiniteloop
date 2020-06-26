


looper: main.o a.o
	g++ main.o a.o -o looper
	
a.o: a.cpp
	g++ -c a.cpp -O2
	
main.o: main.cpp
	g++ -c main.cpp -O2
	
	