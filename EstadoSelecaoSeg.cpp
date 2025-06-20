#include "EstadoSelecaoSeg.h"


using namespace Masmorra::Estados;


EstadoSelecaoSeg::EstadoSelecaoSeg() :
	Estado()
{
	pSelecaoSegunda = new Masmorra::Interfaces::SelecaoSegunda(2);
	pObs = new Observadores::ObservadorSelecaoSeg();
}

EstadoSelecaoSeg::~EstadoSelecaoSeg()
{
	if (pSelecaoSegunda)
	{
		delete pSelecaoSegunda;
		pSelecaoSegunda = nullptr;
	}

	if (pObs)
	{
		delete pObs;
		pObs = nullptr;
	}
}

void EstadoSelecaoSeg::executar()
{
	pSelecaoSegunda->executar();
}

void EstadoSelecaoSeg::verificarEvento()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		if (pObs)
		{
			pObs->notificarEvento("1 JOGADOR");
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		if (pObs)
		{
			pObs->notificarEvento("2 JOGADOR");
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
	{
		if (pObs)
		{
			pObs->notificarEvento("VOLTAR");
		}
	}
}