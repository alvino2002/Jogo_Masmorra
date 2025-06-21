#include "../headers/SelecaoPrimeira.h"


using namespace Masmorra::Interfaces;


SelecaoPrimeira::SelecaoPrimeira(int id) :
	Interface(id)
{
	inicializar();
}

SelecaoPrimeira::~SelecaoPrimeira()
{
}

void SelecaoPrimeira::inicializar()
{
	/*Carregar fonte e textura*/
	fonte->loadFromFile("texturas e fonte/Korcy.otf");
	imagem->loadFromFile("texturas e fonte/selecao_Sprite.jpg");

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
	opcoes.push_back("Seleção");
	opcoes.push_back("1P (1)");
	opcoes.push_back("2P (2)");
	opcoes.push_back("Voltar (V)");

	textos.resize(4);

	coordenadas =
	{
		{310.f, 50.f},    // Título
		{350.f, 215.f},   // Botão 1
		{350.f, 295.f},   // Botão 2
		{320.f, 373.f}    // Botão 3
	};
	tamanhos = { 60, 36, 36, 36 };

	for (std::size_t i = 0; i < textos.size(); i++)
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


void SelecaoPrimeira::executar()
{
	pGT->reiniciar();
	desenhar();
	pGG->mostrarEntes();
}