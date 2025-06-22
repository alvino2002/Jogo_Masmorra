#include "../headers/ObservadorPause.h"
#include "../headers/EstadoMenu.h"
#include "../headers/SalvarJogada.h"
#include "../headers/EstadoPrimeiraFase.h"


using namespace Masmorra::Observadores;


ObservadorPause::ObservadorPause() :
	Observador(),
	pSalvar(),
	pMenu(),
	pPrimeiro()
{
	pGG = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();
}


ObservadorPause::~ObservadorPause()
{
	pMenu = nullptr;
	pPrimeiro = nullptr;

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

		pPrimeiro = dynamic_cast<Estados::EstadoPrimeiraFase*>(pGEs->getEstado(1));
		/*Verificar se o proximo estado da pilha é primeira fase, se for, o cast dá certo, se nao, recebe nullptr*/

		if (pPrimeiro)
		{
			pSalvar->salvarFase(1);
		}
		else
		{
			pSalvar->salvarFase(2);
		}
	}
}