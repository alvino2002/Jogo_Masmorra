#include "GerenciadorTempo.h"


using namespace Masmorra::Gerenciadores;


GerenciadorTempo::GerenciadorTempo() :
	deltaTempo(),
	relogio()
{
}

GerenciadorTempo::~GerenciadorTempo()
{
}

GerenciadorTempo* GerenciadorTempo::getGerenciadorTempo()
{
	if (pGerenciadorTempo == nullptr)
	{
		pGerenciadorTempo = new GerenciadorTempo();
	}
	else
	{
		return pGerenciadorTempo;
	}
}

void GerenciadorTempo::reiniciar()
{
	deltaTempo = relogio.restart().asSeconds();
}

float GerenciadorTempo::getDeltaTempo() const
{
	return deltaTempo;
}

void GerenciadorTempo::deletar()
{
	if (pGerenciadorTempo)
	{
		delete pGerenciadorTempo;
		pGerenciadorTempo = nullptr;
	}
}

GerenciadorTempo* GerenciadorTempo::pGerenciadorTempo = nullptr;