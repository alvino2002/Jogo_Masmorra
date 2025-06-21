#include "../headers/ObservadorRanking.h"
#include "../headers/EstadoMenu.h"


using namespace Masmorra::Observadores;


ObservadorRanking::ObservadorRanking() :
	Observador(),
	pMenu()
{
}

ObservadorRanking::~ObservadorRanking()
{
	pMenu = nullptr;
}

void ObservadorRanking::notificarEvento(const std::string& evento)
{
	if (evento == "VOLTAR")
	{
		pGEs->removerTopo();
		pMenu = new Estados::EstadoMenu();
		pGEs->adicionarEstado(pMenu);
	}
}
