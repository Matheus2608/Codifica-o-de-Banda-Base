#include <bitset>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define endln "\n"

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
 * Converte o trme de bits na mensagem original
 * @param quadro Trem de bits original
 */
void CamadaDeAplicacaoReceptora (vi);

/**
 * Exibe a mensagem recebida
 * @param mensagem Mensagem que foi recebida
 */
void AplicacaoReceptora(string);
