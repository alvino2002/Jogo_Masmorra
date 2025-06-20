#include "EstadoSelecaoPrim.h"


using namespace Masmorra::Estados;


EstadoSelecaoPrim::EstadoSelecaoPrim() :
	Estado()
{
	pSelecaoPrim = new Masmorra::Interfaces::SelecaoPrimeira(2);
	pObs = new Observadores::ObservadorSelecaoPrim();
}

EstadoSelecaoPrim::~EstadoSelecaoPrim()
{
	if (pSelecaoPrim)
	{
		delete pSelecaoPrim;
		pSelecaoPrim = nullptr;
	}

	if (pObs)
	{
		delete pObs;
		pObs = nullptr;
	}
}

void EstadoSelecaoPrim::executar()
{
	pSelecaoPrim->executar();
}

void EstadoSelecaoPrim::verificarEvento()
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
