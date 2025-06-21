#include "../headers/ObservadorSegundaFase.h"
#include "../headers/EstadoMenu.h"
#include "../headers/EstadoPause.h"
#include "../headers/EstadoFim.h"


using namespace Masmorra::Observadores;


ObservadorSegundaFase::ObservadorSegundaFase() :
	Observador(),
	pSeg(),
	pPause(),
	pFim(),
	pMenu()
{
}

ObservadorSegundaFase::~ObservadorSegundaFase()
{
	pSeg = nullptr;
	pPause = nullptr;
	pFim = nullptr;
	pMenu = nullptr;
}

void ObservadorSegundaFase::notificarEvento(const std::string& evento)
{
	if (evento == "PAUSE")
	{
		pPause = new Estados::EstadoPause();
		pGEs->adicionarEstado(pPause);
	}


	if (evento == "VENCEU")
	{
		pSeg->escreverNome();
		pGEs->limparPilha();

		pMenu = new Estados::EstadoMenu();
		pGEs->adicionarEstado(pMenu);
	}

	if (evento == "FIM")
	{
		pFim = new Estados::EstadoFim();
		pGEs->adicionarEstado(pFim);
	}
}

void ObservadorSegundaFase::setSegundaFase(Fases::RecintoDosMagos* pSF)
{
	if (pSF)
	{
		pSeg = pSF;
	}
}