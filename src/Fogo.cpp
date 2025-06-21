#include "../headers/Fogo.h"


using namespace Masmorra::Entidades;


Fogo::Fogo(int id, sf::Vector2f tam, sf::Vector2f posicao, sf::Vector2f vel, bool direita) :
	Entidade(id, tam, posicao, vel),
	dano(3),
	sentido(direita)
{
	texturaFogo = new sf::Texture();
	texturaFogo->loadFromFile("fireball_Sprite.png");
	corpo.setTexture(texturaFogo);
	pGA->pegarAnimacao(texturaFogo, sf::Vector2u(1, 1));
}

Fogo::~Fogo()
{
	delete texturaFogo;
	texturaFogo = nullptr;
}

void Fogo::executar()
{
	salvarDataBuffer();

	float deltaTime = pGT->getDeltaTempo();
	corpo.move(velocidade * deltaTime);
	aplicarGravidade(deltaTime * 0.005f);

	pGA->atualizar(0, sentido);
	corpo.setTextureRect(pGA->getFrameAtual());
}


void Fogo::atingir(Personagens::Jogador* pJ)
{
	if (pJ->getInvulneravel() == false)
	{
		pJ->sofrerDano(dano);
		pJ->invulnerabilizar();
	}
	setAtivo(false); // Na colisao, é automaticamente excluido
}

void Fogo::setSentido(bool sent)
{
	sentido = sent;
}

void Fogo::salvarDataBuffer()
{
	buffer.str("");
	buffer.clear();
	buffer << "Fogo" << ' ' << getPosicaoX() << ' ' << getPosicaoY() << ' ' << getVelocidadeX() << ' ' << 0
		<< sentido << '\n';
	/*posicao, velocidade, sentido*/
	/*resto sao fixos*/
}