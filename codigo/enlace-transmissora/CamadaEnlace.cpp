#include "../base-template.hpp"
#include "../constantes.cpp"
#include "../fisica/CamadaFisica.hpp"


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

vi CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(vi quadro) {
    bitset<8> tamMaxEmByte(QTD_MAX_BYTES_QUADRO);
    int tamCargaUtil = QTD_MAX_BYTES_QUADRO - 1;


    int numBytes = quadro.size() / 8;
    int numQuadrosPerfeitos = numBytes / tamCargaUtil;

    vi resultadoEnquadramento;

    for(int i = 0; i < numQuadrosPerfeitos; i++) {
        for(int j = 7; j >= 0; j--){
            resultadoEnquadramento.pb(tamMaxEmByte[j]);
        }

        for(int k = 0; k < tamCargaUtil * 8; k++) {
            resultadoEnquadramento.pb(quadro[i*8+k]);
        }
    }

    int numBytesFaltantes = numBytes % tamCargaUtil;
    if(numBytesFaltantes) {

        bitset<8> numBytesFaltantesEmByte(numBytesFaltantes+1);

        for(int i = 7; i >= 0; i--){
            resultadoEnquadramento.pb(numBytesFaltantesEmByte[i]);
        }

        for(int j = numQuadrosPerfeitos * tamCargaUtil * 8; j < quadro.size(); j++){
            resultadoEnquadramento.pb(quadro[j]);
        }
    }

    return resultadoEnquadramento;
}

vi CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(vi quadro) {
    vi ByteDeFlag{0,0,0,0,1,1,1,1}, ByteEsc{1,1,1,1,0,0,0,0}, resultadoEnquadramento;

    int tamCargaUtil = QTD_MAX_BYTES_QUADRO - 1;
    int numBytes = quadro.size() / 8;
    int numQuadrosPerfeitos = numBytes / tamCargaUtil;

    for(int i = 0; i < numQuadrosPerfeitos; i++) {
        for(int j = 0; j < 8; j++){
            resultadoEnquadramento.pb(ByteDeFlag[j]);
        }

        for(int k = 0; k < tamCargaUtil * 8; k++) {
            resultadoEnquadramento.pb(quadro[i*8+k]);
        }

        for(int j = 0; j < 8; j++){
            resultadoEnquadramento.pb(ByteDeFlag[j]);
        }
    }

    return resultadoEnquadramento;
}

void CamadaEnlaceDadosTransmissora(vi quadro) {
    cout << "Enquadrado pacote ..." << endl;
    vi pacoteEnquadrado;

    switch (TIPO_DE_ENQUADRAMENTO) {
    case 0:
        pacoteEnquadrado = CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(quadro);
        break;
    
    case 1:
        pacoteEnquadrado = CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(quadro);
        break;
    }

    cout << "Resultado do enquadramento:" << endl;
    for(int bit : pacoteEnquadrado) cout << bit << " "; cout << endl;

    CamadaFisicaTransmissora(pacoteEnquadrado);
}

vi CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(vi quadro){
    // Conta a quantidade de bits 1 no quadro
    int contador1 = count(quadro.begin(), quadro.end(), 1);

    //Adiciona o bit de paridade no final do quadro
    if (contador1 % 2 == 0) {
        quadro.push_back(0);
    } else {
        quadro.push_back(1);
    }
    return quadro;
}

vi CamadaEnlaceDadosTransmissoraControleDeErroCRC(vi quadro){
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
    // Adiciona os bits CRC no final do quadro
    for (int i = 0; i < resto.size(); i++){
        quadro.pb(resto[i]);
    }
    return quadro;
}

vi CamadaEnlaceDadosTransmissoraControleDeErroCodigoDeHamming (vi quadro) {
    int tamanhoDoQuadro = quadro.size();
    int quantidadeDeBitsDeRedundancia = 0;

    // Inserindo um bit 0 no começo, pois a primeira posição do bit de redundância é 1 (2^0)
    quadro.insert(quadro.begin(), 0);

    // Caculando a quantidade de bits de redundânciaa
    while(pow (2,quantidadeDeBitsDeRedundancia) < tamanhoDoQuadro + quantidadeDeBitsDeRedundancia + 1){
        quantidadeDeBitsDeRedundancia++;
    }

    // Criando o vetor do código de Hamming
    vi codigoDeHamming(tamanhoDoQuadro + quantidadeDeBitsDeRedundancia + 1);
    int j = 0,k = 1;

    // Localizando a posição dos bits de redundância (Inserindo o valor de -1)
    // Inserindo o valor do quadro nos outros bits
    for(int i = 1; i <= tamanhoDoQuadro + quantidadeDeBitsDeRedundancia; i++){
        if( i == pow( 2, j )){
            codigoDeHamming[i] = -1;
            j++;
        }
        else{
            codigoDeHamming[i] = quadro[k];
            k++;
        }
    }

    k = 0;
    int paridade,x, min, max = 0;
    // Calculando os bits de redundância
    for (int i = 1; i <= tamanhoDoQuadro + quantidadeDeBitsDeRedundancia; i = pow (2, k)){
        k++;
        paridade = 0;
        j = i;
        min = 1;
        max = i;
        while ( j <= tamanhoDoQuadro + quantidadeDeBitsDeRedundancia){
            for (j = j; max >= min && j <= tamanhoDoQuadro + quantidadeDeBitsDeRedundancia; min++, j++){
                if (codigoDeHamming[j] == 1)
                    paridade = paridade + 1;;
            }
            j = j + i;
            min = 1;
        }

        // Inserindo o valor do bit de redundância
        if (paridade % 2 == 0){
            codigoDeHamming[i] = 0;
        }
        else{
            codigoDeHamming[i] = 1;
        }
    }
    // Removendo o bit 0 do começo
    codigoDeHamming.erase(codigoDeHamming.begin());
    return codigoDeHamming;
}

vi CamadaEnlaceDadosTransmissoraControleDeErro(vi quadro){
    vi quadroControleErro;
    switch (TIPO_DE_VERIFICACAO_DE_ERROS) {
    case 0:
        quadroControleErro = CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(quadro);
        break;

    case 1:
        quadroControleErro = CamadaEnlaceDadosTransmissoraControleDeErroCRC(quadro);
        break;

    case 2:
        quadroControleErro = CamadaEnlaceDadosTransmissoraControleDeErroCodigoDeHamming(quadro);
        break;
    }
    return quadroControleErro;
}