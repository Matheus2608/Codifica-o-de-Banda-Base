#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../base_template.cpp"
#include "../catch.hpp"

vi TestaCamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(vi quadro, int tamMaxQuadro) {
    int numQuadrosPerfeitos = quadro.size() / tamMaxQuadro;
    cout << numQuadrosPerfeitos << endl;
    vi resultadoEnquadramento;
    bitset<8> tamMaxEmByte(tamMaxQuadro);

    for(int i = 0; i < numQuadrosPerfeitos; i++) {
        for(int j = 7; j >= 0; j--){
            resultadoEnquadramento.pb(tamMaxEmByte[j]);
        }

        for(int k = 0; k < tamMaxQuadro; k++) {
            resultadoEnquadramento.pb(quadro[i*tamMaxQuadro+k]);
        }
    }

    int numBitsFaltantes = quadro.size() - (numQuadrosPerfeitos * tamMaxQuadro);
    if(numBitsFaltantes) {
        cout << numBitsFaltantes << endl;
        bitset<8> numBitsFaltantesEmByte(numBitsFaltantes);

        for(int j = 7; j >= 0; j--){
            resultadoEnquadramento.pb(numBitsFaltantesEmByte[j]);
        }

        for(int z = numQuadrosPerfeitos * tamMaxQuadro; z < quadro.size(); z++){
            resultadoEnquadramento.pb(quadro[z]);
        }
    }

    return resultadoEnquadramento;
}

TEST_CASE( " Testa CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres com todos quadros completos") {
    vi input = {0,1,1,0,0,0,0,1};
    int tamMaxQuadro = 4;

    vi expected_output = {0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,1};

    REQUIRE(expected_output == TestaCamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(input, tamMaxQuadro));
}

TEST_CASE( " Testa CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres com um quadro incompleto") {

    input = {0,1,1,0,0,0,0,1,1};
    tamMaxQuadro = 4;

    expected_output = {0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1};
    REQUIRE(expected_output == TestaCamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(input, tamMaxQuadro));
}
