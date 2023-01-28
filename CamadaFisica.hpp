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
void MeioDeComunicacao (int fluxoBrutoDeBits[]);
void CamadaFisicaReceptora (int quadro[]);
int CamadaFisicaReceptoraCodificacaoBinaria (int quadro[]);
int CamadaFisicaReceptoraCodificacaoManchester (int quadro[]);
int CamadaFisicaReceptoraCodificacaoBipolar (int quadro[]);
void CamadaDeAplicacaoReceptora (int quadro[]);
void AplicacaoReceptora(string mensagem);

#endif //SIMULADORCAMADAFISICA_CAMADAFISICA_HPP
