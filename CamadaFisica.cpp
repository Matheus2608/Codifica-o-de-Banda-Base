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
    int quadro[mensagemBinario.length()];

    for (int i = 0; i < (int) mensagemBinario.length(); i++) {
        quadro[i] = (mensagemBinario[i] - 48);
    }

    // Chama a proxima camada
    // CamadaFisicaTransmissora(quadro);
}

// void CamadaFisicaTransmissora (int quadro[]) {
//     int tipoDeCodificacao = 1;
//     int fluxoBrutoDeBits[];

//     switch (tipoDeCodificacao) {
//         case 0:
//             fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
//             break;
//         case 1:
//             fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchester(quadro);
//             break;
//         case 2:
//             fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBipolar(quadro);
//             break;
//         default:
//             break;
//     }

//     MeioDeComunicacao(fluxoBrutoDeBits);
// }






