CC = g++
CFLAGS = -Wall -std=c++11 -O2 -lm -g
SOURCES = CamadaFisica.cpp Simulador.cpp testa_CamadaFisica.cpp
OBJECTS = CamadaFisica.o Simulador.o testa_CamadaFisica.o
PROGRAM = CamadaFisica
TEST = test_CamadaFisica

all: $(PROGRAM) $(TEST)

$(PROGRAM): CamadaFisica.o Simulador.o
	$(CC) $(CFLAGS) CamadaFisica.o Simulador.o -o $(PROGRAM)

$(TEST): testa_CamadaFisica.o CamadaFisica.o
	$(CC) $(CFLAGS) testa_CamadaFisica.o CamadaFisica.o -o $(TEST)

CamadaFisica.o: CamadaFisica.cpp headers/CamadaFisica.hpp
	$(CC) $(CFLAGS) -c CamadaFisica.cpp -o CamadaFisica.o

Simulador.o: simulador.cpp
	$(CC) $(CFLAGS) -c simulador.cpp -o Simulador.o -lpthread

testa_CamadaFisica.o: testa_CamadaFisica.cpp headers/catch.hpp headers/CamadaFisica.hpp
	$(CC) $(CFLAGS) -c testa_CamadaFisica.cpp -o testa_CamadaFisica.o

run: CamadaFisica
	./CamadaFisica

test: test_CamadaFisica
	./test_CamadaFisica

clean:
	rm -rf $(PROGRAM) $(TEST) $(OBJECTS)
