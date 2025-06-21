#include "../headers/Entidade.h"


using namespace Masmorra::Entidades;


Entidade::Entidade(int id, sf::Vector2f tam, sf::Vector2f posicao, sf::Vector2f vel) :
	Ente(id),
	corpo(),
	gravidade(980.f),
	naSuperficie(true),
	ativo(true)
{
	corpo.setSize(tam);
	corpo.setPosition(posicao);
	velocidade = vel;
}

Entidade::~Entidade()
{
}

/*Estamos retornando uma referencia, ja que alteraçoes feitas
no corpo devem feitas no proprio atributo e nao em uma copia*/
sf::RectangleShape& Entidade::getCorpo()
{
	if (this)
	{
		return corpo;
	}
}

sf::Vector2f Entidade::getTamanho()const
{
	return corpo.getSize();
}

void Entidade::aplicarGravidade(float deltaTime)
{
	velocidade.y += gravidade * deltaTime;
	corpo.move(0.0f, velocidade.y * deltaTime);
}

float Entidade::getVelocidadeX()const
{
	return velocidade.x;
}

float Entidade::getVelocidadeY()const
{
	return velocidade.y;
}

void Entidade::setVelocidadeX(float vX)
{
	velocidade.x = vX;
}

void Entidade::setVelocidadeY(float vY)
{
	velocidade.y = vY;
}

void Entidade::setNaSuperficie(bool superficie)
{
	naSuperficie = superficie;
}

void Entidade::setPosicao(sf::Vector2f pos)
{
	if (this)
	{
		corpo.setPosition(pos);
	}
}

void Entidade::setAtivo(bool at)
{
	ativo = at;
}

bool Entidade::getAtivo()const
{
	return ativo;
}

float Entidade::getPosicaoX()const
{
	return corpo.getPosition().x;
}

float Entidade::getPosicaoY()const
{
	return corpo.getPosition().y;
}

std::string Entidade::getBuffer()
{
	return buffer.str();
}