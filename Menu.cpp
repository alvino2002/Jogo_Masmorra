#include "Menu.h"


using namespace Masmorra::Interfaces;


Menu::Menu(int id) :
	Interface(id)
{
	inicializar();
}

Menu::~Menu()
{
}

void Menu::inicializar()
{
	/*Carregar fonte e textura*/
	fonte->loadFromFile("Korcy.otf");
	imagem->loadFromFile("menuInicial_Sprite.png");

	/*Aplicar textura ao fundo*/
	fundo->setTexture(*imagem);

	/*Ajuste da escala*/
	sf::Vector2u tamanho = imagem->getSize();
	float escalaX = 800.0f / tamanho.x;
	float escalaY = 600.0f / tamanho.y;
	fundo->setScale(escalaX, escalaY);
	fundo->setPosition(0.0f, 0.0f);

	/*Inicializar os textos*/
	opcoes.clear();
	opcoes.push_back("Menu");
	opcoes.push_back("Jogo Salvo (J)");
	opcoes.push_back("Primeira Fase (P)");
	opcoes.push_back("Segunda Fase (S)");
	opcoes.push_back("Ranking (R)");

	textos.resize(5);

	coordenadas =
	{
		{305.f, 50.f},    // Título
		{290.f, 217.f},   // Jogo Salvo
		{255.f, 296.f},   // Primeira Fase (P)
		{260.f, 375.f},   // Segunda Fase (S)
		{310.f, 453.f}    // Ranking (R)
	};
	tamanhos = { 60, 36, 36, 36, 36 };

	for (unsigned int i = 0; i < textos.size(); i++)
	{
		textos[i].setFont(*fonte);
		textos[i].setString(opcoes[i]);
		textos[i].setPosition(coordenadas[i]);
		textos[i].setCharacterSize(tamanhos[i]);
		textos[i].setFillColor(sf::Color::Red);
		textos[i].setOutlineColor(sf::Color::Black);
		textos[i].setOutlineThickness(2);
	}
}

void Menu::executar()
{
	desenhar();
	pGG->mostrarEntes();
}