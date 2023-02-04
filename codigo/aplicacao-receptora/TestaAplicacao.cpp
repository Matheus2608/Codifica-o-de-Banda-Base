#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../base-template.hpp"
#include "../catch.hpp"

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

TEST_CASE( "Converte binario para string" ) {
    vi input{0,1,1,0,1,0,0,0,0,1,1,0,0,1,0,1,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,1,1,0,0,1,0,0,0,0,0,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,1,0,1,1,1,0,0,1,0,0,1,1,0,1,1,0,0,0,1,1,0,0,1,0,0};
    string expected_output = "hello world";
    REQUIRE(TestCamadaDeAplicacaoReceptora(input) == expected_output);

    vi input2{0,1,1,0,0,0,0,1,0,1,1,0,0,0,1,0,0,1,1,0,0,0,1,1};
    expected_output = "abc";
    REQUIRE(TestCamadaDeAplicacaoReceptora(input2) == expected_output);
}