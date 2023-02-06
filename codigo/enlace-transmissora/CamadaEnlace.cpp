#include "../base-template.hpp"
#include "../constantes.cpp"
#include "../fisica/CamadaFisica.hpp"



vi CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(vi quadro) {
    bitset<8> tamMaxEmByte(QTD_MAX_BYTES_QUADRO);
    int tamCargaUtil = QTD_MAX_BYTES_QUADRO - 1;


    int numBytes = quadro.size() / 8;
    int numQuadrosPerfeitos = numBytes / tamCargaUtil;

    vi resultadoEnquadramento;

    for(int i = 0; i < numQuadrosPerfeitos; i++) {
        for(int j = 7; j >= 0; j--){
            resultadoEnquadramento.pb(tamMaxEmByte[j]);
        }

        for(int k = 0; k < tamCargaUtil * 8; k++) {
            resultadoEnquadramento.pb(quadro[i*8*tamCargaUtil+k]);
        }
    }

    int numBytesFaltantes = numBytes % tamCargaUtil;
    if(numBytesFaltantes) {

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

vi CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(vi quadro) {
    vi ByteDeFlag{0,0,0,0,1,1,1,1}, ByteEsc{1,1,1,1,0,0,0,0}, resultadoEnquadramento;

    int tamCargaUtil = QTD_MAX_BYTES_QUADRO - 1;
    int numBytes = quadro.size() / 8;
    int numQuadrosPerfeitos = numBytes / tamCargaUtil;

    for(int i = 0; i < numQuadrosPerfeitos; i++) {
        for(int j = 0; j < 8; j++){
            resultadoEnquadramento.pb(ByteDeFlag[j]);
        }

        for(int k = 0; k < tamCargaUtil * 8; k++) {
            resultadoEnquadramento.pb(quadro[i*8*tamCargaUtil+k]);
        }

        for(int j = 0; j < 8; j++){
            resultadoEnquadramento.pb(ByteDeFlag[j]);
        }
    }

    return resultadoEnquadramento;
}

void CamadaEnlaceDadosTransmissoraEnquadramento(vi quadro) {
    cout << "Enquadrado pacote ..." << endl;
    vi pacoteEnquadrado;

    switch (TIPO_DE_ENQUADRAMENTO) {
    case 0:
        pacoteEnquadrado = CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(quadro);
        break;

    case 1:
        pacoteEnquadrado = CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(quadro);
        break;
    }

    cout << "Resultado do enquadramento:" << endl;
    for(int bit : pacoteEnquadrado) cout << bit << " "; cout << endl;

    CamadaFisicaTransmissora(pacoteEnquadrado);
}
