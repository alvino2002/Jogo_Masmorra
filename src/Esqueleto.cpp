#include "../headers/Esqueleto.h"


using namespace Masmorra::Entidades::Personagens;


Esqueleto::Esqueleto(
	int id,
	sf::Vector2f tamanho,
	sf::Vector2f posicao,
	sf::Vector2f velocidade,
	int vida,
	int nivelMaldade,
	float alcance
) :
	Inimigo(id, tamanho, posicao, velocidade, vida, nivelMaldade, alcance)
{
	if (nivelDeMaldade == 1)
	{
		batida = 1;
	}

	else
	{
		batida = 2;
	}
	texturaEsqueleto = new sf::Texture();
	texturaEsqueleto->loadFromFile("texturas e fonte/skull.sprite.png");
	corpo.setTexture(texturaEsqueleto);
	pGA->pegarAnimacao(texturaEsqueleto, sf::Vector2u(3, 4));
}

Esqueleto::~Esqueleto()
{
	delete texturaEsqueleto;
	texturaEsqueleto = nullptr;
}

void Esqueleto::executar()
{
	if (!naSuperficie)
	{
		float deltaTime = pGT->getDeltaTempo();
		aplicarGravidade(deltaTime);
	}

	mover();

	pGA->atualizar(1, olhandoDireita);
	corpo.setTextureRect(pGA->getFrameAtual());

	if (vida <= 0) // Esqueleto eliminado
	{
		setVivo(false);
		Jogador::derrotarEsqueleto();
		pCavaleiro->operator++();
	}

	salvarDataBuffer();

}

void Esqueleto::bater(Jogador* pJ) const
{
	if (pJ->getInvulneravel() == false) // Jogador nao esta invuneravel, pode receber dano;
	{
		pJ->sofrerDano(batida);


		pJ->invulnerabilizar();
	}
}

void Esqueleto::danificar(Jogador* pJ)
{
	Entidades::Personagens::Cavaleiro* cavaleiro = dynamic_cast<Entidades::Personagens::Cavaleiro*>(pJ);

	if (cavaleiro && cavaleiro->getEstaAtacando()) // Cavaleiro atacando??
	{
		vida -= cavaleiro->getDano();
		cavaleiro->setEstaAtacando(false);
	}
	else
	{
		bater(pJ);
	}
}

void Esqueleto::salvarDataBuffer()
{
	buffer.str("");
	buffer.clear();
	buffer << "Esqueleto" << ' ' << getPosicaoX() << ' ' << getPosicaoY() << ' ' << getVelocidadeX() << ' ' << 0 << ' ' <<
		vida << ' ' << nivelDeMaldade << ' ' << alcance << '\n';
	/*posicao, velocidade, vida, nivelMaldade */
	/*resto sao fixos*/
}