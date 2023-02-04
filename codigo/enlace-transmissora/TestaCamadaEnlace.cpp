#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../catch.hpp"
#include "CamadaEnlace.cpp"

vi TestaCamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(vi quadro, int tamMaxQuadro) {
    cout << "----------------------------------------------------------------" << endl;
    cout << endl;
    bitset<8> tamMaxEmByte(tamMaxQuadro);
    int tamCargaUtil = tamMaxQuadro - 1;

    int numBytes = quadro.size() / 8;

    cout << "numBytes = " << numBytes << endl;

    int numQuadrosPerfeitos = numBytes / tamCargaUtil;

    cout << "numQuadrosPerfeitos = " << numQuadrosPerfeitos << endl;
    vi resultadoEnquadramento;

    for(int i = 0; i < numQuadrosPerfeitos; i++) {
        for(int j = 7; j >= 0; j--){
            resultadoEnquadramento.pb(tamMaxEmByte[j]);
        }

        for(int k = 0; k < tamCargaUtil * 8; k++) {
            resultadoEnquadramento.pb(quadro[i*8+k]);
        }
    }

    int numBytesFaltantes = numBytes % tamCargaUtil;
    if(numBytesFaltantes) {
        cout << "numBytesFaltantes = " << numBytesFaltantes << endl;
        bitset<8> numBytesFaltantesEmByte(numBytesFaltantes+1);

        for(int i = 7; i >= 0; i--){
            resultadoEnquadramento.pb(numBytesFaltantesEmByte[i]);
        }

        for(int j = numQuadrosPerfeitos * tamCargaUtil * 8; j < quadro.size(); j++){
            resultadoEnquadramento.pb(quadro[j]);
        }
    }

    return resultadoEnquadramento;
}

TEST_CASE( " Testa CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres com todos quadros completos") {
    vi input = {0,1,1,0,0,0,0,1};
    vi expected_output = {0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,1};
    int tamMaxQuadro = 2;

    REQUIRE(expected_output == TestaCamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(input, tamMaxQuadro));

    input = {0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0};
    expected_output = {0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,1,1,1,0,0};
    tamMaxQuadro = 2;

    REQUIRE(expected_output == TestaCamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(input, tamMaxQuadro));
}

TEST_CASE( " Testa CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres com um quadro incompleto") {
    vi input = {0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0,0,0,0,1,1,0,1,0};
    vi expected_output = {0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,0,1,0};
    int tamMaxQuadro = 3;

    REQUIRE(expected_output == TestaCamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(input, tamMaxQuadro));

}
