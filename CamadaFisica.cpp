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

    // Fill the clock array with the sequence "01"
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
    // cout << "tamanho quadro " << quadro.size() << endl;
    // cout << "tamanho clock " << tamanhoClock << endl;

    vi clock = inicializadorDeClock(tamanhoClock);
    vi output(tamanhoClock);

    for (int i = 0; i < tamanhoClock; i++) {
        output[i] = quadro[i/2] ^ clock[i];
    }

    return output;
}

vi CamadaFisicaTransmissoraCodificacaoBipolar(vi quadro) {
    return quadro;
}

void CamadaFisicaTransmissora (vi quadro) {
    int tipoDeCodificacao = 1;
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

    for(int bit : fluxoBrutoDeBits) {
        cout << bit << " ";
    }

    cout << endl;

    //MeioDeComunicacao(fluxoBrutoDeBits);
}









