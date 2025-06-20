#include "ZonaDosEsqueletos.h"
#include <fstream>


using namespace Masmorra::Fases;


ZonaDosEsqueletos::ZonaDosEsqueletos(int id, int qtdeJogadores, bool novoJogo) :
	Fase(id, qtdeJogadores, novoJogo)
{
	srand(time(NULL));

	if (novoJogo)
	{
		camera.setSize(sf::Vector2f(800.f, 600.f));
		criarCenario();
		criarInimigos();
		criarObstaculos();

		numeroInimigos = numeroAranhas + numeroEsqueletos;
	}

	else
	{
		carregarFase();
	}
}

ZonaDosEsqueletos::~ZonaDosEsqueletos()
{
}

void ZonaDosEsqueletos::criarEsqueletos()
{
	numeroEsqueletos = rand() % 3 + 3; // 3 a 5

	//ESQUELETO 01
	Entidades::Personagens::Esqueleto* pE = new Entidades::Personagens::Esqueleto
	(
		1,
		sf::Vector2f(50.f, 70.f),
		sf::Vector2f(1450.f, 670.f),
		sf::Vector2f(50.f, 0.f),
		10, 2,
		500.f
	);
	pGC->incluirInimigo(pE);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pE));

	//ESQUELETO 02
	Entidades::Personagens::Esqueleto* pE2 = new Entidades::Personagens::Esqueleto
	(
		1,
		sf::Vector2f(50.f, 70.f),
		sf::Vector2f(890.f, 190.f),
		sf::Vector2f(50.f, 0.f),
		10, 2,
		100.f
	);
	pGC->incluirInimigo(pE2);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pE2));

	//ESQUELETO 03
	Entidades::Personagens::Esqueleto* pE3 = new Entidades::Personagens::Esqueleto
	(
		1,
		sf::Vector2f(50.f, 70.f),
		sf::Vector2f(500.f, 520.f),
		sf::Vector2f(50.f, 0.f),
		10, 1,
		100.f
	);
	pGC->incluirInimigo(pE3);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pE3));

	if (numeroEsqueletos > 3)
	{
		//ESQUELETO 4
		Entidades::Personagens::Esqueleto* pE4 = new Entidades::Personagens::Esqueleto
		(
			1,
			sf::Vector2f(50.f, 70.f),
			sf::Vector2f(1090.f, 780.f),
			sf::Vector2f(50.f, 0.f),
			10, 1,
			200.f
		);
		pGC->incluirInimigo(pE4);
		listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pE4));
	}

	if (numeroEsqueletos > 4)
	{
		//ESQUELETO 5
		Entidades::Personagens::Esqueleto* pE5 = new Entidades::Personagens::Esqueleto
		(
			1,
			sf::Vector2f(50.f, 70.f),
			sf::Vector2f(130.f, 350.f),
			sf::Vector2f(50.f, 0.f),
			10, 2,
			300.f
		);
		pGC->incluirInimigo(pE5);
		listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pE5));
	}
}

void ZonaDosEsqueletos::criarAranhas()
{
	numeroAranhas = rand() % 3 + 3; // 3 a 5

	//ARANHA 01
	Entidades::Personagens::Aranha* pA = new Entidades::Personagens::Aranha
	(
		1,
		sf::Vector2f(50.f, 70.f),
		sf::Vector2f(1190.f, 690.f),
		sf::Vector2f(50.f, 0.f),
		10, 1,
		300.f
	);
	pGC->incluirInimigo(pA);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pA));

	//ARANHA 02
	Entidades::Personagens::Aranha* pA2 = new Entidades::Personagens::Aranha
	(
		1,
		sf::Vector2f(50.f, 70.f),
		sf::Vector2f(1280.f, 250.f),
		sf::Vector2f(50.f, 0.f),
		10, 1,
		200.f
	);
	pGC->incluirInimigo(pA2);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pA2));

	//ARANHA 03
	Entidades::Personagens::Aranha* pA3 = new Entidades::Personagens::Aranha
	(
		1,
		sf::Vector2f(50.f, 70.f),
		sf::Vector2f(500.f, 690.f),
		sf::Vector2f(50.f, 0.f),
		10, 2,
		350.f
	);
	pGC->incluirInimigo(pA3);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pA3));

	if (numeroAranhas > 3)
	{
		//ARANHA 4
		Entidades::Personagens::Aranha* pA4 = new Entidades::Personagens::Aranha
		(
			1,
			sf::Vector2f(50.f, 70.f),
			sf::Vector2f(900.f, 800.f),
			sf::Vector2f(50.f, 0.f),
			10, 2,
			400.f
		);
		pGC->incluirInimigo(pA4);
		listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pA4));
	}

	if (numeroAranhas > 4)
	{
		//ARANHA 5
		Entidades::Personagens::Aranha* pA5 = new Entidades::Personagens::Aranha
		(
			1,
			sf::Vector2f(50.f, 70.f),
			sf::Vector2f(480.f, 190.f),
			sf::Vector2f(50.f, 0.f),
			10, 2,
			100.f
		);
		pGC->incluirInimigo(pA5);
		listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pA5));
	}
}

void ZonaDosEsqueletos::criarPlataformas()
{
	int numeroPlataformas = rand() % 3;

	//P01
	Entidades::Obstaculos::Plataforma* pP1 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(300.f, 20.f),
		sf::Vector2f(380.f, 250.f),
		false
	);
	pGC->incluirObstaculo(pP1);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP1));

	//P02
	Entidades::Obstaculos::Plataforma* pP2 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(300.f, 20.f),
		sf::Vector2f(790.f, 270.f),
		false
	);
	pGC->incluirObstaculo(pP2);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP2));

	//P03
	Entidades::Obstaculos::Plataforma* pP3 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(300.f, 20.f),
		sf::Vector2f(1160.f, 310.f),
		false
	);
	pGC->incluirObstaculo(pP3);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP3));

	//P04
	Entidades::Obstaculos::Plataforma* pP4 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(300.f, 20.f),
		sf::Vector2f(50.f, 430.f),
		false
	);
	pGC->incluirObstaculo(pP4);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP4));

	//P05
	Entidades::Obstaculos::Plataforma* pP5 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(300.f, 20.f),
		sf::Vector2f(1470.f, 430.f),
		false
	);
	pGC->incluirObstaculo(pP5);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP5));

	//P06
	Entidades::Obstaculos::Plataforma* pP6 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(300.f, 20.f),
		sf::Vector2f(740.f, 500.f),
		false
	);
	pGC->incluirObstaculo(pP6);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP6));

	//P07
	Entidades::Obstaculos::Plataforma* pP7 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(300.f, 20.f),
		sf::Vector2f(400.f, 600.f),
		false
	);
	pGC->incluirObstaculo(pP7);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP7));

	//P08
	Entidades::Obstaculos::Plataforma* pP8 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(400.f, 50.f),
		sf::Vector2f(1140.f, 600.f),
		false
	);
	pGC->incluirObstaculo(pP8);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP8));

	//P09
	Entidades::Obstaculos::Plataforma* pP9 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(20.f, 130.f),
		sf::Vector2f(600.f, 620.f),
		false
	);
	pGC->incluirObstaculo(pP9);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP9));

	//P10
	Entidades::Obstaculos::Plataforma* pP10 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(20.f, 40.f),
		sf::Vector2f(1280.f, 650.f),
		false
	);
	pGC->incluirObstaculo(pP10);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP10));

	//P11
	Entidades::Obstaculos::Plataforma* pP11 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(20.f, 130.f),
		sf::Vector2f(80.f, 750.f),
		false
	);
	pGC->incluirObstaculo(pP11);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP11));

	//P12
	Entidades::Obstaculos::Plataforma* pP12 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(1100.f, 20.f),
		sf::Vector2f(180.f, 750.f),
		false
	);
	pGC->incluirObstaculo(pP12);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP12));

	//P13
	Entidades::Obstaculos::Plataforma* pP13 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(350.f, 20.f),
		sf::Vector2f(1380.f, 750.f),
		false
	);
	pGC->incluirObstaculo(pP13);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP13));

	//P14
	Entidades::Obstaculos::Plataforma* pP14 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(500.f, 20.f),
		sf::Vector2f(100.f, 860.f),
		false
	);
	pGC->incluirObstaculo(pP14);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP14));

	//P15
	Entidades::Obstaculos::Plataforma* pP15 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(600.f, 20.f),
		sf::Vector2f(760.f, 860.f),
		false
	);
	pGC->incluirObstaculo(pP15);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP15));

	//P16
	Entidades::Obstaculos::Plataforma* pP16 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(20.f, 130.f),
		sf::Vector2f(580.f, 880.f),
		false
	);
	pGC->incluirObstaculo(pP16);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP16));

	//P17
	Entidades::Obstaculos::Plataforma* pP17 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(150.f, 20.f),
		sf::Vector2f(580.f, 1010.f),
		false
	);
	pGC->incluirObstaculo(pP17);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP17));

	//P18
	Entidades::Obstaculos::Plataforma* pP18 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(100.f, 20.f),
		sf::Vector2f(750.f, 650.f),
		false
	);
	pGC->incluirObstaculo(pP18);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP18));

	//P19
	Entidades::Obstaculos::Plataforma* pP19 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(100.f, 20.f),
		sf::Vector2f(1620.f, 640.f),
		false
	);
	pGC->incluirObstaculo(pP19);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP19));

	//P20
	Entidades::Obstaculos::Plataforma* pP20 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(100.f, 20.f),
		sf::Vector2f(1560.f, 340.f),
		false
	);
	pGC->incluirObstaculo(pP20);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP20));

	if (numeroPlataformas > 0)
	{
		//P21
		Entidades::Obstaculos::Plataforma* pP20 = new Entidades::Obstaculos::Plataforma(
			1,
			sf::Vector2f(20.f, 100.f),
			sf::Vector2f(1520.f, 650.f),
			false
		);
		pGC->incluirObstaculo(pP19);
		listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP19));
	}
	if (numeroPlataformas > 1)
	{
		//P22
		Entidades::Obstaculos::Plataforma* pP21 = new Entidades::Obstaculos::Plataforma(
			1,
			sf::Vector2f(100.f, 20.f),
			sf::Vector2f(340.f, 490.f),
			false
		);
		pGC->incluirObstaculo(pP19);
		listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP19));
	}
}

void ZonaDosEsqueletos::criarCaixas()
{
	int numeroCaixas = rand() % 3 + 3; // 3 a 5

	//CAIXA 1
	Entidades::Obstaculos::Caixa* pC = new Entidades::Obstaculos::Caixa(1, sf::Vector2f(60.0f, 70.0f),
		sf::Vector2f(280.0f, 780.0f));
	pGC->incluirObstaculo(pC);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pC));

	//CAIXA 2
	Entidades::Obstaculos::Caixa* pC2 = new Entidades::Obstaculos::Caixa(1, sf::Vector2f(60.0f, 70.0f),
		sf::Vector2f(1110.0f, 670.0f));
	pGC->incluirObstaculo(pC2);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pC2));

	//CAIXA 3
	Entidades::Obstaculos::Caixa* pC3 = new Entidades::Obstaculos::Caixa(1, sf::Vector2f(60.0f, 70.0f),
		sf::Vector2f(1190.0f, 520.0f));
	pGC->incluirObstaculo(pC3);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pC3));

	if (numeroCaixas > 3)
	{
		//CAIXA 4
		Entidades::Obstaculos::Caixa* pC4 = new Entidades::Obstaculos::Caixa(1, sf::Vector2f(60.0f, 70.0f),
			sf::Vector2f(230.0f, 350.0f));
		pGC->incluirObstaculo(pC4);
		listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pC4));
	}

	if (numeroCaixas > 4)
	{
		//CAIXA 5
		Entidades::Obstaculos::Caixa* pC5 = new Entidades::Obstaculos::Caixa(1, sf::Vector2f(60.0f, 70.0f),
			sf::Vector2f(1630.0f, 670.0f));
		pGC->incluirObstaculo(pC5);
		listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pC5));
	}
}

void ZonaDosEsqueletos::setAvance(bool avancar)
{
	avance = avancar;
}

bool ZonaDosEsqueletos::getAvance()const
{
	return avance;
}

void ZonaDosEsqueletos::executar()
{
	/*Jogador principal morreu*/
	if (pCav->getVida() == 0)
	{
		setFimDaFase(true);
	}

	/*Jogador pode avancar para proxima fase*/
	else if (Entidades::Personagens::Cavaleiro::getInimigosEliminados() == numeroInimigos)
	{
		setAvance(true);
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
			pE->desenhar();
			pE->executar();
		}
	}

	for (int i = 0; i < pGC->getListaProjeteis().getTam(); i++)
	{
		Entidades::Entidade* pF = pGC->getListaProjeteis().getEntidade(i);
		if (pF->getAtivo())
		{
			pF->executar();
			pF->desenhar();
		}
	}
	pGG->mostrarEntes();
}

void ZonaDosEsqueletos::criarCenario()
{
	criarPlataformas();
}

void ZonaDosEsqueletos::criarObstaculos()
{
	criarCaixas();
}

void ZonaDosEsqueletos::criarInimigos()
{
	//criarAranhas();
	criarEsqueletos();
}

void ZonaDosEsqueletos::salvarFase()
{
	std::ofstream arquivo("fase.txt");
	arquivo << "Fase1" << '\n';

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

void ZonaDosEsqueletos::carregarFase()
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

		if (tipo == "Esqueleto")
		{
			sf::Vector2f posicao;
			sf::Vector2f velocidade;
			int nivelMaldade;
			int vida;
			float alcance;

			linhaAtual >> posicao.x >> posicao.y >> velocidade.x >> velocidade.y >> vida >> nivelMaldade >> alcance; // Pegando as info

			Entidades::Personagens::Esqueleto* pEsq =
				new Entidades::Personagens::Esqueleto(1, sf::Vector2f(50.f, 70.f), posicao, velocidade, vida, nivelMaldade,
					alcance);

			listaEntidades.incluirEntidade(pEsq);
			pGC->incluirInimigo(pEsq);

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

		if (tipo == "Caixa")
		{
			sf::Vector2f posicao;

			linhaAtual >> posicao.x >> posicao.y; // Pegando as info

			Entidades::Obstaculos::Caixa* pC = new Entidades::Obstaculos::Caixa(1, sf::Vector2f(60.0f, 70.0f),
				posicao);

			pC->setVelocidadeX(0);
			pC->setVelocidadeY(0);

			pGC->incluirObstaculo(pC);
			listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pC));
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
