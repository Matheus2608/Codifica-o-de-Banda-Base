#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../catch.hpp"
#include "CamadaEnlace.hpp"

TEST_CASE( " Testa CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres com todos quadros completos") {
    vi input = {0,1,1,0,0,0,0,1};
    vi expected_output = {0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,1};
    int tamMaxQuadro = 2;

    REQUIRE(expected_output == CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(input, tamMaxQuadro));

    input = {0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0};
    expected_output = {0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,1,1,1,0,0};
    tamMaxQuadro = 2;

    REQUIRE(expected_output == CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(input, tamMaxQuadro));
}

TEST_CASE( " Testa CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres com um quadro incompleto") {
    vi input = {0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0,0,0,0,1,1,0,1,0};
    vi expected_output = {0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,0,1,0};
    int tamMaxQuadro = 3;

    REQUIRE(expected_output == CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(input, tamMaxQuadro));

}

// TEST_CASE( " Testa CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes com todos quadros completos") {
//     vi input = {0,1,1,0,0,0,0,1};
//     vi expected_output = {};
//     int tamMaxQuadro = 2;

//     REQUIRE(expected_output == CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(input, tamMaxQuadro));

// }
