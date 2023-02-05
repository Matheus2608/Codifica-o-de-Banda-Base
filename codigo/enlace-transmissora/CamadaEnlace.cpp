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
    int contador1 = count(quadro.begin(), quadro.end(), 1);]
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

    for (int i = 0; i < polinomioGerador.size() - 1; i++){
        resto.pb(0);
    }
    while (polinomioGerador.size() <= resto.size() and resto.size() > 0){
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
    for (int i = 0; i < resto.size(); i++){
        quadro.pb(resto[i]);
    }
    return quadro;
}

vi CamadaEnlaceDadosTransmissoraControleDeErro(vi quadro){
    switch (TIPO_DE_CONTROLE_DE_ERRO) {
    case 0:
        vi quadroControleErro = CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(quadro);
        break;

    case 1:
        vi quadroControleErro = CamadaEnlaceDadosTransmissoraControleDeErroCRC(quadro);
        break;

    case 2:
        vi quadroControleErro = CamadaEnlaceDadosTransmissoraControleDeErroCodigoDeHamming(quadro);
        break;
    }
    return quadroControleErro;
}