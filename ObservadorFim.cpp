#include "ObservadorFim.h"
#include "GerenciadorEstado.h"
#include "EstadoMenu.h"


using namespace Masmorra::Observadores;


ObservadorFim::ObservadorFim() :
	Observador(),
	pMenu()
{
}

ObservadorFim::~ObservadorFim()
{
	pMenu = nullptr;
}

void ObservadorFim::notificarEvento(const std::string& evento)
{
	if (evento == "SAIR")
	{
		pMenu = new Estados::EstadoMenu();
		pGEs->adicionarEstado(pMenu);
	}
}