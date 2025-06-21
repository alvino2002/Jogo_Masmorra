#include "../headers/EstadoMenu.h"


using namespace Masmorra::Estados;


EstadoMenu::EstadoMenu() :
	Estado()
{
	pMenu = new Interfaces::Menu(2);
	pObs = new Observadores::ObservadorMenu();
}

EstadoMenu::~EstadoMenu()
{
	if (pMenu)
	{
		delete pMenu;
		pMenu = nullptr;
	}

	if (pObs)
	{
		delete pObs;
		pObs = nullptr;
	}
}

void EstadoMenu::executar()
{
	pMenu->executar();
}

void EstadoMenu::verificarEvento()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		if (pObs)
		{
			pObs->notificarEvento("PRIMEIRA FASE");
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (pObs)
		{
			pObs->notificarEvento("SEGUNDA FASE");
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		if (pObs)
		{
			pObs->notificarEvento("RANKING");
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
	{
		if (pObs)
		{
			pObs->notificarEvento("JOGO SALVO");
		}
	}
}
