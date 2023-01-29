CC = g++
CFLAGS = -Wall -std=c++11 -O2 -lm -g
SOURCES = CamadaFisica.cpp testa_CamadaFisica.cpp
OBJECTS = CamadaFisica.o testa_CamadaFisica.o
PROGRAM = CamadaFisica
TEST = test_CamadaFisica

all: $(PROGRAM) $(TEST)

$(PROGRAM): CamadaFisica.o
	$(CC) $(CFLAGS) CamadaFisica.o -o $(PROGRAM)

$(TEST): testa_CamadaFisica.o
	$(CC) $(CFLAGS) testa_CamadaFisica.o -o $(TEST)

CamadaFisica.o: CamadaFisica.cpp
	$(CC) $(CFLAGS) -c CamadaFisica.cpp -o CamadaFisica.o

testa_CamadaFisica.o: testa_CamadaFisica.cpp
	$(CC) $(CFLAGS) -c testa_CamadaFisica.cpp -o testa_CamadaFisica.o

run: CamadaFisica
	./CamadaFisica

test: CamadaFisica
	./testa_CamadaFisica

clean:
	rm -rf $(PROGRAM) $(TEST) $(OBJECTS)
