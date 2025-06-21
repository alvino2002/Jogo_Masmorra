#include "../headers/Fim.h"


using namespace Masmorra::Interfaces;


Fim::Fim(int id) :
	Interface(id)
{
	janela = pGG->getJanela();
}

Fim::~Fim()
{
	janela = nullptr;
}

void Fim::inicializar()
{
	/*Carregar fonte e textura*/
	fonte->loadFromFile("texturas e fonte/Korcy.otf");
	imagem->loadFromFile("texturas e fonte/fundo_preto.jpg");

	/*Aplicar textura ao fundo*/
	fundo->setTexture(*imagem);

	/*Ajuste da escala*/
	sf::Vector2u tamanho = imagem->getSize();
	float escalaX = 800.0f / tamanho.x;
	float escalaY = 600.0f / tamanho.y;
	fundo->setScale(escalaX, escalaY);
	fundo->setPosition(0.0f, 0.0f);

	/*Inicializar os textos*/
	titulo.setFont(*fonte);
	titulo.setString("FIM DO JOGO");
	titulo.setCharacterSize(60);
	titulo.setFillColor(sf::Color::Red);
	titulo.setOutlineColor(sf::Color::Black);
	titulo.setOutlineThickness(2);
	titulo.setPosition(200.f, 60.f);
	textos.push_back(titulo);

	instrucao.setFont(*fonte);
	instrucao.setString("(Aperte ESC para sair)");
	instrucao.setCharacterSize(20);
	instrucao.setFillColor(sf::Color::White);
	instrucao.setOutlineColor(sf::Color::Black);
	instrucao.setOutlineThickness(2);
	instrucao.setPosition(280.f, 450.f);
	textos.push_back(instrucao);
}

void Fim::executar()
{
	/*Centralizar a camera*/
	janela = pGG->getJanela();
	janela->setView(janela->getDefaultView());

	pGG->limparJanela();
	inicializar();
	desenhar();
	pGG->mostrarEntes();
}
