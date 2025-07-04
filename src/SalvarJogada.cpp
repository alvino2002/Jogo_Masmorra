#include "../headers/SalvarJogada.h"
#include "../headers/ZonaDosEsqueletos.h"
#include "../headers/RecintoDosMagos.h"
#include "../headers/EstadoPrimeiraFase.h"
#include "../headers/EstadoSegundaFase.h"
#include <fstream>
#include <iostream>


using namespace Masmorra;


SalvarJogada::SalvarJogada():
	pPrim(),
	pSeg()
{
	pGEs = Gerenciadores::GerenciadorEstado::getGerenciadorEstado();
}

SalvarJogada::~SalvarJogada()
{
	pGEs = nullptr;
	pPrim = nullptr;
	pSeg = nullptr;
}

void SalvarJogada::salvarFase(int fase)
{
	if (fase == 1)
	{
		pPrimeira->salvarFase();
	}
	else
	{
		pSegunda->salvarFase();
	}
}


void SalvarJogada::setPrimeiraFase(Fases::ZonaDosEsqueletos* pP)
{
	if (pP)
	{
		pPrimeira = pP;
	}
}

void SalvarJogada::setSegundaFase(Fases::RecintoDosMagos* pS)
{
	if (pS)
	{
		pSegunda = pS;
	}
}


void SalvarJogada::executar()
{
	try
	{
		std::ifstream arquivo("txt/fase.txt");
		std::string primeiraLinha;
		std::getline(arquivo, primeiraLinha);

		if (primeiraLinha == "Fase1")
		{
			pPrim = new Estados::EstadoPrimeiraFase(2, false); // Nao eh mais novo jogo;
			pGEs->adicionarEstado(pPrim);
		}

		else // Fase2
		{
			pSeg = new Estados::EstadoSegundaFase(2, false); // Nao eh mais novo jogo;
			pGEs->adicionarEstado(pSeg);
		}
	}
	catch (...)
	{
		std::cout << "Erro na leitura" << std::endl;
	}

}

Masmorra::Fases::ZonaDosEsqueletos* Masmorra::SalvarJogada::pPrimeira = nullptr;
Masmorra::Fases::RecintoDosMagos* Masmorra::SalvarJogada::pSegunda = nullptr;