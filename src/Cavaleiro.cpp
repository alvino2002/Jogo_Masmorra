#include "../headers/Cavaleiro.h"
#include <iostream>


using namespace Masmorra::Entidades::Personagens;


Cavaleiro::Cavaleiro(int id, sf::Vector2f tamanho, sf::Vector2f posicao, sf::Vector2f velocidade, int vida, float pulo, int energia) :
	Jogador(id, tamanho, posicao, velocidade, vida, pulo),
	estaAtacando(false),
	dano(2),
	energia(energia),
	tempoRecuperar(),
	duracaoRecuperacao(3.0f),
	tempoAtaque(),
	recargaAtaque(0.5f),
	ataquePronto(true)
{
	texturaCavaleiro = new sf::Texture();
	texturaCavaleiro->loadFromFile("texturas e fonte/knight_Sprite.png");
	corpo.setTexture(texturaCavaleiro);
	pGA->pegarAnimacao(texturaCavaleiro, sf::Vector2u(4, 4));
}

Cavaleiro::~Cavaleiro()
{
	delete texturaCavaleiro;
	texturaCavaleiro = nullptr;
}

void Cavaleiro::executar()
{
	std::cout << vida << std::endl;

	velAtual.x = 0;
	/*Movimento do cavaleiro*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velAtual.x -= velocidade.x;
		olhandoDireita = false;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velAtual.x += velocidade.x;
		olhandoDireita = true;
	}

	/*Pulo do cavaleiro*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (naSuperficie))
	{
		velAtual.y = -sqrtf(2.0f * gravidade * pulo);

		if (naSuperficie) // Em cima da plataforma
		{
			naSuperficie = false;
		}
	}

	mover();

	verificarInvulnerabilidade();

	/*Ataque do cavaleiro*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && ataquePronto && energia)
	{
		setEstaAtacando(true);
		ataquePronto = false;
		tempoAtaque.restart();
		operator--();
	}

	else if (tempoAtaque.getElapsedTime().asSeconds() >= recargaAtaque)
	{
		ataquePronto = true;     // Libera o próximo ataque
		setEstaAtacando(false); // Desativa o estado de ataque
	}

	if (energia == 0 && tempoRecuperar.getElapsedTime().asSeconds() >= duracaoRecuperacao)
	{
		recuperar();
	}

	/*Oi*/

	if (vida <= 0)
	{
		setVivo(false);
	}

	/*Atualizar a animacao*/
	unsigned int linha = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		linha = 2; // Atacando
	}

	else if (velAtual.x != 0.0f)
	{
		linha = 1; // Correndo
	}

	else
	{
		linha = 0; // Parado
	}

	pGA->atualizar(linha, olhandoDireita);

	corpo.setTextureRect(pGA->getFrameAtual());

	salvarDataBuffer();
}

bool Cavaleiro::getEstaAtacando()const
{
	return estaAtacando;
}

void Cavaleiro::setEstaAtacando(bool atacando)
{
	estaAtacando = atacando;
}

int Cavaleiro::getDano()const
{
	return dano;
}

void Cavaleiro::operator--()
{
	if (energia > 0)
	{
		energia--;

		if (energia == 0)
		{
			tempoRecuperar.restart();
		}
	}
}

void Cavaleiro::recuperar()
{
	energia = 10;
}

void Cavaleiro::operator++()
{
	inimigosEliminados++;
}

int Cavaleiro::getInimigosEliminados()
{
	return inimigosEliminados;
}

void Cavaleiro::setInimigosEliminados(int numeroInimigos)
{
	inimigosEliminados = numeroInimigos;
}

void Cavaleiro::salvarDataBuffer()
{
	buffer.str("");
	buffer.clear();
	buffer << "Cavaleiro" << ' ' << getPosicaoX() << ' ' << getPosicaoY() << ' ' << getVelocidadeX() << ' ' << 0 << ' '
		<< vida << ' ' << energia << ' ' << pontuacao << '\n';
	/*posicao, velocidade, vida, energia, pontuacao*/
	/*resto sao fixos*/
}

int Masmorra::Entidades::Personagens::Cavaleiro::inimigosEliminados = 0;