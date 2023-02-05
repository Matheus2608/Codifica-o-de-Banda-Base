#include "CamadaEnlace.hpp"

vi CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(vi quadro) {
    bool cabecalho = true;
    int i = 0, tamanhoCargaUtil;
    vi output;

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
                output.pb(quadro[k]);
            }

            i += (8 * tamanhoCargaUtil);
            cabecalho = true;
        }
    }

    return output;
}
