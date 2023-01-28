#ifndef SIMULADORCAMADAFISICA_CAMADAFISICA_HPP
#define SIMULADORCAMADAFISICA_CAMADAFISICA_HPP
#include <bitset>
#include <string>
#include <iostream>
using namespace std;

void AplicacaoTransmissora();
void CamadaDeAplicacaoTransmissora (string mensagem);
void CamadaFisicaTransmissora (int quadro[]);
int CamadaFisicaTransmissoraCodificacaoBinaria (int quadro[]);
int CamadaFisicaTransmissoraCodificacaoManchester (int quadro[]);
int CamadaFisicaTransmissoraCodificacaoBipolar (int quadro[]);
void MeioDeComunicacao (int fluxoBrutoDeBits[]);
void CamadaFisicaReceptora (int quadro[]);
int CamadaFisicaReceptoraCodificacaoBinaria (int quadro[]);
int CamadaFisicaReceptoraCodificacaoManchester (int quadro[]);
int CamadaFisicaReceptoraCodificacaoBipolar (int quadro[]);
void CamadaDeAplicacaoReceptora (int quadro[]);
void AplicacaoReceptora(string mensagem);

#endif //SIMULADORCAMADAFISICA_CAMADAFISICA_HPP
