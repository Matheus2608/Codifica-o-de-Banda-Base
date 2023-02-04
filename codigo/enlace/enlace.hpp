#include <bitset>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define endln "\n"

// Transmissora
void CamadaEnlaceDadosTransmissora(vi);
void CamadaEnlaceDadosTransmissoraEnquadramento(vi);
void CamadaEnlaceDadosTransmissoraControleDeErro(vi);
vi CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(vi);
vi CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(vi);

// Receptora
void CamadaEnlaceDadosReceptora(vi);
void CamadaEnlaceDadosReceptoraEnquadramento(vi);
vi CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(vi);
vi CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(vi);
