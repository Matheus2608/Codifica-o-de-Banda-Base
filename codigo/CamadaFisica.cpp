#include "headers/CamadaFisica.hpp"

vi inicializadorDeClock(int tamanhoQuadro) {
    vi clock;
    if(!tamanhoQuadro) return clock;

    // Prrenchendo o clock com sequencias de "01"
    for (int i = 0; i < tamanhoQuadro * 2; i++) {
        if (i % 2 == 0)
            clock.pb(0);
        else
            clock.pb(1);
    }

    return clock;
}

// Funcões Receptoras
string AplicacaoReceptora(string mensagem) {
    cout << "A mensagem recebida foi: " << mensagem << endl;
    return mensagem;
}

string CamadaDeAplicacaoReceptora(vi quadro, int tipoDeCodificacao) {

    string mensagem = "";

    for (int i = 0; i < quadro.size(); i += 8) {
        bitset<8> byte;
        for (int j = 0; j < 8; j++) {
            byte[7-j]  = quadro[i+j];
        }

        char letra = char(byte.to_ulong());
        mensagem += letra;
    }

    return AplicacaoReceptora(mensagem);
}

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

string CamadaFisicaReceptora(vi quadro, int tipoDeCodificacao) {
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
    // cout << "bits antes de serem encodados" << endl;
    // for(int bit : quadro) cout << bit << " "; cout << endl;
    // cout << "bits foram desencodados" << endl;
    // for(int bit : fluxoBrutoDeBits) cout << bit << " "; cout << endl;
    return CamadaDeAplicacaoReceptora(fluxoBrutoDeBits, tipoDeCodificacao);
}

// ---------------------------------------------------------- ATENCAO --------------------------------------------------------------------------------------
// Funções transmissoras

string AplicacaoTransmissora(string mensagem, int tipoDeCodificacao) {
    // Chama a proxima camada
    return CamadaDeAplicacaoTransmissora(mensagem, tipoDeCodificacao);
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



/* Este metodo simula a transmissao da informacao no meio de comunicacao,
* passando de um pontoA ( transmissor ) para um ponto B ( receptor )
*/
string MeioDeComunicacao(vi fluxoBrutoDeBits, int tipoDeCodificacao) {
    vi fluxoBrutoDeBitsPontoA, fluxoBrutoDeBitsPontoB;

    fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;
    int i = 0;
    while(fluxoBrutoDeBitsPontoB.size() != fluxoBrutoDeBitsPontoA.size()) {
        fluxoBrutoDeBitsPontoB.pb(fluxoBrutoDeBitsPontoA[i]);
        i++;
    }

    // for(int bit : fluxoBrutoDeBitsPontoB) cout << bit << " "; cout << endl;
    return CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB, tipoDeCodificacao);

}

string CamadaFisicaTransmissora (vi quadro, int tipoDeCodificacao) {
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
            return "error";
            break;
    }

    //for(int bit : quadro) cout << bit << " "; cout << endl;
    //cout << "bits foram encodados" << endl;
    //for(int bit : fluxoBrutoDeBits) cout << bit << " "; cout << endl;

    return MeioDeComunicacao(fluxoBrutoDeBits, tipoDeCodificacao);
}

string CamadaDeAplicacaoTransmissora(string mensagem, int tipoDeCodificacao) {
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

    // for(int bit : quadro) cout << bit << " "; cout << endl;


    // Chama a proxima camada
    return CamadaFisicaTransmissora(quadro, tipoDeCodificacao);
}
