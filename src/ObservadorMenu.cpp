#include "../headers/ObservadorMenu.h"
#include "../headers/EstadoSelecaoPrim.h"
#include "../headers/EstadoSelecaoSeg.h"
#include "../headers/EstadoRanking.h"


using namespace Masmorra::Observadores;


ObservadorMenu::ObservadorMenu() :
	Observador(),
	pR(),
	pPrim(),
	pSeg(),
	pSalvar()
{
}

ObservadorMenu::~ObservadorMenu()
{
	pPrim = nullptr;
	pR = nullptr;
	pSeg = nullptr;

	if (pSalvar)
	{
		delete pSalvar;
		pSalvar = nullptr;
	}
}

void ObservadorMenu::notificarEvento(const std::string& evento)
{
	if (evento == "PRIMEIRA FASE")
	{
		pPrim = new Estados::EstadoSelecaoPrim();
		pGEs->adicionarEstado(pPrim);
	}

	if (evento == "SEGUNDA FASE")
	{
		pSeg = new Estados::EstadoSelecaoSeg();
		pGEs->adicionarEstado(pSeg);
	}

	if (evento == "RANKING")
	{
		pR = new Estados::EstadoRanking();
		pGEs->adicionarEstado(pR);
	}

	if (evento == "JOGO SALVO")
	{
		pSalvar = new SalvarJogada();
		pSalvar->executar();
	}
}