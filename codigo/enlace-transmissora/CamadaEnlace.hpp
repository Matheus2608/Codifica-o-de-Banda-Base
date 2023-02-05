#ifndef SIMULADORCAMADAENLACE_CAMADAENLACE_HPP
#define SIMULADORCAMADAENLACE_CAMADAENLACE_HPP
#include "../base-template.hpp"
#include "../constantes.cpp"

bool are_vectors_equal(const std::vector<int>&, const std::vector<int>& );
void CamadaEnlaceDadosTransmissora(vi);
vi CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(vi);
vi CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(vi);
vi CamadaEnlaceDadosTransmissoraControleDeErro(vi);
vi CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(vi);
vi CamadaEnlaceDadosTransmissoraControleDeErroCRC(vi);
vi CamadaEnlaceDadosTransmissoraControleDeErroCodigoDeHamming(vi);

#endif //SIMULADORCAMADAENLACE_CAMADAENLACE_HPP
