all:
	g++ example.cpp -o example

run: 
	g++ example.cpp -o example
	./example

clear:
	rm example
