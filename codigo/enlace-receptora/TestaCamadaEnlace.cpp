#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../catch.hpp"
#include "CamadaEnlace.hpp"

TEST_CASE( " Testa CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres com todos quadros completos") {
    vi input = {0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,1};
    vi expected_output = {0,1,1,0,0,0,0,1};

    REQUIRE(expected_output == CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(input));

    input = {0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,1,1,1,0,0};
    expected_output = {0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0};

    REQUIRE(expected_output == CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(input));
}

TEST_CASE( " Testa CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres com um quadro incompleto") {
    vi input = {0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,0,1,0};
    vi expected_output = {0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0,0,0,0,1,1,0,1,0};

    REQUIRE(expected_output == CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(input));
}

TEST_CASE( " Testa CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes com todos quadros completos") {
    vi input = {0,0,0,0,1,1,1,1,0,1,1,0,0,0,0,1,0,0,0,0,1,1,1,1};
    vi expected_output = {0,1,1,0,0,0,0,1};

    REQUIRE(expected_output == CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(input));

    input = {0,0,0,0,1,1,1,1,0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0,0,0,0,0,1,1,1,1};
    expected_output = {0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0};

    REQUIRE(expected_output == CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(input));

    input = {0,0,0,0,1,1,1,1,0,1,1,0,0,0,0,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,1,0,1,1,1,0,0,0,0,0,0,1,1,1,1};
    expected_output = {0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0};

    REQUIRE(expected_output == CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(input));
}

TEST_CASE( " Testa CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes com um quadro incompleto") {
    vi input = {0,0,0,0,1,1,1,1,0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,1,1,0,1,0,0,0,0,0,1,1,1,1};
    vi expected_output = {0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0,0,0,0,1,1,0,1,0};

    REQUIRE(expected_output == CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(input));
}

TEST_CASE( " Testa CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes com um quadro incompleto") {
    vi input = {0,0,0,0,1,1,1,1,0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,1,1,0,1,0,0,0,0,0,1,1,1,1};
    vi expected_output = {0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0,0,0,0,1,1,0,1,0};

    REQUIRE(expected_output == CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(input));
}

TEST_CASE( " Testa CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes com um byte igual o byteFlag") {
    vi input = {0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1};
    vi expected_output = {0,0,0,0,1,1,1,1};
    REQUIRE(expected_output == CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(input));

    input = {0,0,0,0,1,1,1,1,  0,1,1,0,0,0,0,1,   1,1,1,1,0,0,0,0,  0,0,0,0,1,1,1,1,  0,0,0,0,1,1,1,1,  0,0,0,0,1,1,1,1,  0,0,0,1,1,0,1,0,  0,0,0,0,1,1,1,1};
    expected_output = {0,1,1,0,0,0,0,1,  0,0,0,0,1,1,1,1,     0,0,0,1,1,0,1,0};
    REQUIRE(expected_output == CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(input));
}
