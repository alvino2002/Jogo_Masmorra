#include "Ranking.h"
#include <fstream>


using namespace Masmorra::Interfaces;


Ranking::Ranking(int id) :
    Interface(id),
    nome(),
    pontuacao(),
    ranking(),
    titulo(),
    instrucao()
{
    janela = pGG->getJanela();
}

void Ranking::salvar(int pontuacao, const std::string& nome)
{
    std::ofstream arquivo("ranking.txt", std::ios::app); // abre no modo append
    if (arquivo.is_open())
    {
        arquivo << nome << " " << pontuacao << std::endl;
        arquivo.close();
    }
}

Ranking::~Ranking()
{

}

void Ranking::inicializar()
{
    /*Carregar fonte e textura*/
    fonte->loadFromFile("Korcy.otf");
    imagem->loadFromFile("fundo_preto.jpg");

    /*Aplicar textura ao fundo*/
    fundo->setTexture(*imagem);

    /*Ajuste da escala*/
    sf::Vector2u tamanho = imagem->getSize();
    float escalaX = 800.0f / tamanho.x;
    float escalaY = 600.0f / tamanho.y;
    fundo->setScale(escalaX, escalaY);
    fundo->setPosition(0.0f, 0.0f);

    carregarRanking();

    titulo.setFont(*fonte);
    titulo.setString("RANKING");
    titulo.setCharacterSize(60);
    titulo.setFillColor(sf::Color::Red);
    titulo.setOutlineColor(sf::Color::Black);
    titulo.setOutlineThickness(2);
    titulo.setPosition(280.f, 40.f);
    textos.push_back(titulo);


    for (size_t i = 0; i < ranking.size() && i < 10; i++)
    {
        sf::Text texto;
        texto.setFont(*fonte);
        texto.setCharacterSize(25);
        texto.setFillColor(sf::Color::White);
        texto.setOutlineColor(sf::Color::Black);
        texto.setOutlineThickness(2);
        texto.setPosition(200.f, 120.f + static_cast<float>(i) * 40.f);
        texto.setString(std::to_string(i + 1) + ". " + ranking[i].first + " - " + std::to_string(ranking[i].second));
        textos.push_back(texto);
    }

    instrucao.setFont(*fonte);
    instrucao.setString("(Aperte V para voltar)");
    instrucao.setCharacterSize(20);
    instrucao.setFillColor(sf::Color::White);
    instrucao.setOutlineColor(sf::Color::Black);
    instrucao.setOutlineThickness(2);
    instrucao.setPosition(280.f, 550.f);
    textos.push_back(instrucao);
}

void Ranking::executar()
{
    pGG->limparJanela();
    inicializar();
    desenhar();
    pGG->mostrarEntes();
}

void Ranking::carregarRanking()
{
    std::ifstream arquivoEntrada("ranking.txt");
    ranking.clear();

    while (arquivoEntrada >> nome >> pontuacao)
    {
        ranking.push_back(std::make_pair(nome, pontuacao));
    }
    arquivoEntrada.close();

    std::sort(ranking.begin(), ranking.end(),
        [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
        {
            return a.second > b.second;
        });
}