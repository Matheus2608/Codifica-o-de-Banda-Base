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

void CamadaEnlaceDadosReceptoraControleDeErroBitParidadePar(vi quadro) {
    int bitParidadePar = quadro.back();
    quadro.pop_back();
    int contador1 = count(quadro.begin(), quadro.end(), 1);
    if (contador1 % 2 == bitParidadePar) {
        cout << "Nenhum erro detectado" << endl;
    } else {
        cout << "Erro detectado" << endl;
    }
}

void CamadaEnlaceDadosReceptoraControleDeErroCRC(vi quadro) {
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
    int contador1 = count(resto.begin(), resto.end(), 1);
    if (contador1 == 0) {
        cout << "Nenhum erro detectado" << endl;
    } else {
        cout << "Erro detectado" << endl;
    }
}

void CamadaEnlaceDadosReceptoraControleDeErro(vi quadro) {
    switch(TIPO_DE_VERIFICACAO_DE_ERROS) {
        case 0:
            CamadaEnlaceDadosReceptoraControleDeErroBitParidadePar(quadro);
            break;
        case 1:
            CamadaEnlaceDadosReceptoraControleDeErroCRC(quadro);
            break;
        case 2:
            CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming(quadro);
            break;
    }
}
