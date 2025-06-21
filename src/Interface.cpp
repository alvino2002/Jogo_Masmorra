#include "../headers/Interface.h"


using namespace Masmorra::Interfaces;


Interface::Interface(int id) :
	Ente(id)
{
	fonte = new sf::Font();
	fundo = new sf::Sprite();
	imagem = new sf::Texture();
}

Interface::~Interface()
{
	if (fonte)
	{
		delete fonte;
	}

	if (fundo)
	{
		delete fundo;
	}

	if (imagem)
	{
		delete imagem;
	}
}

const std::vector<sf::Text>& Interface::getTextos()
{
	return textos;
}

const sf::Sprite& Interface::getFundo()
{
	return *fundo;
}