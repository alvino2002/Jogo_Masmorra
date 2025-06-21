#include "../headers/ObservadorPrimeiraFase.h"
#include "../headers/EstadoPause.h"
#include "../headers/EstadoSegundaFase.h"
#include "../headers/GerenciadorEstado.h"
#include "../headers/EstadoRanking.h"
#include "../headers/EstadoFim.h"
#include "../headers/Fase.h"


using namespace Masmorra::Observadores;


ObservadorPrimeiraFase::ObservadorPrimeiraFase() :
	Observador(),
	pPrim(),
	pSeg(),
	pFim(),
	pPause()
{
}

ObservadorPrimeiraFase::~ObservadorPrimeiraFase()
{
	pPause = nullptr;
	pFim = nullptr;
	pSeg = nullptr;
	pPrim = nullptr;
}

void ObservadorPrimeiraFase::notificarEvento(const std::string& evento)
{
	if (evento == "PAUSE")
	{
		pPause = new Estados::EstadoPause();
		pGEs->adicionarEstado(pPause);
	}

	if (evento == "FIM")
	{
		pFim = new Estados::EstadoFim();
		pGEs->adicionarEstado(pFim);
	}

	if (evento == "AVANCAR")
	{
		if (pPrim->getQtdeJogadores() == 1)
		{
			pSeg = new Estados::EstadoSegundaFase(1, true);
			pGEs->adicionarEstado(pSeg);
		}

		else
		{
			pSeg = new Estados::EstadoSegundaFase(2, true);
			pGEs->adicionarEstado(pSeg);
		}
	}
}

void ObservadorPrimeiraFase::setPrimeiraFase(Fases::ZonaDosEsqueletos* pP)
{
	if (pP)
	{
		pPrim = pP;
	}
}
