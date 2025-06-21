#include "../headers/ObservadorSelecaoPrim.h"
#include "../headers/EstadoPrimeiraFase.h"


using namespace Masmorra::Observadores;


ObservadorSelecaoPrim::ObservadorSelecaoPrim() :
	Observador(),
	pPrim()
{
}


ObservadorSelecaoPrim::~ObservadorSelecaoPrim()
{
	pPrim = nullptr;
}


void ObservadorSelecaoPrim::notificarEvento(const std::string& evento)
{
	if (evento == "1 JOGADOR")
	{
		pPrim = new Estados::EstadoPrimeiraFase(1, true);
		pGEs->adicionarEstado(pPrim);
	}

	if (evento == "2 JOGADOR")
	{
		pPrim = new Estados::EstadoPrimeiraFase(2, true);
		pGEs->adicionarEstado(pPrim);
	}

	if (evento == "VOLTAR")
	{
		pGEs->removerTopo(); // Voltar ao Menu, removendo o estado atual, no caso SelecaoPrim
	}
}