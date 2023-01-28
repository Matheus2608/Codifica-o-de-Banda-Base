#include "CamadaFisica.hpp"

void AplicacaoTransmissora() {
    string mensagem;
    cout << "Digite uma mensagem: ";
    cin >> mensagem;

    // Chama a proxima camada
    CamadaDeAplicacaoTransmissora(mensagem);
}

void CamadaDeAplicacaoTransmissora(string mensagem) {
    // Converte a mensagem para binario
    string mensagemBinario = "";
    for (char& letra : mensagem) {
        mensagemBinario += bitset<8>(letra).to_string();
    }
    // Converte string binario para trem de bits
    vi quadro(mensagemBinario.length());

    for (int i = 0; i < (int) mensagemBinario.length(); i++) {
        quadro[i] = mensagemBinario[i] - 48;
    }

    // Chama a proxima camada
    CamadaFisicaTransmissora(quadro);
}

vi inicializadorDeClock(int tamanhoClock) {
    vi clock;

    // Prrenchendo o clock com sequencias de "01"
    for (int i = 0; i < tamanhoClock; i++) {
        if (i % 2 == 0)
            clock.pb(0);
        else
            clock.pb(1);
    }

    return clock;

}

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

void AplicacaoReceptora(string mensagem) {
    cout << "A mensagem recebida foi: " << mensagem << endl;
}

void CamadaDeAplicacaoReceptora(vi quadro) {
    string mensagem = "";

    for (int i = 0; i < quadro.size(); i += 8) {
        bitset<8> byte;
        for (int j = 0; j < 8; j++) {
            byte[7-j]  = quadro[i+j];
        }

        char letra = char(byte.to_ulong());
        mensagem += letra;
    }

    AplicacaoReceptora(mensagem);
}

vi CamadaFisicaReceptoraCodificacaoBinaria(vi quadro){
    return quadro;
}

vi CamadaFisicaReceptoraCodificacaoManchester(vi quadro) {
    int tamanhoClock = quadro.size();
    vi clock = inicializadorDeClock(tamanhoClock);
    vi mensagemDecodada(tamanhoClock/2);

    for (int i = 0; i < tamanhoClock; i++) {
        mensagemDecodada[i/2] ^= mensagemDecodada[i] ^ clock[i];
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
    int tipoDeCodificacao = 1;
    vi fluxoBrutoDeBits;

    switch (tipoDeCodificacao) {
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

    CamadaDeAplicacaoReceptora(fluxoBrutoDeBits);
}

/* Este metodo simula a transmissao da informacao no meio de comunicacao,
* passando de um pontoA ( transmissor ) para um ponto B ( receptor )
*/
void MeioDeComunicacao(vi fluxoBrutoDeBits) {
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
    int tipoDeCodificacao = 2;
    vi fluxoBrutoDeBits;

    switch (tipoDeCodificacao) {
        case 0:
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
            break;
        case 1:
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchester(quadro);
            break;
        case 2:
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBipolar(quadro);
            break;
        default:
            break;
    }

    // for(int bit : quadro) cout << bit << " "; cout << endl;
    // for(int bit : fluxoBrutoDeBits) cout << bit << " "; cout << endl;

    MeioDeComunicacao(fluxoBrutoDeBits);
}






