#include "aplicacao-transmissora/Aplicacao.hpp"
#include "constantes.cpp"

int main() {
    if (TIPO_DE_CODIFICACAO != 0 && TIPO_DE_CODIFICACAO != 1 && TIPO_DE_CODIFICACAO != 2) {
        cout << "Tipo de codificação inválida" << endl;
        return 1;
    }
    if (TIPO_DE_ENQUADRAMENTO != 0 && TIPO_DE_ENQUADRAMENTO != 1) {
        cout << "Tipo de enquadramento inválido" << endl;
        return 1;
    }
    if (QTD_MAX_BYTES_QUADRO < 2 and QTD_MAX_BYTES_QUADRO > 255) {
        cout << "Quantidade máxima de bytes por quadro inválida" << endl;
        return 1;
    }

    AplicacaoTransmissora();
}
