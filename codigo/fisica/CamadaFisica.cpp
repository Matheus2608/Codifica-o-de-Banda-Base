#include "CamadaFisica.hpp"
#include "../enlace-receptora/CamadaEnlace.hpp"
#include "../constantes.cpp"


vi CamadaFisicaReceptoraCodificacaoBinaria(vi quadro){
    return quadro;
}

vi CamadaFisicaReceptoraCodificacaoManchester(vi quadro) {
    int tamanhoQuadroOriginal = quadro.size() / 2;
    vi clock = inicializadorDeClock(tamanhoQuadroOriginal);
    vi mensagemDecodada(tamanhoQuadroOriginal);

    for (int i = 0; i < tamanhoQuadroOriginal; i++) {
        mensagemDecodada[i] = quadro[i*2] ^ clock[i*2];
    }

    return mensagemDecodada;
}

vi CamadaFisicaReceptoraCodificacaoBipolar(vi quadro) {
    int voltagem = 1;

    for(int& bit : quadro) {
        if(bit == voltagem or bit == -1 * voltagem) bit = voltagem;
    }

    return quadro;
}

void CamadaFisicaReceptora(vi quadro) {

    cout << "decodificando..." << endl;
    vi fluxoBrutoDeBits;

    switch (TIPO_DE_CODIFICACAO) {
        case 0:
            fluxoBrutoDeBits = CamadaFisicaReceptoraCodificacaoBinaria(quadro);
            break;
        case 1:
            fluxoBrutoDeBits = CamadaFisicaReceptoraCodificacaoManchester(quadro);
            break;
        case 2:
            fluxoBrutoDeBits = CamadaFisicaReceptoraCodificacaoBipolar(quadro);
            break;
        default:
            break;
    }

    cout << "trem de bits decodificado:" << endl;
    for(int bit : fluxoBrutoDeBits) cout << bit << " "; cout << endl;

    CamadaEnlaceDadosReceptoraControleDeErro(fluxoBrutoDeBits);
}

// ---------------------------------------------------------- ATENCAO --------------------------------------------------------------------------------------
// Funções transmissoras

vi CamadaFisicaTransmissoraCodificacaoBinaria(vi quadro) {
    return quadro;
}

vi CamadaFisicaTransmissoraCodificacaoManchester(vi quadro) {
    int tamanhoClock = quadro.size() * 2;

    vi clock = inicializadorDeClock(tamanhoClock);
    vi mensagemEncondada(tamanhoClock);

    for (int i = 0; i < tamanhoClock; i++) {
        mensagemEncondada[i] = quadro[i/2] ^ clock[i];
    }

    return mensagemEncondada;
}

vi CamadaFisicaTransmissoraCodificacaoBipolar(vi quadro) {
    int voltagem = 1;
    bool positiva = true;

    for (int& bit : quadro) {
        if(bit){
            if(positiva){
                bit = voltagem;
                positiva = false;
            }

            else {
                bit = voltagem * -1;
                positiva = true;
            }
        }
    }

    return quadro;
}



/* Este metodo simula a transmissao da informacao no meio de comunicacao,
* passando de um pontoA ( transmissor ) para um ponto B ( receptor )
*/
void MeioDeComunicacao(vi fluxoBrutoDeBits) {

    cout << "transmitindo no meio de comunicação" << endl;

    vi fluxoBrutoDeBitsPontoA, fluxoBrutoDeBitsPontoB;

    fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;
    int i = 0;
    while(fluxoBrutoDeBitsPontoB.size() != fluxoBrutoDeBitsPontoA.size()) {
        fluxoBrutoDeBitsPontoB.pb(fluxoBrutoDeBitsPontoA[i]);
        i++;
    }

    // for(int bit : fluxoBrutoDeBitsPontoB) cout << bit << " "; cout << endl;
    CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB);

}

void CamadaFisicaTransmissora (vi quadro) {
    vi fluxoBrutoDeBits;

    cout << "Resultado da codificação ";
    switch (TIPO_DE_CODIFICACAO) {
        case 0:
            cout << "binária" << endl;
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
            break;
        case 1:
            cout << "manchester" << endl;
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchester(quadro);
            break;
        case 2:
            cout << "bipolar" << endl;
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBipolar(quadro);
            break;
        default:
            break;
    }


    for(int bit : fluxoBrutoDeBits) cout << bit << " "; cout << endl;

    MeioDeComunicacao(fluxoBrutoDeBits);
}
