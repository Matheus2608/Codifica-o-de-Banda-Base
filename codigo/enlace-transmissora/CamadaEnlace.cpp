#include "../base-template.hpp"

int tamMaxQuadro;

vi CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(vi quadro) {
    cout << "Escreva o tamanho máximo de um quadro: (2-255)" << endl;
    cin >> tamMaxQuadro;

    while (tamMaxQuadro < 2 or tamMaxQuadro > 255)
    {
        cout << "Número invalido! Digite novamente:" << endl;
        cin >> tamMaxQuadro;
    }
    
    bitset<8> tamMaxEmByte(tamMaxQuadro);
    int tamCargaUtil = tamMaxQuadro - 1;

    int numBytes = quadro.size() / 8;
    int numQuadrosPerfeitos = numBytes / tamCargaUtil;

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