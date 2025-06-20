#include "Mago.h"

/*Oi*/

using namespace Masmorra::Entidades::Personagens;


Mago::Mago(int id,
	sf::Vector2f tamanho,
	sf::Vector2f posicao,
	sf::Vector2f velocidade,
	int vida,
	int nivelDeMaldade
) :
	Inimigo(id, tamanho, posicao, velocidade, vida, nivelDeMaldade),

	tempoLancamento(),
	lancamentoPronto(false),
	chamas(1),
	tempoAcumulado(0.0f),
	listaDeProjeteis()
{
	if (nivelDeMaldade == 1)
	{
		olhandoDireita = true;
		recargaLancamento = 5.0f;
	}
	else
	{
		olhandoDireita = false;
		recargaLancamento = 2.0f;
	}

	texturaMago = new sf::Texture();
	texturaMago->loadFromFile("mago_Sprite.png");
	corpo.setTexture(texturaMago);
	pGA->pegarAnimacao(texturaMago, sf::Vector2u(1, 2));
}

Mago::~Mago()
{
	listaDeProjeteis.limparLista();
	delete texturaMago;
	texturaMago = nullptr;
}

void Mago::executar()
{
	if (!naSuperficie)
	{
		float deltaTime = pGT->getDeltaTempo();
		aplicarGravidade(deltaTime);
	}
	else
	{
		velocidade.y = 0;
	}

	if (nivelDeMaldade == 1)
	{
		pGA->atualizar(1, true);
	}
	else
	{
		pGA->atualizar(1, false); // Mago olhando para esquerda
	}

	if (tempoLancamento.getElapsedTime().asSeconds() + tempoAcumulado >= recargaLancamento)
	{
		lancamentoPronto = true;
		tempoAcumulado = 0.0f;
	}

	if (lancamentoPronto)
	{
		criarFogo();
		tempoLancamento.restart();
		lancamentoPronto = false;
	}

	if (vida <= 0)
	{
		setVivo(false);
		Jogador::derrotarMago();
		pCavaleiro->operator++();
	}

	corpo.setTextureRect(pGA->getFrameAtual());

	salvarDataBuffer();
}

void Mago::criarFogo()
{
	if (nivelDeMaldade == 1) // Olhando para direita, o fogo vai ter sentido para direita
	{
		Fogo* fogo = new Fogo(1, sf::Vector2f(30.0f, 30.0f), corpo.getPosition(),
			sf::Vector2f(100.0f, 0.0f), true);
		pGC->incluirProjetil(fogo);
		fogo->executar();
	}

	else
	{
		Fogo* fogo = new Fogo(1, sf::Vector2f(30.0f, 30.0f), corpo.getPosition(),
			sf::Vector2f(-100.0f, 0.0f), false);
		pGC->incluirProjetil(fogo);
		fogo->executar();
	}
}

void Mago::danificar(Jogador* pJ)
{
	Entidades::Personagens::Cavaleiro* cavaleiro = dynamic_cast<Entidades::Personagens::Cavaleiro*>(pJ);

	if (cavaleiro && cavaleiro->getEstaAtacando()) // Cavaleiro atacando??
	{
		vida -= cavaleiro->getDano();
		cavaleiro->setEstaAtacando(false);
	}
	else
	{
		queimar(pJ);
	}
}

void Mago::queimar(Jogador* pJ) const
{
	if (pJ->getInvulneravel() == false)
	{
		pJ->sofrerDano(chamas);
		pJ->invulnerabilizar();
	}
}

void Mago::setTempoAcumulado(float tempo)
{
	tempoAcumulado = tempo;
}

void Mago::salvarDataBuffer()
{
	buffer.str("");
	buffer.clear();
	buffer << "Mago" << ' ' << getPosicaoX() << ' ' << getPosicaoY() << ' ' << getVelocidadeX() << ' ' << 0 << ' '
		<< vida << ' ' << nivelDeMaldade << ' ' << tempoLancamento.getElapsedTime().asSeconds() << '\n';
	/*posicao, velocidade, vida, nivelMaldade, tempo acumulado*/
	/*resto sao fixos*/
}