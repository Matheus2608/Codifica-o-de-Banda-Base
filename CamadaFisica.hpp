#ifndef SIMULADORCAMADAFISICA_CAMADAFISICA_HPP
#define SIMULADORCAMADAFISICA_CAMADAFISICA_HPP
#include <bitset>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define endln "\n"

void AplicacaoTransmissora();
void CamadaDeAplicacaoTransmissora (string mensagem);
void CamadaFisicaTransmissora (vi quadro);
vi CamadaFisicaTransmissoraCodificacaoBinaria (vi quadro);
vi CamadaFisicaTransmissoraCodificacaoManchester (vi quadro);
vi CamadaFisicaTransmissoraCodificacaoBipolar (vi quadro);
void MeioDeComunicacao (vi fluxoBrutoDeBits);
void CamadaFisicaReceptora (vi quadro);
vi CamadaFisicaReceptoraCodificacaoBinaria (vi quadro);
vi CamadaFisicaReceptoraCodificacaoManchester (vi quadro);
vi CamadaFisicaReceptoraCodificacaoBipolar (vi quadro);
void CamadaDeAplicacaoReceptora (vi quadro);
void AplicacaoReceptora(string mensagem);

#endif //SIMULADORCAMADAFISICA_CAMADAFISICA_HPP
