#include "../headers/Caixa.h"


using namespace Masmorra::Entidades::Obstaculos;


Caixa::Caixa(int id, sf::Vector2f tam, sf::Vector2f posicao) :
	Obstaculo(id, tam, posicao),
	lentidao(0.5f)
{
	texturaCaixa = new sf::Texture();
	texturaCaixa->loadFromFile("texturas e fonte/caixa_Sprite.png");
	corpo.setTexture(texturaCaixa);
	pGA->pegarAnimacao(texturaCaixa, sf::Vector2u(4, 4));
}

Caixa::~Caixa()
{
	delete texturaCaixa;
	texturaCaixa = nullptr;
}

void Caixa::executar()
{
	if (!naSuperficie)
	{
		float deltaTime = pGT->getDeltaTempo();
		aplicarGravidade(deltaTime);
	}

	salvarDataBuffer();
}

void Caixa::obstacularizar(Entidade* pE)
{
	sf::Vector2f posicao_Entidade = pE->getCorpo().getPosition();
	sf::Vector2f tamanho_Entidade = pE->getCorpo().getSize();
	sf::Vector2f posicao_Caixa = getCorpo().getPosition();
	sf::Vector2f tamanho_Caixa = getCorpo().getSize();

	bool ehCavaleiro = dynamic_cast<Personagens::Cavaleiro*>(pE) != nullptr;
	bool ehPlat = dynamic_cast<Plataforma*>(pE) != nullptr;


	if (pGC->getInterseccaoX() > pGC->getInterseccaoY())
	{
		if (ehCavaleiro) // Apenas o cavaleiro consegue empurrar a caixa
		{
			float deltaTime = pGT->getDeltaTempo();
			float velocidadeX = pCavaleiro->getVelocidadeX();
			float deslocamentoCaixa = velocidadeX * lentidao * deltaTime; // Ha uma desaceleracao ao empurrar

			if (posicao_Entidade.x < posicao_Caixa.x) // Empurra para direita
			{
				posicao_Entidade.x = posicao_Caixa.x - tamanho_Entidade.x;
				posicao_Caixa.x += deslocamentoCaixa;
			}
			else  // Empurra para esquerda
			{
				posicao_Entidade.x = posicao_Caixa.x + tamanho_Caixa.x;
				posicao_Caixa.x -= deslocamentoCaixa;
			}
		}
		else
		{
			if (!ehPlat) // Assumimos que plataforma eh totalmente estatico
			{
				if (posicao_Entidade.x < posicao_Caixa.x)
				{
					posicao_Entidade.x += pGC->getInterseccaoX();
				}
				else
				{
					posicao_Entidade.x -= pGC->getInterseccaoX();
				}
			}
		}
		getCorpo().setPosition(posicao_Caixa);
	}
	else // Colisão vertical
	{
		if (posicao_Entidade.y < posicao_Caixa.y)
		{
			posicao_Entidade.y += pGC->getInterseccaoY();
			pE->setNaSuperficie(true);
			pE->setVelocidadeY(0.0f);
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

void Caixa::salvarDataBuffer()
{
	buffer.str("");
	buffer.clear();
	buffer << "Caixa" << ' ' << getPosicaoX() << ' ' << getPosicaoY() << '\n';
	/*posicao, velocidade.Y = 0*/
	/*resto sao fixos*/
}