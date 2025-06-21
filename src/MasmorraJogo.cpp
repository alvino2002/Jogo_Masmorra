#include "../headers/MasmorraJogo.h"
#include "../headers/EstadoMenu.h"


using namespace Masmorra;


MasmorraJogo::MasmorraJogo()
{
	pGEs = Gerenciadores::GerenciadorEstado::getGerenciadorEstado();
	pGG = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();
	pGC = Gerenciadores::GerenciadorColisao::getGerenciadorColisao();
}

MasmorraJogo::~MasmorraJogo()
{
	pGEs = nullptr;
	pGG = nullptr;
	pGC = nullptr;
}

void MasmorraJogo::rodarJogo()
{
	Estados::EstadoMenu* estado = new Estados::EstadoMenu();
	pGEs->adicionarEstado(estado);

	while (pGG->verificaJanelaAberta())
	{
		sf::Event evento;

		while (pGG->getJanela()->pollEvent(evento))
		{
			if (evento.type == sf::Event::Closed)
			{
				pGG->fecharJanela();
			}
		}
		pGEs->executar();
	}
}