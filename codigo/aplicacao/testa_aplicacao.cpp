#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../base_template.cpp"
#include "../catch.hpp"

string transformVecInString(vi vec){

    string result = "";
    for (int i = 0; i < vec.size(); i++) {
        result += to_string(vec[i]);
    }

    return result;
}

// É a mesma função, porém ela esta retornando a string
// Fiz isso para poder testá-la, a outra retornava void
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

// É a mesma função, porém ela esta retornando a string
// Fiz isso para poder testá-la, a outra retornava void
string TestCamadaDeAplicacaoReceptora(vi quadro) {

    string mensagem = "";

    for (int i = 0; i < quadro.size(); i += 8) {
        bitset<8> byte;
        for (int j = 0; j < 8; j++) {
            byte[7-j]  = quadro[i+j];
        }

        char letra = char(byte.to_ulong());
        mensagem += letra;
    }

    return mensagem;
}



TEST_CASE( "Converte mensagem para binario" ) {
    string input = "hello world", expected_output = "0110100001100101011011000110110001101111001000000111011101101111011100100110110001100100";
    REQUIRE(TestCamadaDeAplicacaoTransmissora(input) == expected_output);

    input = "abc", expected_output = "011000010110001001100011";
    REQUIRE(TestCamadaDeAplicacaoTransmissora(input) == expected_output);

}

TEST_CASE( "Converte binario para string" ) {
    vi input{0,1,1,0,1,0,0,0,0,1,1,0,0,1,0,1,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,1,1,0,0,1,0,0,0,0,0,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,1,0,1,1,1,0,0,1,0,0,1,1,0,1,1,0,0,0,1,1,0,0,1,0,0};
    string expected_output = "hello world";
    REQUIRE(TestCamadaDeAplicacaoReceptora(input) == expected_output);

    vi input2{0,1,1,0,0,0,0,1,0,1,1,0,0,0,1,0,0,1,1,0,0,0,1,1};
    expected_output = "abc";
    REQUIRE(TestCamadaDeAplicacaoReceptora(input2) == expected_output);
}
