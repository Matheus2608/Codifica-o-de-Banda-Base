#include "CamadaEnlace.hpp"
#include "../aplicacao-receptora/Aplicacao.hpp"
#include "../constantes.cpp"



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

    CamadaDeAplicacaoReceptora(pacoteDesenquadrado);
}
