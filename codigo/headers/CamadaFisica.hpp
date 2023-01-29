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

/**
 * Inicializa o clock necessário para a codificação manchester
 * @param tamanhoClock Necessario para saber o tamanho do clock
 */
vi inicializadorDeClock(int);

/**
 * Inicializa a simulação da transmissão da mensagem
 */
void AplicacaoTransmissora();

/**
 * Converte a mensagem em um trem de bits
 * @param mensagem Mensagem que o usuario digitou
 */
void CamadaDeAplicacaoTransmissora (string);

/**
 * Responsável por delegar para outra função a codificação necessária
 * e transferir o resultado da codificacao para o MeioDeComunicacao
 * @param quadro Trem de bits
 */
void CamadaFisicaTransmissora (vi);


/**
 * Codificam o trem de bits de acordo com o algoritmo proposto
 * @param quadro Trem de bits
 */

vi CamadaFisicaTransmissoraCodificacaoBinaria (vi);
vi CamadaFisicaTransmissoraCodificacaoManchester (vi);
vi CamadaFisicaTransmissoraCodificacaoBipolar (vi);

/**
 * Simula a transmissão da mensagem codificada em um meio de transmissão
 * @param fluxoBrutoDeBits Trem de bits codificado
 */
void MeioDeComunicacao (vi fluxoBrutoDeBits);

/**
 * Nessa parte, a mensagem esta no receptor, pois já foi transferida no MeioDeComunicacao.
 * Responsável por delegar para outra função a decodificação necessária para encontrar o trem de bits original
 * e transferir o resultado da codificacao para o MeioDeComunicacao
 * @param quadro Trem de bits codificado
 */
void CamadaFisicaReceptora (vi);

/**
 * Decodificam o trem de bits de acordo com o algoritmo proposto
 * @param quadro Trem de bits codificado
 */
vi CamadaFisicaReceptoraCodificacaoBinaria (vi);
vi CamadaFisicaReceptoraCodificacaoManchester (vi);
vi CamadaFisicaReceptoraCodificacaoBipolar (vi);

/**
 * Converte o trme de bits na mensagem original
 * @param quadro Trem de bits original
 */
void CamadaDeAplicacaoReceptora (vi);

/**
 * Exibe a mensagem recebida
 * @param mensagem Mensagem que foi recebida
 */
void AplicacaoReceptora(string);

#endif //SIMULADORCAMADAFISICA_CAMADAFISICA_HPP
