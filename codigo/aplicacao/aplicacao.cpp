#include "aplicacao.hpp"

// Funcões Receptoras
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

void AplicacaoReceptora(string mensagem) {
    cout << "A mensagem recebida foi: " << mensagem << endl;
}


void AplicacaoTransmissora() {
    string mensagem;
    cout << "Digite uma mensagem: ";
    getline(cin, mensagem);

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

    cout << "Convertendo mensagem para trem de bits..." << endl;
    for(int bit : quadro) cout << bit << " "; cout << endl;

    // Chama a proxima camada
    CamadaFisicaTransmissora(quadro);
}
