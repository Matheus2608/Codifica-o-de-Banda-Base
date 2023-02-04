CC = g++
CFLAGS = -Wall -std=c++11 -O2 -lm -g
PROGRAM = Simulador

# Camada Enlace
TEST_ENLACE = enlace/TestaCamadaEnlace
OBJECT_ENLACE = enlace/CamadaEnlace.o

$(TEST_ENLACE): $(OBJECT_ENLACE)
	$(CC) $(CFLAGS) enlace/TestaCamadaEnlace.cpp $(OBJECT_ENLACE) -o $(TEST_ENLACE)

$(OBJECT_ENLACE): enlace/CamadaEnlace.cpp
	$(CC) $(CFLAGS) -c enlace/CamadaEnlace.cpp -o $(OBJECT_ENLACE)

test_enlace: $(TEST_ENLACE)
	./enlace/TestaCamadaEnlace


# Camada Fisica
OBJECT_FISICA = fisica/CamadaEnlace.o
TEST_FISICA = fisica/TestaCamadaFisica

$(TEST_FISICA): $(OBJECT_FISICA)
	$(CC) $(CFLAGS) fisica/TestaCamadaFisica.cpp $(OBJECT_FISICA) -o $(TEST_FISICA)

$(OBJECT_FISICA): fisica/CamadaFisica.cpp
	$(CC) $(CFLAGS) -c fisica/CamadaFisica.cpp -o $(OBJECT_FISICA)

test_fisica: $(TEST_FISICA)
	./fisica/TestaCamadaFisica


# Main
OBJECTS = $(OBJECT_ENLACE) $(OBJECT_FISICA)
TESTS = $(TEST_ENLACE) $(TEST_FISICA)

$(PROGRAM): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) Simulador.cpp -o $(PROGRAM)

test: test_enlace test_fisica

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -rf $(PROGRAM) $(TESTS) $(OBJECTS)
