#include "../headers/EstadoPause.h"


using namespace Masmorra::Estados;


EstadoPause::EstadoPause() :
	Estado()
{
	pPause = new Interfaces::Pause(2);
	pObs = new Observadores::ObservadorPause();
}

EstadoPause::~EstadoPause()
{
	if (pPause)
	{
		delete pPause;
		pPause = nullptr;
	}

	if (pObs)
	{
		delete pObs;
		pObs = nullptr;
	}
}

void EstadoPause::executar()
{
	pPause->executar();
	pGT->reiniciar(); // Devemos reiniciar o relogio para nao haver acumulo de velocidade
}

void EstadoPause::verificarEvento()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		if (pObs)
		{
			pObs->notificarEvento("DESPAUSE");
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		if (pObs)
		{
			pObs->notificarEvento("SALVAR");
		}
	}
}