hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/TekBagliListe.o -c ./src/TekBagliListe.cpp
	g++ -I ./include/ -o ./bin/Main ./lib/Dugum.o ./lib/TekBagliListe.o ./src/Main.cpp
	
calistir:
	./bin/Main