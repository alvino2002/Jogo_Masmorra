#include "Jogador.h"


using namespace Masmorra::Entidades::Personagens;


Jogador::Jogador(int id, sf::Vector2f tamanho, sf::Vector2f posicao, sf::Vector2f velocidade, int vida, float pul) :
	Personagem(id, tamanho, posicao, velocidade, vida),
	tempoInvulneravel(),
	duracaoInvulneravel(2.0f),
	invulneravel(false),
	velAtual(),
	pulo(pul)
{
}

Jogador::~Jogador()
{
}

void Jogador::mover()
{
	float deltaTime = pGT->getDeltaTempo();

	if (naSuperficie)
	{
		velAtual.y = 0;
	}
	else
	{
		velAtual.y += gravidade * deltaTime;
	}

	corpo.move(velAtual * deltaTime);
}

void Jogador::sofrerDano(int d)
{
	vida -= d;
	perderPonto();
}

void Jogador::invulnerabilizar()
{
	tempoInvulneravel.restart();
	setInvulneravel(true);
}

void Jogador::setInvulneravel(bool imune)
{
	invulneravel = imune;
}

bool Jogador::getInvulneravel()const
{
	return invulneravel;
}

void Jogador::verificarInvulnerabilidade()
{
	if (invulneravel && tempoInvulneravel.getElapsedTime().asSeconds() >= duracaoInvulneravel)
	{
		setInvulneravel(false);
	}

	if (invulneravel)
	{
		float tempoPiscar = tempoInvulneravel.getElapsedTime().asSeconds();
		bool visivel = static_cast<int>(tempoPiscar * 10) % 2 == 0;
		corpo.setFillColor(visivel ? sf::Color::White : sf::Color::Transparent);
	}
	else
	{
		corpo.setFillColor(sf::Color::White);
	}
}

void Jogador::derrotarAranha()
{
	pontuacao += 50;
}

void Jogador::derrotarEsqueleto()
{
	pontuacao += 20;
}

void Jogador::derrotarMago()
{
	pontuacao += 300;
}

void Jogador::perderPonto()
{
	pontuacao -= 1;
}

void Jogador::setPontuacao(int pontos)
{
	pontuacao = pontos;
}

int Jogador::getPontuacao()
{
	return pontuacao;
}

int Jogador::pontuacao = 0;