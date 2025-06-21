#include "../headers/Fase.h"
#include "../headers/GerenciadorColisao.h"


using namespace Masmorra::Fases;


Fase::Fase(int id, int qtdeJogadores, bool novoJogo) :
	Ente(id),
	pCav(),
	pCur(),
	camera(),
	numeroInimigos(),
	numeroAranhas(),
	fimDaFase(false),
	quantidadeJogadores(qtdeJogadores),
	janela(),
	listaEntidades()
{
	listaEntidades.limparLista();
	pGC->zerarListas();

	imagem_cenario = new sf::Texture();
	fundo_cenario = new sf::Sprite();
	imagem_cenario->loadFromFile("fundo_preto.jpg");
	fundo_cenario->setTexture(*imagem_cenario);

	if (novoJogo)
	{
		if (quantidadeJogadores == 1)
		{
			pCav = new Entidades::Personagens::Cavaleiro(1,
				sf::Vector2f(50.f, 70.f),
				sf::Vector2f(860.f, 430.f),
				sf::Vector2f(200.f, 0.f),
				10, 110.0f, 20);

			pCur = nullptr;

			Entidades::Obstaculos::Obstaculo::setCavaleiro(pCav); // Inimigos conhecerem o cavaleiro
			Entidades::Personagens::Inimigo::setCavaleiro(pCav);

			pGC->incluirJogador(pCav);

			listaEntidades.incluirEntidade(pCav);

		}

		else // quantidadeJogadores == 2;
		{
			pCav = new Entidades::Personagens::Cavaleiro(1,
				sf::Vector2f(50.f, 70.f),
				sf::Vector2f(860.f, 430.f),
				sf::Vector2f(200.f, 0.f),
				100, 110.0f, 20);

			pCur = new Entidades::Personagens::Curandeira(1,
				sf::Vector2f(50.f, 70.f),
				sf::Vector2f(860.f, 430.f),
				sf::Vector2f(200.f, 0.f),
				30, 110.0f);

			Entidades::Obstaculos::Obstaculo::setCurandeira(pCur); // Obstaculos conhecerem a curandeira
			Entidades::Personagens::Inimigo::setCurandeira(pCur);

			Entidades::Obstaculos::Obstaculo::setCavaleiro(pCav); // Inimigos conhecerem o cavaleiro
			Entidades::Personagens::Inimigo::setCavaleiro(pCav);

			listaEntidades.incluirEntidade(pCav);
			listaEntidades.incluirEntidade(pCur);

			pCur->setCavaleiro(pCav);

			pGC->incluirJogador(pCav);
			pGC->incluirJogador(pCur);
		}
	}
}

Fase::~Fase()
{
	delete fundo_cenario;
	delete imagem_cenario;
	listaEntidades.limparLista();
	pGC->zerarListas();
}

void Fase::setFimDaFase(bool fim)
{
	fimDaFase = fim;
}

bool Fase::getFimDaFase()const
{
	return fimDaFase;
}

int Fase::getQtdeJogadores()const
{
	return quantidadeJogadores;
}

void Fase::setarCamera()
{
	camera.setSize(sf::Vector2f(800.f, 600.f));

	janela = pGG->getJanela();

	/*Ajustando a camera ao cavaleiro*/
	for (int i = listaEntidades.getTam() - 1; i >= 0; i--)
	{
		Entidades::Entidade* pE = listaEntidades.getEntidade(i);

		Entidades::Personagens::Cavaleiro* cavaleiro = dynamic_cast<Entidades::Personagens::Cavaleiro*>(pE);

		if (cavaleiro)
		{
			sf::Vector2f pos = (cavaleiro->getCorpo().getPosition());  // Posicao do jogador
			sf::Vector2f cameraPos = pos;

			/*Limites para manter a camera dentro do mundo*/
			float meiaLargura = camera.getSize().x / 2.f;
			float meiaAltura = camera.getSize().y / 2.f;

			if (pos.x < meiaLargura)
			{
				cameraPos.x = meiaLargura;
			}
			else if (pos.x > (10000 - meiaLargura))
			{
				cameraPos.x = 10000 - meiaLargura;
			}

			if (pos.y < meiaAltura)
			{
				cameraPos.y = meiaAltura;
			}
			else if (pos.y > (5050 - meiaAltura))
			{
				cameraPos.y = 5050 - meiaAltura;
			}

			// Atualiza a view com a posicao ajustada
			camera.setCenter(cameraPos);
			janela->setView(camera);

			break;
		}
	}
}

void Fase::desenharFundo()
{
	//sf::RenderWindow* janela = pGG->getJanela();
	auto janela = pGG->getJanela();
	sf::Vector2f TopoEsquerda = camera.getCenter() - camera.getSize() * 0.7f;
	fundo_cenario->setPosition(TopoEsquerda);
	janela->draw(*fundo_cenario);
}