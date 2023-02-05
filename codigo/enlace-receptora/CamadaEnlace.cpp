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
