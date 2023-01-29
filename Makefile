all: CamadaFisica.o testa_CamadaFisica.cpp
	g++ -std=c++11 -Wall  CamadaFisica.o testa_CamadaFisica.cpp -o testa_CamadaFisica


CamadaFisica.cpp : CamadaFisica.cpp CamadaFisica.hpp
	g++ -std=c++11 -Wall  -c CamadaFisica.cpp

clean:
	rm -rf *.o *.exe
