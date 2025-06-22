#include "../headers/Lava.h"


using namespace Masmorra::Entidades::Obstaculos;


Lava::Lava(int id, sf::Vector2f tam, sf::Vector2f posicao) :
	Obstaculo(id, tam, posicao),
	dano(2)
{
	texturaLava = new sf::Texture();
	texturaLava->loadFromFile("texturas e fonte/lava_sprite.png");
	corpo.setTexture(texturaLava);
	pGA->pegarAnimacao(texturaLava, sf::Vector2u(1, 1));
}

Lava::~Lava()
{
	delete texturaLava;
	texturaLava = nullptr;
}

void Lava::executar()
{
	salvarDataBuffer();

	if (!naSuperficie)
	{
		float deltaTime = pGT->getDeltaTempo();
		aplicarGravidade(deltaTime);
	}
}

void Lava::obstacularizar(Entidade* pE)
{
	sf::Vector2f posicao_Entidade = pE->getCorpo().getPosition();
	sf::Vector2f tamanho_Entidade = pE->getCorpo().getSize();
	sf::Vector2f posicao_Lava = getCorpo().getPosition();
	sf::Vector2f tamanho_Lava = getCorpo().getSize();

	Personagens::Jogador* ehJog = dynamic_cast<Personagens::Jogador*>(pE);
	Plataforma* ehPlat = dynamic_cast<Plataforma*>(pE);

	if (pGC->getInterseccaoX() > pGC->getInterseccaoY())
	{
		if (!ehPlat)
		{
			if (posicao_Entidade.x < posicao_Lava.x)
			{
				posicao_Entidade.x += pGC->getInterseccaoX();
			}
			else
			{
				posicao_Entidade.x -= pGC->getInterseccaoX();
			}
		}
	}

	else
	{
		if (posicao_Entidade.y < posicao_Lava.y) // Jogador por cima
		{
			posicao_Entidade.y += pGC->getInterseccaoY();
			pE->setNaSuperficie(true);

			if (ehJog)
			{
				if (ehJog->getInvulneravel() == false)
				{
					ehJog->sofrerDano(dano);
					ehJog->invulnerabilizar();
				}
			}
		}
		else
		{
			if (!ehPlat)
			{
				posicao_Entidade.y -= pGC->getInterseccaoY();
			}
		}
	}
	pE->setPosicao(posicao_Entidade);
}

void Lava::salvarDataBuffer()
{
	buffer.str("");
	buffer.clear();
	buffer << "Lava" << ' ' << getPosicaoX() << ' ' << getPosicaoY() << ' ' << getTamanho().x << ' '
		<< getTamanho().y << '\n';
	/*posicao, tamanho*/
	/*resto sao fixos*/
}
