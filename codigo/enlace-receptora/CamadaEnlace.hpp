#ifndef SIMULADORCAMADAENLACE_CAMADAENLACE_HPP
#define SIMULADORCAMADAENLACE_CAMADAENLACE_HPP
#include "../base-template.hpp"
#include "../constantes.cpp"

vi CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(vi quadro);
vi CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(vi);
void CamadaEnlaceDadosReceptoraControleDeErro(vi quadro);
int CamadaEnlaceDadosReceptoraControleDeErroBitParidadePar(vi quadro);
int CamadaEnlaceDadosReceptoraControleDeErroCRC(vi quadro);
int CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming(vi quadro);
#endif //SIMULADORCAMADAENLACE_CAMADAENLACE_HPP
