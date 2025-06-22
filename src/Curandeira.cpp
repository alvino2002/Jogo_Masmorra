#include "../headers/Curandeira.h"


using namespace Masmorra::Entidades::Personagens;


Curandeira::Curandeira(int id, sf::Vector2f tamanho, sf::Vector2f posicao, sf::Vector2f velocidade, int vida, float pulo) :
	Jogador(id, tamanho, posicao, velocidade, vida, pulo),
	olhandoDireita(true),
	tempoCura(),
	recargaCura(30.0f),
	curaPronta(true),
	curaAliado(false),
	pCavaleiro(),
	tempoAcumulado()
{
	texturaCurandeira = new sf::Texture();
	texturaCurandeira->loadFromFile("texturas e fonte/healer_Sprite.png");
	corpo.setTexture(texturaCurandeira);
	pGA->pegarAnimacao(texturaCurandeira, sf::Vector2u(3, 4));
}

Curandeira::~Curandeira()
{
	pCavaleiro = nullptr;
	delete texturaCurandeira;
	texturaCurandeira = nullptr;
}

void Curandeira::setCavaleiro(Cavaleiro* pCa)
{
	if (pCa)
	{
		pCavaleiro = pCa;
	}
	pCavaleiro->setCurandeira(this);
}

void Curandeira::executar()
{
	velAtual.x = 0.0f;

	/*Movimento da curandeira*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		velAtual.x -= velocidade.x;
		olhandoDireita = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		velAtual.x += velocidade.x;
		olhandoDireita = true;
	}

	/*Pulo da curandeira*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (naSuperficie))
	{
		velAtual.y = -sqrtf(2.0f * gravidade * pulo);

		if (naSuperficie) // Em cima da plataforma
		{
			naSuperficie = false;
		}
	}

	mover();

	verificarInvulnerabilidade();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && curaPronta)
	{
		curaPronta = false;
		curar();
		tempoCura.restart();
	}

	else if (tempoCura.getElapsedTime().asSeconds() + tempoAcumulado >= recargaCura)
	{
		curaPronta = true;
		tempoAcumulado = 0.0f; // Zeramos o tempo acumulado
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		if (!curaAliado)
		{
			curarAliado();
			curaAliado = true;
		}
	}
	else
	{
		curaAliado = false;
	}

	if (vida <= 0)
	{
		setVivo(false);
	}

	/*Atualizar animacao*/
	corpo.setTextureRect(pGA->getFrameAtual());
	pGA->atualizar(2, olhandoDireita);

	salvarDataBuffer();
}

void Curandeira::curar() // Curar a si mesma
{
	vida += 5;
}

void Curandeira::curarAliado()
{
	if (pCavaleiro)
	{
		/*só consegue curar se estiverm proximos*/
		if (fabs(pCavaleiro->getCorpo().getPosition().x - corpo.getPosition().x) < 100.0f
			&& fabs(pCavaleiro->getCorpo().getPosition().y - corpo.getPosition().y) < 100.0f)
		{
			vida -= 5; // Fornece sua propria energia vital
			pCavaleiro->setVida(pCavaleiro->getVida() + 5);
		}
	}
}

void Curandeira::setTempoAcumulado(float t)
{
	tempoAcumulado = t;
}

void Curandeira::salvarDataBuffer()
{
	buffer.str("");
	buffer.clear();
	buffer << "Curandeira" << ' ' << getPosicaoX() << ' ' << getPosicaoY() << ' ' << getVelocidadeX() << ' ' << 0
		<< ' ' << vida << ' ' << tempoCura.getElapsedTime().asSeconds() << '\n';
	/*posicao, velocidade, vida, tempo acumulado*/
	/*resto sao fixos*/
}
