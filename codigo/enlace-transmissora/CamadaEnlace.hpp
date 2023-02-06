#ifndef SIMULADORCAMADAENLACE_CAMADAENLACE_HPP
#define SIMULADORCAMADAENLACE_CAMADAENLACE_HPP
#include "../base-template.hpp"
#include "../utils/utils.hpp"

void CamadaEnlaceDadosTransmissoraEnquadramento(vi);
vi CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(vi);
vi CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(vi);
vi CamadaEnlaceDadosTransmissoraControleDeErro(vi);
vi CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(vi);
vi CamadaEnlaceDadosTransmissoraControleDeErroCRC(vi);
vi CamadaEnlaceDadosTransmissoraControleDeErroCodigoDeHamming(vi);

#endif //SIMULADORCAMADAENLACE_CAMADAENLACE_HPP
