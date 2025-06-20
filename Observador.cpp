#include "Observador.h"


using namespace Masmorra::Observadores;


Observador::Observador()
{
	pGEs = Masmorra::Gerenciadores::GerenciadorEstado::getGerenciadorEstado();
}

Observador::~Observador()
{
}

Masmorra::Gerenciadores::GerenciadorEstado* Observador::pGEs = nullptr;