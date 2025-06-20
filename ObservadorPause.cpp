#include "ObservadorPause.h"
#include "EstadoMenu.h"
#include "SalvarJogada.h"


using namespace Masmorra::Observadores;


ObservadorPause::ObservadorPause() :
	Observador(),
	pSalvar(),
	pMenu()
{
	pGG = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();
}


ObservadorPause::~ObservadorPause()
{
	pMenu = nullptr;

	if (pSalvar)
	{
		delete pSalvar;
		pSalvar = nullptr;
	}
}

void ObservadorPause::notificarEvento(const std::string& evento)
{
	if (evento == "DESPAUSE")
	{
		pGEs->removerTopo(); // Remover o topo
	}

	if (evento == "SALVAR")
	{
		pSalvar = new Masmorra::SalvarJogada();

		Estados::EstadoPrimeiraFase* primeiraFase = dynamic_cast<Estados::EstadoPrimeiraFase*>(pGEs->getEstado(1));
		/*Verificar se o proximo estado da pilha é primeira fase, se for, o cast dá certo, se nao, recebe nullptr*/

		if (primeiraFase)
		{
			pSalvar->salvarFase(1);
		}
		else
		{
			pSalvar->salvarFase(2);
		}
	}
}