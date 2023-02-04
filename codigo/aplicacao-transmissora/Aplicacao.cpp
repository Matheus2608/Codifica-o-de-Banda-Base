#include "Aplicacao.hpp"
#include "../fisica/CamadaFisica.hpp"

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