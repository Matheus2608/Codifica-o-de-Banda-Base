#include "CamadaEnlace.hpp"

bool are_vectors_equal(const std::vector<int>& v1, const std::vector<int>& v2) {
    if (v1.size() != v2.size()) {
        return false;
    }
    for (std::size_t i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }
    return true;
}

vi CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(vi quadro) {
    bool cabecalho = true;
    int i = 0, tamanhoCargaUtil;
    vi resultadoDesenquadramento;

    while(i < quadro.size()){
        if(cabecalho){
            // cout << "estou no if" << endl;
            // cout << "i = " << i << endl;

            bitset<8> bitsetCabecalho;
            for(int j = i; j < i + 8; j++){
                bitsetCabecalho[7-(j%8)] = quadro[j];
                //cout << " bitsetCabecalho[" << 7-(j%8) << "] = " << bitsetCabecalho[7-j] << endl;
            }

            tamanhoCargaUtil = (int) (bitsetCabecalho.to_ullong() - 1);
            cabecalho = false;
            // cout << "tamanhoCargaUtil = " << tamanhoCargaUtil << endl;
            i += 8;
        }

        else{
            // cout << "estou no else" << endl;
            // cout << "i = " << i << endl;

            for(int k = i; k < i + (8 * tamanhoCargaUtil); k++){
                resultadoDesenquadramento.pb(quadro[k]);
            }

            i += (8 * tamanhoCargaUtil);
            cabecalho = true;
        }
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

vi CamadaEnlaceDadosReceptoraControleDeErroBitParidadePar(vi quadro) {
    // Armazena o bit de paridade recebido
    int bitParidadePar = quadro.back();
    quadro.pop_back();

    // Conta a quantidade de bits 1 no quadro
    int contador1 = count(quadro.begin(), quadro.end(), 1);

    // Compara o valor recebido com o valor calculado
    vi quadroOriginal;
    int erro = 0;
    if (contador1 % 2 == bitParidadePar) {
        quadroOriginal = quadro;
        cout << "Nenhum erro detectado" << endl;
    } else {
        erro = 1;
        cout << "Erro detectado" << endl;
    }
    return quadroOriginal;
}

vi CamadaEnlaceDadosReceptoraControleDeErroCRC(vi quadro) {
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
    vi quadroOriginal;
    int erro = 0;
    if (contador1 == 0) {
        quadroOriginal = quadro;
        for (int i = 0; i < polinomioGerador.size() - 1; i++){
            quadroOriginal.pop_back();
        }
        cout << "Nenhum erro detectado" << endl;
    } else {
        erro = 1;
        cout << "Erro detectado" << endl;
    }
    return quadroOriginal;
}

vi CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming(vi quadro){
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
    vi quadroOriginal;
    if (erro == 0){
        // Localizando a posição dos bits de redundância
        // Inserindo o valor do quadro nos outros bits
        j = 0;
        for(int i = 1; i <= tamanhoDoQuadro; i++){
            if( i == pow( 2, j )){
                j++;
            }
            else{
                quadroOriginal.pb(quadro[i]);
            }
        }
        cout << "Nenhum erro detectado" << endl;
    }

    return quadroOriginal;
}

void CamadaEnlaceDadosReceptoraControleDeErro(vi quadro) {
    vi quadroDecodificado;
    switch(TIPO_DE_VERIFICACAO_DE_ERROS) {
        case 0:
            quadroDecodificado = CamadaEnlaceDadosReceptoraControleDeErroBitParidadePar(quadro);
            break;
        case 1:
            quadroDecodificado = CamadaEnlaceDadosReceptoraControleDeErroCRC(quadro);
            break;
        case 2:
            quadroDecodificado = CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming(quadro);
            break;
    }
}
