#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../catch.hpp"
#include "CamadaEnlace.hpp"

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

        for(int k = i*8; k < i*8 + (tamCargaUtil * 8); k++) {
            resultadoEnquadramento.pb(quadro[k]);
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


vi TestaCamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(vi quadro, int tamMaxQuadro) {

    cout << "--------------------------------------------------------------------------------" << endl;
    vi ByteDeFlag{0,0,0,0,1,1,1,1}, ByteEsc{1,1,1,1,0,0,0,0}, resultadoEnquadramento;

    int numBytes = quadro.size() / 8;
    int numQuadrosPerfeitos = numBytes / tamMaxQuadro;

    cout << "numBytes = " << numBytes << endl;
    cout << "numQuadrosPerfeitos = " << numQuadrosPerfeitos << endl;

    for(int i = 0; i < numQuadrosPerfeitos; i++) {
        for(int j = 0; j < 8; j++){
            resultadoEnquadramento.pb(ByteDeFlag[j]);
        }

        for(int k = i*8; k < i*8 + (tamMaxQuadro * 8); k++) {
            vi temp;
            if(k%8==0) {
                for(int z = k; z < k + 8; z++){
                    temp.pb(quadro[z]);
                }
                if(are_vectors_equal(temp, ByteDeFlag)){
                    for(int a = 0; a < 8; a++){
                        resultadoEnquadramento.pb(ByteEsc[a]);
                    }
                }
            }

            resultadoEnquadramento.pb(quadro[k]);
        }

        for(int j = 0; j < 8; j++){
            resultadoEnquadramento.pb(ByteDeFlag[j]);
        }
    }

    int numBytesFaltantes = numBytes % tamMaxQuadro;
    if(numBytesFaltantes) {
        for(int i = 0; i < 8; i++){
            resultadoEnquadramento.pb(ByteDeFlag[i]);
        }

        for(int j = numQuadrosPerfeitos * tamMaxQuadro * 8; j < quadro.size(); j++){
            resultadoEnquadramento.pb(quadro[j]);
        }

        for(int k = 0; k < 8; k++){
            resultadoEnquadramento.pb(ByteDeFlag[k]);
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

TEST_CASE( " Testa CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes com todos quadros completos") {
    vi input = {0,1,1,0,0,0,0,1};
    vi expected_output = {0,0,0,0,1,1,1,1,0,1,1,0,0,0,0,1,0,0,0,0,1,1,1,1};
    int tamMaxQuadro = 1;

    REQUIRE(expected_output == TestaCamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(input, tamMaxQuadro));

    input = {0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0};
    expected_output = {0,0,0,0,1,1,1,1,0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0,0,0,0,0,1,1,1,1};
    tamMaxQuadro = 2;

    REQUIRE(expected_output == TestaCamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(input, tamMaxQuadro));

    input = {0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0};
    expected_output = {0,0,0,0,1,1,1,1,0,1,1,0,0,0,0,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,1,0,1,1,1,0,0,0,0,0,0,1,1,1,1};
    tamMaxQuadro = 1;

    REQUIRE(expected_output == TestaCamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(input, tamMaxQuadro));
}

TEST_CASE( " Testa CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes com um quadro incompleto") {
    vi input = {0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0,0,0,0,1,1,0,1,0};
    vi expected_output = {0,0,0,0,1,1,1,1,0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,1,1,0,1,0,0,0,0,0,1,1,1,1};
    int tamMaxQuadro = 2;

    REQUIRE(expected_output == TestaCamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(input, tamMaxQuadro));

}

TEST_CASE( " Testa CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes com um byte igual o byteFlag") {
    vi input = {0,0,0,0,1,1,1,1};
    vi expected_output = {0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1};
    int tamMaxQuadro = 1;

    REQUIRE(expected_output == TestaCamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(input, tamMaxQuadro));

    input = {0,1,1,0,0,0,0,1,  0,0,0,0,1,1,1,1,     0,0,0,1,1,0,1,0};
    expected_output = {0,0,0,0,1,1,1,1,  0,1,1,0,0,0,0,1,   1,1,1,1,0,0,0,0,  0,0,0,0,1,1,1,1,  0,0,0,0,1,1,1,1,  0,0,0,0,1,1,1,1,  0,0,0,1,1,0,1,0,  0,0,0,0,1,1,1,1};
    tamMaxQuadro = 2;

    REQUIRE(expected_output == TestaCamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(input, tamMaxQuadro));
}
