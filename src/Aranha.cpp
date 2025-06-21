#include "../headers/Aranha.h"


using namespace Masmorra::Entidades::Personagens;


Aranha::Aranha(
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
		mordida = 2;
		veneno = 1;
	}

	else // nivelDeMaldade == 2
	{
		mordida = 3;
		veneno = 2;
	}
	
	texturaAranha = new sf::Texture();
	texturaAranha->loadFromFile("spider_Sprite.png");
	corpo.setTexture(texturaAranha);
	pGA->pegarAnimacao(texturaAranha, sf::Vector2u(3, 4));
	
	///corpo.setFillColor(sf::Color::Magenta);
}

Aranha::~Aranha()
{
	delete texturaAranha;
	texturaAranha = nullptr;
}

void Aranha::executar()
{
	if (!naSuperficie)
	{
		float deltaTime = pGT->getDeltaTempo();
		aplicarGravidade(deltaTime);
	}

	mover(); // Persegue o jogador

	pGA->atualizar(2, olhandoDireita);

	corpo.setTextureRect(pGA->getFrameAtual());

	if (vida <= 0) // Aranha eliminada
	{
		setVivo(false);
		Jogador::derrotarAranha();
		pCavaleiro->operator++();
	}

	salvarDataBuffer();
}

void Aranha::morder(Jogador* pJ) const
{
	if (pJ->getInvulneravel() == false)
	{
		pJ->sofrerDano(mordida);

		pJ->invulnerabilizar();
	}
}

void Aranha::aplicarVeneno() const
{
	pCavaleiro->sofrerDano(veneno);
}

void Aranha::danificar(Jogador* pJ) // Ocorreu a colisao com o jogador
{
	Cavaleiro* cavaleiro = dynamic_cast<Cavaleiro*>(pJ); // Retorna null se o cast nao der certo

	if (cavaleiro && cavaleiro->getEstaAtacando()) // Cavaleiro atacando??
	{
		vida -= cavaleiro->getDano();
		aplicarVeneno(); // Ao tomar dano, aplica veneno ao atacante, no caso ao cavaleiro
		cavaleiro->setEstaAtacando(false);
	}

	else
	{
		morder(pJ);
	}
}

void Aranha::salvarDataBuffer()
{
	buffer.str("");
	buffer.clear();
	buffer << "Aranha" << ' ' << getPosicaoX() << ' ' << getPosicaoY() << ' ' << getVelocidadeX() << ' ' <<
		0 << ' ' << vida << ' ' << nivelDeMaldade << ' ' << alcance << '\n';
	/*zeramos a velocidade em y para evitar um acumulo grande, comprometendo o jogo na hora de recuperar*/
	/*posicao, velocidade, vida, nivelMaldade, alcance */
	/*resto sao fixos*/
}
