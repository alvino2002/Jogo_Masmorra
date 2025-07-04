#include "../headers/Plataforma.h"


using namespace Masmorra::Entidades::Obstaculos;


Plataforma::Plataforma(int id, sf::Vector2f tam, sf::Vector2f posicao, bool arm) :
	Obstaculo(id, tam, posicao),
	armadilha(arm)
{
	corpo.setFillColor(sf::Color(105, 105, 105)); // cinza

}

Plataforma::~Plataforma()
{
}

void Plataforma::executar()
{
	salvarDataBuffer();

	float deltaTempo = pGT->getDeltaTempo();
	aplicarGravidade(deltaTempo);
	flutuar(deltaTempo);
}


void Plataforma::obstacularizar(Entidade* pE)
{
	sf::Vector2f posicao_Entidade = pE->getCorpo().getPosition();
	sf::Vector2f tamanho_Entidade = pE->getCorpo().getSize();
	sf::Vector2f posicao_Plataforma = getCorpo().getPosition();
	sf::Vector2f tamanho_Plataforma = getCorpo().getSize();

	if (pGC->getInterseccaoX() > pGC->getInterseccaoY())
	{
		if (posicao_Entidade.x < posicao_Plataforma.x)
		{
			posicao_Entidade.x += pGC->getInterseccaoX();
		}
		else
		{
			posicao_Entidade.x -= pGC->getInterseccaoX();
		}
	}

	if (pGC->getInterseccaoX() < pGC->getInterseccaoY())
	{
		if (posicao_Entidade.y < posicao_Plataforma.y)
		{
			if (armadilha)
			{
				Personagens::Jogador* pJ = static_cast<Personagens::Jogador*>(pE);
				if (pJ->getInvulneravel() == false)
				{
					pJ->sofrerDano(1);
					pJ->invulnerabilizar();
				}
			}
			posicao_Entidade.y += pGC->getInterseccaoY();
			pE->setNaSuperficie(true);
			pE->setVelocidadeY(0.0f);
		}
		else
		{
			posicao_Entidade.y -= pGC->getInterseccaoY();
		}
	}

	pE->setPosicao(posicao_Entidade);
}


void Plataforma::flutuar(float deltaTempo)
{
	corpo.move(0.0f, -velocidade.y * deltaTempo);
}

void Plataforma::salvarDataBuffer()
{
	buffer.str("");
	buffer.clear();
	buffer << "Plataforma" << ' ' << getPosicaoX() << ' ' << getPosicaoY() << ' ' << getTamanho().x << ' ' << getTamanho().y <<
		' ' << armadilha << '\n';
	/*posicao, tamanho, armadilha*/
	/*resto sao fixos*/
}