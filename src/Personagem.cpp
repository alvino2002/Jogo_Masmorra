#include "../headers/Personagem.h"


using namespace Masmorra::Entidades::Personagens;


Personagem::Personagem(int id, sf::Vector2f tam, sf::Vector2f posicao, sf::Vector2f velocidade, int v) :
	Entidade(id, tam, posicao, velocidade),
	olhandoDireita(false),
	vida(v)
{
}

Personagem::~Personagem()
{
}

void Personagem::setVida(int v)
{
	vida = v;
}

int Personagem::getVida()const
{
	if (this)
	{
		return vida;
	}
}

void Personagem::setVivo(bool v)
{
	if (v == false)
	{
		setAtivo(false); // Personagem nao esta mais ativo no jogo
	}
}

bool Personagem::getOlhandoDireita()const
{
	return olhandoDireita;
}
