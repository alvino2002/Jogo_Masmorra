#include "../headers/RecintoDosMagos.h"
#include "../headers/Ranking.h"
#include <fstream>


using namespace Masmorra::Fases;


RecintoDosMagos::RecintoDosMagos(int id, int qtdeJogadores, bool novoJogo) :
	Fase(id, qtdeJogadores, novoJogo),
	pontuacaoFinal(),
	venceu(false),
	numeroChefoes()
{
	srand(time(NULL));

	if (novoJogo)
	{
		pCav->setPosicao(sf::Vector2f(1300.f, 120.f)); // Reposicionando
		pCur->setPosicao(sf::Vector2f(1300.f, 120.f));

		Entidades::Personagens::Cavaleiro::setInimigosEliminados(0);

		camera.setSize(sf::Vector2f(800.f, 600.f));
		criarCenario();
		criarInimigos();
		criarObstaculos();

		numeroInimigos = numeroAranhas + numeroChefoes;
	}

	else
	{
		carregarFase();
	}
}

RecintoDosMagos::~RecintoDosMagos()
{
}

void RecintoDosMagos::criarInimigos()
{
	criarAranhas();
	criarMagos();
}

void RecintoDosMagos::criarCenario()
{
	criarPlataformas();
}

void RecintoDosMagos::criarObstaculos()
{
	criarLavas();
}


void RecintoDosMagos::setVenceu(bool v)
{
	venceu = v;
}

bool RecintoDosMagos::getVenceu()const
{
	return venceu;
}

void RecintoDosMagos::criarAranhas()
{
	numeroAranhas = rand() % 3 + 3; // 3 a 5

	/*Aranha 1*/
	Entidades::Personagens::Aranha* pA1 = new Entidades::Personagens::Aranha
	(
		1,
		sf::Vector2f(50.f, 70.f),
		sf::Vector2f(1250.f, 280.f),
		sf::Vector2f(50.f, 0.f),
		10, 2,
		300.f
	);
	pGC->incluirInimigo(pA1);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pA1));

	/*Aranha 2*/
	Entidades::Personagens::Aranha* pA2 = new Entidades::Personagens::Aranha
	(
		1,
		sf::Vector2f(50.f, 70.f),
		sf::Vector2f(1420.f, 500.f),
		sf::Vector2f(50.f, 0.f),
		10, 2,
		300.f
	);
	pGC->incluirInimigo(pA2);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pA2));

	/*Aranha 3*/
	Entidades::Personagens::Aranha* pA3 = new Entidades::Personagens::Aranha
	(
		1,
		sf::Vector2f(50.f, 70.f),
		sf::Vector2f(1260.f, 950.f),
		sf::Vector2f(50.f, 0.f),
		10, 1,
		400.f
	);
	pGC->incluirInimigo(pA3);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pA3));

	if (numeroAranhas > 3)
	{
		/*Aranha 4*/
		Entidades::Personagens::Aranha* pA4 = new Entidades::Personagens::Aranha
		(
			1,
			sf::Vector2f(50.f, 70.f),
			sf::Vector2f(850.f, 450.f),
			sf::Vector2f(50.f, 0.f),
			10, 2,
			450.f
		);
		pGC->incluirInimigo(pA4);
		listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pA4));

		if (numeroAranhas > 4)
		{
			/*Aranha 5*/
			Entidades::Personagens::Aranha* pA5 = new Entidades::Personagens::Aranha
			(
				1,
				sf::Vector2f(50.f, 70.f),
				sf::Vector2f(970.f, 1100.f),
				sf::Vector2f(50.f, 0.f),
				10, 2,
				350.f
			);
			pGC->incluirInimigo(pA5);
			listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pA5));
		}
	}
}

void RecintoDosMagos::criarPlataformas()
{
	int numeroPlataformas = rand() % 3 + 28; // 28 a 30

	//P01
	Entidades::Obstaculos::Plataforma* pP1 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(500.f, 1500.f),
		sf::Vector2f(0.f, 0.f),
		false
	);
	pGC->incluirObstaculo(pP1);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP1));

	//P02
	Entidades::Obstaculos::Plataforma* pP2 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(500.f, 400.f),
		sf::Vector2f(500.f, 500.f),
		false
	);
	pGC->incluirObstaculo(pP2);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP2));

	//P03
	Entidades::Obstaculos::Plataforma* pP3 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(500.f, 1500.f),
		sf::Vector2f(1650.f, 0.f),
		false
	);
	pGC->incluirObstaculo(pP3);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP3));

	//P04
	Entidades::Obstaculos::Plataforma* pP4 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(250.f, 20.f),
		sf::Vector2f(1200.f, 250.f),
		false
	);
	pGC->incluirObstaculo(pP4);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP4));

	//P05
	Entidades::Obstaculos::Plataforma* pP5 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(650.f, 20.f),
		sf::Vector2f(1000.f, 330.f),
		false
	);
	pGC->incluirObstaculo(pP5);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP5));

	//P06
	Entidades::Obstaculos::Plataforma* pP6 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(250.f, 20.f),
		sf::Vector2f(710.f, 370.f),
		false
	);
	pGC->incluirObstaculo(pP6);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP6));

	//P07
	Entidades::Obstaculos::Plataforma* pP7 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(200.f, 20.f),
		sf::Vector2f(1050.f, 550.f),
		false
	);
	pGC->incluirObstaculo(pP7);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP7));

	//P08
	Entidades::Obstaculos::Plataforma* pP8 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(200.f, 20.f),
		sf::Vector2f(1350.f, 550.f),
		false
	);
	pGC->incluirObstaculo(pP8);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP8));

	//P09
	Entidades::Obstaculos::Plataforma* pP9 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(500.f, 50.f),
		sf::Vector2f(1050.f, 570.f),
		false
	);
	pGC->incluirObstaculo(pP9);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP9));

	//P10
	Entidades::Obstaculos::Plataforma* pP10 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(20.f, 280.f),
		sf::Vector2f(1050.f, 620.f),
		false
	);
	pGC->incluirObstaculo(pP10);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP10));

	//P11
	Entidades::Obstaculos::Plataforma* pP11 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(50.f, 20.f),
		sf::Vector2f(1000.f, 880.f),
		false
	);
	pGC->incluirObstaculo(pP11);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP11));

	//P12
	Entidades::Obstaculos::Plataforma* pP12 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(50.f, 20.f),
		sf::Vector2f(1550.f, 580.f),
		false
	);
	pGC->incluirObstaculo(pP12);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP12));

	//P13
	Entidades::Obstaculos::Plataforma* pP13 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(50.f, 20.f),
		sf::Vector2f(1600.f, 680.f),
		false
	);
	pGC->incluirObstaculo(pP13);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP13));

	//P14
	Entidades::Obstaculos::Plataforma* pP14 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(50.f, 20.f),
		sf::Vector2f(1520.f, 730.f),
		false
	);
	pGC->incluirObstaculo(pP14);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP14));

	//P15
	Entidades::Obstaculos::Plataforma* pP15 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(50.f, 20.f),
		sf::Vector2f(1440.f, 780.f),
		false
	);
	pGC->incluirObstaculo(pP15);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP15));

	//P16
	Entidades::Obstaculos::Plataforma* pP16 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(50.f, 20.f),
		sf::Vector2f(1300.f, 780.f),
	    false
	);
	pGC->incluirObstaculo(pP16);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP16));

	//P17
	Entidades::Obstaculos::Plataforma* pP17 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(500.f, 20.f),
		sf::Vector2f(1150.f, 880.f),
		false
	);
	pGC->incluirObstaculo(pP17);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP17));

	//P18
	Entidades::Obstaculos::Plataforma* pP18 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(900.f, 20.f),
		sf::Vector2f(500.f, 1000.f),
		false
	);
	pGC->incluirObstaculo(pP18);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP18));

	//P19
	Entidades::Obstaculos::Plataforma* pP19 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(50.f, 20.f),
		sf::Vector2f(1450.f, 1090.f),
	    false
	);
	pGC->incluirObstaculo(pP19);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP19));

	//P20
	Entidades::Obstaculos::Plataforma* pP20 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(500.f, 20.f),
		sf::Vector2f(900.f, 1150.f),
		false
	);
	pGC->incluirObstaculo(pP20);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP20));

	//P21
	Entidades::Obstaculos::Plataforma* pP21 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(80.f, 20.f),
		sf::Vector2f(500.f, 1150.f),
		false
	);
	pGC->incluirObstaculo(pP21);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP21));

	//P22
	Entidades::Obstaculos::Plataforma* pP22 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(20.f, 200.f),
		sf::Vector2f(1400.f, 1150.f),
	    false
	);
	pGC->incluirObstaculo(pP22);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP22));

	//P23
	Entidades::Obstaculos::Plataforma* pP23 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(100.f, 20.f),
		sf::Vector2f(620.f, 1200.f),
	    false
	);
	pGC->incluirObstaculo(pP23);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP23));

	//P24
	Entidades::Obstaculos::Plataforma* pP24 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(50.f, 20.f),
		sf::Vector2f(780.f, 1230.f),
		false
	);
	pGC->incluirObstaculo(pP24);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP24));

	//P25
	Entidades::Obstaculos::Plataforma* pP25 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(100.f, 20.f),
		sf::Vector2f(850.f, 1330.f),
		false
	);
	pGC->incluirObstaculo(pP25);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP25));

	//P26
	Entidades::Obstaculos::Plataforma* pP26 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(100.f, 20.f),
		sf::Vector2f(1000.f, 1330.f),
		false
	);
	pGC->incluirObstaculo(pP26);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP26));

	//P27
	Entidades::Obstaculos::Plataforma* pP27 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(100.f, 20.f),
		sf::Vector2f(1150.f, 1330.f),
		false
	);
	pGC->incluirObstaculo(pP27);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP27));

	//P28
	Entidades::Obstaculos::Plataforma* pP28 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(100.f, 20.f),
		sf::Vector2f(1300.f, 1330.f),
		false
	);
	pGC->incluirObstaculo(pP28);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP28));

	/*PLATAFORMAS VARIAVEIS*/

	if (numeroPlataformas > 28)
	{
		//P29
		Entidades::Obstaculos::Plataforma* pP29 = new Entidades::Obstaculos::Plataforma(
			1,
			sf::Vector2f(150.f, 20.f),
			sf::Vector2f(500.f, 410.f),
			false
		);
		pGC->incluirObstaculo(pP29);
		listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP29));
	}

	if (numeroPlataformas > 29)
	{
		//P30
		Entidades::Obstaculos::Plataforma* pP30 = new Entidades::Obstaculos::Plataforma(
			1,
			sf::Vector2f(50.f, 20.f),
			sf::Vector2f(1160.f, 780.f),
			false
		);
		pGC->incluirObstaculo(pP30);
		listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP30));
	}
}

void RecintoDosMagos::criarMagos()
{
	numeroChefoes = rand() % 2 + 3; // 3 a 4

	//MAGO 01
	Entidades::Personagens::Mago* pM1 = new Entidades::Personagens::Mago
	(
		1,
		sf::Vector2f(40.f, 70.f),
		sf::Vector2f(500.f, 900.f),
		sf::Vector2f(50.f, 0.f),
		10, 1
	);
	pGC->incluirInimigo(pM1);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pM1));

	//MAGO 02
	Entidades::Personagens::Mago* pM2 = new Entidades::Personagens::Mago
	(
		1,
		sf::Vector2f(40.f, 70.f),
		sf::Vector2f(500.f, 1050.f),
		sf::Vector2f(50.f, 0.f),
		10, 1
	);
	pGC->incluirInimigo(pM2);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pM2));


	//MAGO 03
	Entidades::Personagens::Mago* pM3 = new Entidades::Personagens::Mago
	(
		1,
		sf::Vector2f(40.f, 70.f),
		sf::Vector2f(1330.f, 1230.f),
		sf::Vector2f(50.f, 0.f),
		10, 2
	);
	pGC->incluirInimigo(pM3);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pM3));

	if (numeroChefoes > 3)
	{
		//MAGO 04
		Entidades::Personagens::Mago* pM4 = new Entidades::Personagens::Mago
		(
			1,
			sf::Vector2f(40.f, 70.f),
			sf::Vector2f(1560.f, 900.f),
			sf::Vector2f(50.f, 0.f),
			10,1
		);
		pGC->incluirInimigo(pM4);
		listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pM4));
	}
}

void RecintoDosMagos::criarLavas()
{
	int numeroLavas = rand() % 3 + 3; // 3 a 5
	
	/*Lava 1*/
	Entidades::Obstaculos::Lava* pL1 = new Entidades::Obstaculos::Lava(
		1,
		sf::Vector2f(50.f, 20.f),
		sf::Vector2f(1000.f, 860.f)
	);
	pGC->incluirObstaculo(pL1);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pL1));

	/*Lava 2*/
	Entidades::Obstaculos::Lava* pL2 = new Entidades::Obstaculos::Lava(
		1,
		sf::Vector2f(100.f, 20.f),
		sf::Vector2f(1250.f, 550.f)
	);
	pGC->incluirObstaculo(pL2);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pL2));

	/*Lava 3*/
	Entidades::Obstaculos::Lava* pL3 = new Entidades::Obstaculos::Lava(
		1,
		sf::Vector2f(500.f, 20.f),
		sf::Vector2f(1150.f, 860.f)
	);
	pGC->incluirObstaculo(pL3);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pL3));

	//LAVAS VARIAVEIS
	if (numeroLavas > 3)
	{
		/*Lav 4*/
		Entidades::Obstaculos::Lava* pL4 = new Entidades::Obstaculos::Lava(
			1,
			sf::Vector2f(200.f, 20.f),
			sf::Vector2f(500.f, 480.f)
		);
		pGC->incluirObstaculo(pL4);
		listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pL4));
	}

	if (numeroLavas > 4)
	{
		/*Lava 5*/
		Entidades::Obstaculos::Lava* pL5 = new Entidades::Obstaculos::Lava(
			1,
			sf::Vector2f(200.f, 20.f),
			sf::Vector2f(1450.f, 310.f)
		);
		pGC->incluirObstaculo(pL5);
		listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pL5));
	}
}

void RecintoDosMagos::executar()
{
	/*Jogador principal morreu*/
	if (pCav->getVida() <= 0 || pCav->getPosicaoY() > 1600)
	{
		setFimDaFase(true);
	}

	else if (Entidades::Personagens::Cavaleiro::getInimigosEliminados() == numeroInimigos)
	{
		/*Venceu*/
		setVenceu(true);
	}

	setarCamera();

	pGG->limparJanela();
	pGT->reiniciar();
	pGC->executar();

	for (int i = listaEntidades.getTam() - 1; i >= 0; i--)
	{
		Entidades::Entidade* pE = listaEntidades.getEntidade(i);
		if (pE->getAtivo() == true)
		{
			pE->executar();
			pE->desenhar();
		}
	}
	for ( int i = 0; i < pGC->getListaProjeteis().getTam(); i++)
	{
		Entidades::Entidade* pF = pGC->getListaProjeteis().getEntidade(i);
		if (pF->getAtivo() == true)
		{
			pF->executar();
			pF->desenhar();
		}
	}
	pGG->mostrarEntes();
}

int RecintoDosMagos::getPontuacao()
{
	return Entidades::Personagens::Jogador::getPontuacao();
}


void RecintoDosMagos::escreverNome()
{
	std::string nomeJogador;
	sf::Font fonte;
	sf::Text textoNome;
	sf::Text instrucoes;

	fonte.loadFromFile("Korcy.otf");

	textoNome.setFont(fonte);
	textoNome.setCharacterSize(32);
	textoNome.setFillColor(sf::Color::White);
	textoNome.setPosition(100.f, 100.f);
	textoNome.setString("Nome: ");

	instrucoes.setFont(fonte);
	instrucoes.setCharacterSize(20);
	instrucoes.setFillColor(sf::Color::White);
	instrucoes.setPosition(100.f, 200.f);
	instrucoes.setString("Pressione enter para salvar");

	sf::Event event{};
	bool nomeConfirmado = false;

	sf::RenderWindow* janela = pGG->getJanela();
	janela->setView(janela->getDefaultView());

	while (janela->isOpen() && !nomeConfirmado)
	{
		while (janela->pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				sf::Keyboard::Key tecla = event.key.code;

				if (tecla == sf::Keyboard::Enter)
				{
					nomeConfirmado = true;
					Masmorra::Interfaces::Ranking::salvar(getPontuacao(), nomeJogador);
				}
				else if (tecla == sf::Keyboard::Backspace && !nomeJogador.empty())
				{
					nomeJogador.pop_back();
				}
				else if (tecla >= sf::Keyboard::A && tecla <= sf::Keyboard::Z && nomeJogador.size() < 12)
				{
					nomeJogador += static_cast<char>('A' + (tecla - sf::Keyboard::A)); // Sempre maiúscula
				}
				else if (tecla == sf::Keyboard::Space && nomeJogador.size() < 12)
				{
					nomeJogador += ' ';
				}

				textoNome.setString("Nome: " + nomeJogador);
			}
		}

		sf::RenderWindow* janela = pGG->getJanela();

		pGG->limparJanela();
		janela->draw(instrucoes);
		janela->draw(textoNome);
		pGG->mostrarEntes();
	}
}

void RecintoDosMagos::salvarFase()
{
	std::ofstream arquivo("fase.txt");
	arquivo << "Fase2" << '\n';

	for (int i = listaEntidades.getTam() - 1; i >= 0; i--)
	{
		Entidades::Entidade* pE = listaEntidades.getEntidade(i);

		if (pE->getAtivo() == true)
		{
			arquivo << pE->getBuffer();
		}
	}
	arquivo.close();
}

void RecintoDosMagos::carregarFase()
{
	numeroInimigos = 0;

	std::ifstream arquivo("fase.txt");

	std::string linha;

	std::getline(arquivo, linha); // Descarta a primeira linha ja que ela representa apenas o numero da fase

	while (std::getline(arquivo, linha)) // Lendo linha por linha
	{
		pGT->reiniciar();

		std::istringstream linhaAtual(linha);
		std::string tipo;
		linhaAtual >> tipo;

		if (tipo == "Cavaleiro")
		{
			sf::Vector2f posicao;
			sf::Vector2f velocidade;
			int vida;
			int energia;
			int pontuacao;

			linhaAtual >> posicao.x >> posicao.y >> velocidade.x >> velocidade.y >> vida >> energia >> pontuacao; // Pegando as info

			pCav = new Entidades::Personagens::Cavaleiro(1,
				sf::Vector2f(50.f, 70.f),
				posicao, velocidade,
				vida, 110.0f, energia);

			pCav->setPontuacao(pontuacao);

			listaEntidades.incluirEntidade(pCav);
			pGC->incluirJogador(pCav);

			Entidades::Obstaculos::Obstaculo::setCavaleiro(pCav);
			Entidades::Personagens::Inimigo::setCavaleiro(pCav);
		}


		if (tipo == "Curandeira")
		{
			sf::Vector2f posicao;
			sf::Vector2f velocidade;
			int vida;
			float tempoAcumulado;

			linhaAtual >> posicao.x >> posicao.y >> velocidade.x >> velocidade.y >> vida >> tempoAcumulado; // Pegando as info

			pCur = new Entidades::Personagens::Curandeira(1,
				sf::Vector2f(50.f, 70.f),
				posicao, velocidade,
				vida, 110.0f);

			pCur->setTempoAcumulado(tempoAcumulado);

			listaEntidades.incluirEntidade(pCur);
			pGC->incluirJogador(pCur);

			Entidades::Obstaculos::Obstaculo::setCurandeira(pCur);
			Entidades::Personagens::Inimigo::setCurandeira(pCur);
		}

		if (tipo == "Mago")
		{
			sf::Vector2f posicao;
			sf::Vector2f velocidade;
			int vida;
			int nivelMaldade;
			float tempoAcumulado;

			linhaAtual >> posicao.x >> posicao.y >> velocidade.x >> velocidade.y >> vida >> nivelMaldade >> tempoAcumulado; // Pegando as info

			Entidades::Personagens::Mago* pM =
				new Entidades::Personagens::Mago(1, sf::Vector2f(40.f, 70.f), posicao, velocidade, vida, nivelMaldade);

			pM->setTempoAcumulado(tempoAcumulado);
			listaEntidades.incluirEntidade(pM);
			pGC->incluirInimigo(pM);

			numeroInimigos++;
		}

		if (tipo == "Aranha")
		{
			sf::Vector2f posicao;
			sf::Vector2f velocidade;
			int nivelMaldade;
			int vida;
			float alcance;

			linhaAtual >> posicao.x >> posicao.y >> velocidade.x >> velocidade.y >> vida >> nivelMaldade >> alcance; // Pegando as info

			Entidades::Personagens::Aranha* pAr =
				new Entidades::Personagens::Aranha(1, sf::Vector2f(50.f, 70.f), posicao, velocidade, vida, nivelMaldade,
					alcance);

			listaEntidades.incluirEntidade(pAr);
			pGC->incluirInimigo(pAr);

			numeroInimigos++;
		}

		if (tipo == "Lava")
		{
			sf::Vector2f tamanho;
			sf::Vector2f posicao;

			linhaAtual >> posicao.x >> posicao.y >> tamanho.x >> tamanho.y; // Pegando as info

			Entidades::Obstaculos::Lava* pL = new Entidades::Obstaculos::Lava(1, tamanho,
				posicao);

			pL->setVelocidadeX(0);
			pL->setVelocidadeY(0);

			pGC->incluirObstaculo(pL);
			listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pL));
		}

		if (tipo == "Plataforma")
		{
			sf::Vector2f posicao;
			sf::Vector2f tamanho;
			bool armadilha;

			linhaAtual >> posicao.x >> posicao.y >> tamanho.x >> tamanho.y >> armadilha; // Pegando as info

			Entidades::Obstaculos::Plataforma* pP = new Entidades::Obstaculos::Plataforma(1, tamanho,
				posicao, armadilha);

			pP->setVelocidadeX(0);
			pP->setVelocidadeY(0);

			pGC->incluirObstaculo(pP);
			listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP));
		}
	}
}