#ifndef SIMULADORCAMADAENLACE_CAMADAENLACE_HPP
#define SIMULADORCAMADAENLACE_CAMADAENLACE_HPP
#include "../base-template.hpp"
#include "../constantes.cpp"

vi CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(vi quadro);
vi CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(vi);
void CamadaEnlaceDadosReceptoraControleDeErro(vi quadro);
vi CamadaEnlaceDadosReceptoraControleDeErroBitParidadePar(vi quadro);
vi CamadaEnlaceDadosReceptoraControleDeErroCRC(vi quadro);
vi CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming(vi quadro);
#endif //SIMULADORCAMADAENLACE_CAMADAENLACE_HPP
