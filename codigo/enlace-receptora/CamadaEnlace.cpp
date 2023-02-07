#include "CamadaEnlace.hpp"
#include "../aplicacao-receptora/Aplicacao.hpp"
#include "../constantes.cpp"

vi CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(vi quadro) {
    bitset<8> bitsetCabecalho;
    vi resultadoDesenquadramento;

    for(int i = 0; i < 8; i++){
        bitsetCabecalho[7 - i] = quadro[i];
    }

    int numBits = (int) (bitsetCabecalho.to_ullong());

    for(int j = 8; j < 8 + numBits; j++){
        resultadoDesenquadramento.pb(quadro[j]);
    }

    return resultadoDesenquadramento;

}

vi CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(vi quadro) {
    vi ByteDeFlag{0,0,0,0,1,1,1,1}, ByteEsc{1,1,1,1,0,0,0,0}, resultadoDesenquadramento;

    int i = 0;
    while(i < quadro.size()) {
        vi temp;
        for(int j = i; j < i + 8; j++) {
            temp.pb(quadro[j]);
        }

        if(are_vectors_equal(temp, ByteEsc)){
            i += 8;
            for(int j = i; j < i + 8; j++) {
                resultadoDesenquadramento.pb(quadro[j]);
            }
        }

        else if(!are_vectors_equal(temp, ByteDeFlag)) {
            for(int j = i; j < i + 8; j++) {
                resultadoDesenquadramento.pb(quadro[j]);
            }
        }

        i += 8;
    }

    return resultadoDesenquadramento;
}

bool CamadaEnlaceDadosReceptoraControleDeErroBitParidadePar(vi quadro) {
    // Armazena o bit de paridade recebido
    int bitParidadePar = quadro.back();
    quadro.pop_back();

    // Conta a quantidade de bits 1 no quadro
    int contador1 = count(quadro.begin(), quadro.end(), 1);

    // Compara o valor recebido com o valor calculado
    bool erro = false;
    if (contador1 % 2 == bitParidadePar) {
        cout << "Nenhum erro detectado" << endl;
    } else {
        erro = true;
        cout << "Erro detectado" << endl;
    }
    return erro;
}

int CamadaEnlaceDadosReceptoraControleDeErroCRC(vi quadro) {
    vi polinomioGerador{1,1,0,1};
    vi resto = quadro;
    vi resultado;

    // Adiciona zeros no quadro (Quantidade de bits CRC)
    for (int i = 0; i < polinomioGerador.size() - 1; i++){
        resto.pb(0);
    }

    // Loop da divisão até o resto ser menor que o polinomio gerador
    while (polinomioGerador.size() <= resto.size() and resto.size() > 0){
        // Se o primeiro bit for 1, faz XOR com o polinomio gerador
        if (resto[0] == 1){
            resto.erase(resto.begin());
            for (int i = 0; i < polinomioGerador.size(); i++){
                resto[i] = resto[i] ^ polinomioGerador[i+1];
            }
            resultado.pb(1);
        } else {
            resto.erase(resto.begin());
            resultado.pb(0);
        }
    }
    // Conta a quantidade de bits 1 dos bits CRC
    int contador1 = count(resto.begin(), resto.end(), 1);

    // Verifica a quantidade de bits 1
    int erro = 0;
    if (contador1 == 0) {
        cout << "Nenhum erro detectado" << endl;
    } else {
        erro = 1;
        cout << "Erro detectado" << endl;
    }
    return erro;
}

int CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming(vi quadro){
    int tamanhoDoQuadro = quadro.size();

    // Inserindo um bit 0 no começo, pois a primeira posição do bit de redundância é 1 (2^0)
    quadro.insert(quadro.begin(), 0);

    int k = 0;
    int erro = 0;
    int paridade,x,j, min, max = 0;
    int localizarErro = 0;
    // Calculando os bits de redundância
    for (int i = 1; i <= tamanhoDoQuadro; i = pow(2, k)) {
        k++;
        paridade = 0;
        j = i;
        min = 1;
        max = i;
        while (j <= tamanhoDoQuadro) {
            for (j = j; max >= min && j <= tamanhoDoQuadro; min++, j++) {
                if (quadro[j] == 1)
                    paridade = paridade + 1;;
            }
            j = j + i;
            min = 1;
        }

        // Verificando erro
        if (paridade % 2 != 0){
            erro = 1;
            localizarErro += i;
            cout << "Erro detectado" << endl;
        }
    }
    if (erro == 0){
        cout << "Nenhum erro detectado" << endl;
    }

    // Removendo o bit 0 do começo
    quadro.erase(quadro.begin());
    return erro;
}

void CamadaEnlaceDadosReceptoraControleDeErro(vi quadro) {
    
    switch(TIPO_DE_VERIFICACAO_DE_ERROS) {
        case 0:
            CamadaEnlaceDadosReceptoraControleDeErroBitParidadePar(quadro);
            quadro.pop_back();
            break;
        case 1:
            CamadaEnlaceDadosReceptoraControleDeErroCRC(quadro);
            break;
        case 2:
            CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming(quadro);
            break;
    }

    cout << "Resultado do Controle de Erro:" << endl;
    for(int bit : quadro) cout << bit << " "; cout << endl;

    CamadaDeAplicacaoReceptora(quadro);
}

void CamadaEnlaceDadosReceptoraEnquadramento(vi quadro) {
    cout << "Desenquadrando pacote ..." << endl;
    vi pacoteDesenquadrado;

    switch (TIPO_DE_ENQUADRAMENTO) {
    case 0:
        pacoteDesenquadrado = CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(quadro);
        break;

    case 1:
        pacoteDesenquadrado = CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(quadro);
        break;
    }

    cout << "Resultado do desenquadramento:" << endl;
    for(int bit : pacoteDesenquadrado) cout << bit << " "; cout << endl;

    CamadaEnlaceDadosReceptoraControleDeErro(pacoteDesenquadrado);
}
