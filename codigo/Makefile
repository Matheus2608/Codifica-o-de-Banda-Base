CC = g++
CFLAGS = -Wall -std=c++11 -O2 -lm -g
PROGRAM = Simulador.out

# Utils
UTILS_OBJECT = utils/utils.o
$(UTILS_OBJECT):
	$(CC) $(CFLAGS) -c utils/utils.cpp  -o $(UTILS_OBJECT)

# Camada Aplicacao Transmissora
OBJECT_APLICACAO_T = aplicacao-transmissora/Aplicacao.o

$(OBJECT_APLICACAO_T):
	$(CC) $(CFLAGS) -c aplicacao-transmissora/Aplicacao.cpp  -o $(OBJECT_APLICACAO_T)

# Camada Aplicacao Receptora
OBJECT_APLICACAO_R = aplicacao-receptora/Aplicacao.o

$(OBJECT_APLICACAO_R):
	$(CC) $(CFLAGS) -c aplicacao-receptora/Aplicacao.cpp -o $(OBJECT_APLICACAO_R)

# Camada Enlace Transmissora
ENLACE-T-PATH = enlace-transmissora
TEST_ENLACE-T = $(ENLACE-T-PATH)/TestaCamadaEnlace.out
OBJECT_ENLACE-T = $(ENLACE-T-PATH)/CamadaEnlace.o

$(TEST_ENLACE-T): $(OBJECT_ENLACE-T) $(UTILS_OBJECT)
	$(CC) $(CFLAGS) $(ENLACE-T-PATH)/TestaCamadaEnlace.cpp $(UTILS_OBJECT) $(OBJECT_ENLACE-T) -o $(TEST_ENLACE-T)

$(OBJECT_ENLACE-T): $(UTILS_OBJECT)
	$(CC) $(CFLAGS) -c $(ENLACE-T-PATH)/CamadaEnlace.cpp $(UTILS_OBJECT) -o $(OBJECT_ENLACE-T)

test-enlace-t: $(TEST_ENLACE-T)
	./$(TEST_ENLACE-T)

# Camada Enlace Receptora 
ENLACE-R-PATH = enlace-receptora
TEST_ENLACE-R = $(ENLACE-R-PATH)/TestaCamadaEnlace.out
OBJECT_ENLACE-R = $(ENLACE-R-PATH)/CamadaEnlace.o

$(TEST_ENLACE-R): $(OBJECT_ENLACE-R) $(UTILS_OBJECT)
	$(CC) $(CFLAGS) $(ENLACE-R-PATH)/TestaCamadaEnlace.cpp $(UTILS_OBJECT) $(OBJECT_ENLACE-R) -o $(TEST_ENLACE-R)

$(OBJECT_ENLACE-R): $(UTILS_OBJECT)
	$(CC) $(CFLAGS) -c $(ENLACE-R-PATH)/CamadaEnlace.cpp $(UTILS_OBJECT) -o $(OBJECT_ENLACE-R)

test-enlace-r: $(TEST_ENLACE-R)
	./$(TEST_ENLACE-R)


# Camada Fisica
OBJECT_FISICA = fisica/CamadaEnlace.o
TEST_FISICA = fisica/TestaCamadaFisica.out

$(TEST_FISICA): $(OBJECT_FISICA) $(UTILS_OBJECT)
	$(CC) $(CFLAGS) fisica/TestaCamadaFisica.cpp $(UTILS_OBJECT) $(OBJECT_FISICA) -o $(TEST_FISICA)

$(OBJECT_FISICA): fisica/CamadaFisica.cpp $(UTILS_OBJECT)
	$(CC) $(CFLAGS) -c fisica/CamadaFisica.cpp $(UTILS_OBJECT) -o $(OBJECT_FISICA)

test-fisica: $(TEST_FISICA)
	./fisica/TestaCamadaFisica.out


# Main
OBJECTS = $(OBJECT_ENLACE-R) $(OBJECT_ENLACE-T) $(OBJECT_FISICA) $(OBJECT_APLICACAO_T) $(OBJECT_APLICACAO_R) $(UTILS_OBJECT)
TESTS = $(TEST_ENLACE-R) $(TEST_ENLACE-T) $(TEST_FISICA)

$(PROGRAM): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) Simulador.cpp -o $(PROGRAM)

test: test-enlace-t test-enlace-r test-fisica

run: $(PROGRAM)
	@echo "\n------------------------------------------------------------------------------------------------\n"
	@echo "Para alterar as opções padrões modifique o arquivo constantes.cpp, escreva make clean e make run novamente\n"
	@./$(PROGRAM)

clean:
	rm -rf $(PROGRAM) $(TESTS) $(OBJECTS)
