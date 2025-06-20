#include "EstadoPrimeiraFase.h"


using namespace Masmorra::Estados;


EstadoPrimeiraFase::EstadoPrimeiraFase(int qtdeJogadores, bool novoJogo) :
	Estado()
{
	pPrimFase = new Fases::ZonaDosEsqueletos(2, qtdeJogadores, novoJogo);
	pObs = new Observadores::ObservadorPrimeiraFase();
	pObs->setPrimeiraFase(pPrimFase);
	Masmorra::SalvarJogada::setPrimeiraFase(pPrimFase);
}

EstadoPrimeiraFase::~EstadoPrimeiraFase()
{
	if (pPrimFase)
	{
		delete pPrimFase;
		pPrimFase = nullptr;
	}

	if (pObs)
	{
		delete pObs;
		pObs = nullptr;
	}
}

void EstadoPrimeiraFase::executar()
{
	pPrimFase->executar();
}

void EstadoPrimeiraFase::verificarEvento()
{
	if (pObs)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			pObs->notificarEvento("PAUSE");
		}

		if (pPrimFase->getFimDaFase())
		{
			pObs->notificarEvento("FIM");// Fim do jogo
		}

		if (pPrimFase->getAvance())
		{
			pObs->notificarEvento("AVANCAR"); // Avancar para a segunda fase
		}
	}
}