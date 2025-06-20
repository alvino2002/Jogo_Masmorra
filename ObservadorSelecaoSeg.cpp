#include "ObservadorSelecaoSeg.h"
#include "EstadoSegundaFase.h"


using namespace Masmorra::Observadores;


ObservadorSelecaoSeg::ObservadorSelecaoSeg() :
	Observador(),
	pSeg()
{
}


ObservadorSelecaoSeg::~ObservadorSelecaoSeg()
{
	pSeg = nullptr;
}

void ObservadorSelecaoSeg::notificarEvento(const std::string& evento)
{
	if (evento == "1 JOGADOR")
	{
		pSeg = new Estados::EstadoSegundaFase(1, true);
		pGEs->adicionarEstado(pSeg);
	}

	if (evento == "2 JOGADOR")
	{
		pSeg = new Estados::EstadoSegundaFase(2, true);
		pGEs->adicionarEstado(pSeg);
	}

	if (evento == "VOLTAR")
	{
		pGEs->removerTopo(); // Voltar ao Menu, removendo o estado atual, no caso SelecaoSeg
	}
}