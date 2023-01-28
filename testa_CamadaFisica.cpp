#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "CamadaFisica.hpp"

vi TestCamadaDeAplicacaoTransmissora(string mensagem) {
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

    return quadro;
}




TEST_CASE( "Teste 1" ) {
    string input = "hello world";
    string expected_output = "0110100001100101011011000110110001101111001000000101011101101111011100100110110001100100";

    vi quadro = TestCamadaDeAplicacaoTransmissora(input);

    string result = "";
    for (int i = 0; i < quadro.size(); i++) {
        result += to_string(quadro[i]);
    }

    REQUIRE(result == expected_output);
}
