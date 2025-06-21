#include "../headers/Pause.h"


using namespace Masmorra::Interfaces;


Pause::Pause(int id) :
	Interface(id)
{
	inicializar();
}

Pause::~Pause()
{
	delete fonte;
	delete imagem;
	delete fundo;
	fonte = nullptr;
	imagem = nullptr;
	fundo = nullptr;
}


void Pause::inicializar()
{
	/*Carregar fonte e textura*/
	fonte->loadFromFile("texturas e fonte/Korcy.otf");
	imagem->loadFromFile("texturas e fonte/pause_Sprite.jpg");

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
	opcoes.push_back("Pausado");
	opcoes.push_back("Continuar (C)");
	opcoes.push_back("");
	opcoes.push_back("Salvar (ESC)");

	textos.resize(4);

	coordenadas =
	{
		{280.f, 80.f},    // Título
		{275.f, 200.f},   // Botão 1
		{300.f, 250.f},   // Botão 2 INEXISTENTE
		{300.f, 290.f}    // Botão 3
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


void Pause::executar()
{
	/*Centralizar a camera*/
	sf::RenderWindow* janela = pGG->getJanela();
	janela->setView(janela->getDefaultView());

	desenhar();
	pGG->mostrarEntes();
}
