#include "EstadoSegundaFase.h"


using namespace Masmorra::Estados;


EstadoSegundaFase::EstadoSegundaFase(int qtdeJogadores, bool novoJogo) :
	Estado()
{
	pSegFase = new Fases::RecintoDosMagos(2, qtdeJogadores, novoJogo);
	pObs = new Observadores::ObservadorSegundaFase();
	pObs->setSegundaFase(pSegFase);
	Masmorra::SalvarJogada::setSegundaFase(pSegFase);
}

EstadoSegundaFase::~EstadoSegundaFase()
{
	if (pSegFase)
	{
		delete pSegFase;
		pSegFase = nullptr;
	}

	if (pObs)
	{
		delete pObs;
		pObs = nullptr;
	}
}

void EstadoSegundaFase::executar()
{
	pSegFase->executar();
}

void EstadoSegundaFase::verificarEvento()
{
	if (pObs)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) // Pause
		{
			pObs->notificarEvento("PAUSE");
		}

		if (pSegFase->getFimDaFase()) // Fim do jogo
		{
			pObs->notificarEvento("FIM");
		}

		if (pSegFase->getVenceu()) // Fim do jogo
		{
			pObs->notificarEvento("VENCEU");
		}
	}
}