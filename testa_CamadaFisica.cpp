#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "CamadaFisica.hpp"

string transformVecInString(vi vec){

    string result = "";
    for (int i = 0; i < vec.size(); i++) {
        result += to_string(vec[i]);
    }

    return result;
}

string TestCamadaDeAplicacaoTransmissora(string mensagem) {
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

    return transformVecInString(quadro);
}


TEST_CASE( "Converte mensagem para binario" ) {
    string result, input = "hello world", expected_output = "0110100001100101011011000110110001101111001000000111011101101111011100100110110001100100";;
    result = TestCamadaDeAplicacaoTransmissora(input);
    REQUIRE(result == expected_output);

    input = "abc", expected_output = "011000010110001001100011";
    result = TestCamadaDeAplicacaoTransmissora(input);
    REQUIRE(result == expected_output);

}

TEST_CASE( "Converte mensagem com unicodes para binario" ) {

    string input = "٩(-̮̮̃-̃)۶ ٩(●̮̮̃•̃)۶ ٩(͡๏̯͡๏)۶ ٩(-̮̮̃•̃)";
    string expected_output = "110011010010010100000101101110010111011001011101100000011001011011100000011001010011101111011000100000110011010010010100010010111001111110010111011001011101100000011100000001000101100000011001010011101111011000100000110011010010010100011011000011110010011111100101111110110000111100100111100101001110111101100010000011001101001001010000010110111001011101100101110110000001110000000100010110000001100101001";
    string result = TestCamadaDeAplicacaoTransmissora(input);
    REQUIRE(result == expected_output);
}

TEST_CASE( "Funcionamento das funcoes de codificacao" ) {
    vi expected_bin_output = {0,1,1,0,0,0,0,1};
    vi expected_bipolar_output = {0,1,-1,0,0,0,0,1};
    vi expected_manchester_output = {0,1,0,1,1,0,0,0,1,1,0,0,0,1};

    vi input{0,1,1,0,0,0,0,1};

    vi bin_output = CamadaFisicaTransmissoraCodificacaoBinaria(input);
    vi manchester_output = CamadaFisicaTransmissoraCodificacaoManchester(input);
    vi bipolar_output = CamadaFisicaTransmissoraCodificacaoBipolar(input);

    REQUIRE(expected_bin_output == bin_output);
    REQUIRE(expected_bipolar_output == bipolar_output);
    REQUIRE(expected_manchester_output == manchester_output);

}
