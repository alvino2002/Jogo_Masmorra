#include "../headers/EstadoRanking.h"


using namespace Masmorra::Estados;


EstadoRanking::EstadoRanking() :
	Estado()
{
	pR = new Masmorra::Interfaces::Ranking(2);
	pObs = new Observadores::ObservadorRanking();
}

EstadoRanking::~EstadoRanking()
{
	if (pR)
	{
		delete pR;
		pR = nullptr;
	}

	if (pObs)
	{
		delete pObs;
		pObs = nullptr;
	}
}

void EstadoRanking::executar()
{
	pR->executar();
}

void EstadoRanking::verificarEvento()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
	{
		pObs->notificarEvento("VOLTAR");
	}
}