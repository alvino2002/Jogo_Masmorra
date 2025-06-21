#include "../headers/GerenciadorAnimacao.h"


using namespace Masmorra::Gerenciadores;


GerenciadorAnimacao::GerenciadorAnimacao() :
	numeroImgs(),
	imgAtual(),
	frameAtual(),
	duracaoFrame(0.3f),
	tempoTotal()
{
	pGT = GerenciadorTempo::getGerenciadorTempo();
}

GerenciadorAnimacao::~GerenciadorAnimacao()
{
	pGT = nullptr;
}

void GerenciadorAnimacao::pegarAnimacao(sf::Texture* textura, sf::Vector2u imageCount)
{
	numeroImgs = imageCount;
	tempoTotal = 0.0f;
	imgAtual.x = 0;

	frameAtual.width = textura->getSize().x / float(imageCount.x);
	frameAtual.height = textura->getSize().y / float(imageCount.y);
}

void GerenciadorAnimacao::atualizar(int linha, bool olhandoDireita)
{
	float deltaTime = pGT->getDeltaTempo();

	imgAtual.y = linha;
	tempoTotal += deltaTime;

	if (tempoTotal >= duracaoFrame)
	{
		tempoTotal -= duracaoFrame;
		imgAtual.x++;

		if (imgAtual.x >= numeroImgs.x)
		{
			imgAtual.x = 0;
		}
	}

	frameAtual.top = imgAtual.y * frameAtual.height;

	if (olhandoDireita)
	{
		frameAtual.left = imgAtual.x * frameAtual.width;
		frameAtual.width = abs(frameAtual.width);
	}
	else
	{
		frameAtual.left = (imgAtual.x + 1) * abs(frameAtual.width);
		frameAtual.width = -abs(frameAtual.width);
	}
}

const sf::IntRect& GerenciadorAnimacao::getFrameAtual() const
{
	return frameAtual;
}