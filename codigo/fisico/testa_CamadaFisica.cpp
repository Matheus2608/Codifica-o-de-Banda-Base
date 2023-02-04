#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../base_template.cpp"
#include "../catch.hpp"
#include "CamadaFisica.cpp"

TEST_CASE( "Funcoes de codificacao na transmissao" ) {
    vi expected_bin_output = {0,1,1,0,0,0,0,1};
    vi expected_bipolar_output = {0,1,-1,0,0,0,0,1};
    vi expected_manchester_output = {0,1,1,0,1,0,0,1,0,1,0,1,0,1,1,0};

    vi input{0,1,1,0,0,0,0,1};

    vi bin_output = CamadaFisicaTransmissoraCodificacaoBinaria(input);
    vi manchester_output = CamadaFisicaTransmissoraCodificacaoManchester(input);
    vi bipolar_output = CamadaFisicaTransmissoraCodificacaoBipolar(input);

    REQUIRE(expected_bin_output == bin_output);
    REQUIRE(expected_bipolar_output == bipolar_output);
    REQUIRE(expected_manchester_output == manchester_output);
}

TEST_CASE( "Funcoes de decodificacao no receptor") {
    vi bin_input = {0,1,1,0,0,0,0,1};
    vi bipolar_input = {0,1,-1,0,0,0,0,1};
    vi manchester_input = {0,1,1,0,1,0,0,1,0,1,0,1,0,1,1,0};

    vi expected_output{0,1,1,0,0,0,0,1};

    vi bin_output = CamadaFisicaReceptoraCodificacaoBinaria(bin_input);
    vi bipolar_output = CamadaFisicaReceptoraCodificacaoBipolar(bipolar_input);
    vi manchester_output = CamadaFisicaReceptoraCodificacaoManchester(manchester_input);

    REQUIRE(expected_output == bin_output);
    REQUIRE(expected_output == bipolar_output);
    REQUIRE(expected_output == manchester_output);
}

TEST_CASE( "Clock inicializado corretamente" ) {
    int input = 0;
    vi expected_output;

    REQUIRE(inicializadorDeClock(input) == expected_output);

    input = 2;
    vi expected_output2{0,1,0,1};

    REQUIRE(inicializadorDeClock(input) == expected_output2);
}
