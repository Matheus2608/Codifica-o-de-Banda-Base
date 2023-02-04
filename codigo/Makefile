CC = g++
CFLAGS = -Wall -std=c++11 -O2 -lm -g
PROGRAM = Simulador

# Camada Aplicacao Transmissora
OBJECT_APLICACAO_T = aplicacao-transmissora/Aplicacao.o

$(OBJECT_APLICACAO_T):
	$(CC) $(CFLAGS) -c aplicacao-transmissora/Aplicacao.cpp  -o $(OBJECT_APLICACAO_T)

# Camada Aplicacao Receptora
OBJECT_APLICACAO_R = aplicacao-receptora/Aplicacao.o

$(OBJECT_APLICACAO_R):
	$(CC) $(CFLAGS) -c aplicacao-receptora/Aplicacao.cpp  -o $(OBJECT_APLICACAO_R)


# Camada Enlace
TEST_ENLACE = enlace/TestaCamadaEnlace
OBJECT_ENLACE = enlace/CamadaEnlace.o

$(TEST_ENLACE): $(OBJECT_ENLACE)
	$(CC) $(CFLAGS) enlace/TestaCamadaEnlace.cpp $(OBJECT_ENLACE) -o $(TEST_ENLACE)

$(OBJECT_ENLACE): enlace/CamadaEnlace.cpp
	$(CC) $(CFLAGS) -c enlace/CamadaEnlace.cpp -o $(OBJECT_ENLACE)

test-enlace: $(TEST_ENLACE)
	./enlace/TestaCamadaEnlace


# Camada Fisica
OBJECT_FISICA = fisica/CamadaEnlace.o
TEST_FISICA = fisica/TestaCamadaFisica

$(TEST_FISICA): $(OBJECT_FISICA)
	$(CC) $(CFLAGS) fisica/TestaCamadaFisica.cpp $(OBJECT_FISICA) -o $(TEST_FISICA)

$(OBJECT_FISICA): fisica/CamadaFisica.cpp
	$(CC) $(CFLAGS) -c fisica/CamadaFisica.cpp -o $(OBJECT_FISICA)

test-fisica: $(TEST_FISICA)
	./fisica/TestaCamadaFisica


# Main
OBJECTS = $(OBJECT_ENLACE) $(OBJECT_FISICA) $(OBJECT_APLICACAO_T) $(OBJECT_APLICACAO_R)
TESTS = $(TEST_ENLACE) $(TEST_FISICA)

$(PROGRAM): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) Simulador.cpp -o $(PROGRAM)

test: test-enlace test-fisica

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -rf $(PROGRAM) $(TESTS) $(OBJECTS)
