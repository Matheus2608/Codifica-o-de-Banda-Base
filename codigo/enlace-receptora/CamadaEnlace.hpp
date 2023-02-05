#ifndef SIMULADORCAMADAENLACE_CAMADAENLACE_HPP
#define SIMULADORCAMADAENLACE_CAMADAENLACE_HPP
#include "../base-template.hpp"

vi CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(vi quadro);
vi CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(vi);
void CamadaEnlaceDadosReceptoraControleDeErro(vi quadro);
void CamadaEnlaceDadosReceptoraControleDeErroBitParidadePar(vi quadro);
void CamadaEnlaceDadosReceptoraControleDeErroCRC(vi quadro);
void CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming(vi quadro);
#endif //SIMULADORCAMADAENLACE_CAMADAENLACE_HPP
