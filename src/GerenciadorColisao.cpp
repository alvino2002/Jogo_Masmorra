#include "../headers/GerenciadorColisao.h"
#include "../headers/Fogo.h"


using namespace Masmorra::Gerenciadores;


GerenciadorColisao::GerenciadorColisao() :
	lista_jogadores(),
	lista_ini(),
	lista_obst(),
	delta_x(),
	delta_y(),
	interseccao_x(),
	interseccao_y()
{
	pGT = GerenciadorTempo::getGerenciadorTempo();
}

GerenciadorColisao::~GerenciadorColisao()
{
}

GerenciadorColisao* GerenciadorColisao::getGerenciadorColisao()
{
	if (pGerenciadorColisao == nullptr)
	{
		pGerenciadorColisao = new GerenciadorColisao();
	}
	else
	{
		return pGerenciadorColisao;
	}
}

void GerenciadorColisao::executar()
{
	colisaoJogadorInimigo();
	colisaoObstaculosEntidades();
	colisaoJogadorProjetil();
}

bool GerenciadorColisao::verificarColisao(Entidades::Entidade* e1, Entidades::Entidade* e2) //colisao do tipo AABB
{
	sf::Vector2f e1_Posicao = e1->getCorpo().getPosition();
	sf::Vector2f e2_Posicao = e2->getCorpo().getPosition();
	sf::Vector2f e1_Tamanho = e1->getCorpo().getSize();
	sf::Vector2f e1_MetadeTam(e1_Tamanho.x / 2.0f, e1_Tamanho.y / 2.0f);
	sf::Vector2f e2_Tamanho = e2->getCorpo().getSize();
	sf::Vector2f e2_MetadeTam(e2_Tamanho.x / 2.0f, e2_Tamanho.y / 2.0f);

	delta_x = fabs((e1_Posicao.x + e1_MetadeTam.x) - (e2_Posicao.x + e2_MetadeTam.x));
	delta_y = fabs((e1_Posicao.y + e1_MetadeTam.y) - (e2_Posicao.y + e2_MetadeTam.y));
	interseccao_x = (delta_x) - (e2_MetadeTam.x + e1_MetadeTam.x);
	interseccao_y = (delta_y) - (e2_MetadeTam.y + e1_MetadeTam.y);

	if (interseccao_x < 0.0f && interseccao_y < 0.0f) // Houve colisao
	{
		return true;
	}

	return false;
}

void GerenciadorColisao::incluirProjetil(Entidades::Entidade* pF)
{
	if (pF)
	{
		lista_projeteis.incluirEntidade(static_cast<Entidades::Entidade*>(pF));
	}
}

void GerenciadorColisao::incluirJogador(Entidades::Personagens::Jogador* pJ)
{
	if (pJ)
	{
		lista_jogadores.incluirEntidade(static_cast<Entidades::Entidade*>(pJ));
	}
}

void GerenciadorColisao::incluirInimigo(Entidades::Personagens::Inimigo* pI)
{
	if (pI)
	{
		lista_ini.incluirEntidade(static_cast<Entidades::Entidade*> (pI));
	}
}

void GerenciadorColisao::incluirObstaculo(Entidades::Obstaculos::Obstaculo* pO)
{
	if (pO)
	{
		lista_obst.incluirEntidade(static_cast<Entidades::Entidade*> (pO));
	}
}

float GerenciadorColisao::getDeltaX()const
{
	return delta_x;
}

float GerenciadorColisao::getDeltaY()const
{
	return delta_y;
}

float GerenciadorColisao::getInterseccaoX()const
{
	return interseccao_x;
}

float GerenciadorColisao::getInterseccaoY()const
{
	return interseccao_y;
}

Masmorra::Listas::ListaEntidades& GerenciadorColisao::getListaProjeteis()
{
	return lista_projeteis;
}

void GerenciadorColisao::zerarListas()
{
	lista_obst.removerNos();
	lista_ini.removerNos();
	lista_jogadores.removerNos();
	lista_projeteis.removerNos();
}

void GerenciadorColisao::colisaoJogadorInimigo()
{
	for (int i = 0; i < lista_ini.getTam(); i++)
	{
		Entidades::Personagens::Inimigo* ini = static_cast<Entidades::Personagens::Inimigo*>(lista_ini.getEntidade(i));
		for (int j = 0; j < lista_jogadores.getTam(); j++)
		{
			Entidades::Personagens::Jogador* jog = static_cast<Entidades::Personagens::Jogador*>(lista_jogadores.getEntidade(j));
			if (verificarColisao(ini, jog) && jog->getAtivo() && ini->getAtivo())
			{
				ini->danificar(jog);
			}
		}
	}
}

void GerenciadorColisao::colisaoJogadorProjetil()
{
	for (int i = 0; i < lista_projeteis.getTam(); i++)
	{
		Entidades::Entidade* fog = static_cast<Entidades::Entidade*>(lista_projeteis.getEntidade(i));
		for (int j = 0; j < lista_jogadores.getTam(); j++)
		{
			Entidades::Personagens::Jogador* jog = static_cast<Entidades::Personagens::Jogador*>(lista_jogadores.getEntidade(j));
			if (verificarColisao(fog, jog) && jog->getAtivo() && fog->getAtivo())
			{
				Entidades::Fogo* fogo = static_cast<Entidades::Fogo*>(fog);
				fogo->atingir(jog);
			}
		}
	}
}

void GerenciadorColisao::colisaoObstaculosEntidades()
{
	for (int i = 0; i < lista_ini.getTam(); i++) // Inimigos
	{
		Entidades::Personagens::Inimigo* ini = static_cast<Entidades::Personagens::Inimigo*>(lista_ini.getEntidade(i));
		bool colidiu = false;

		for (int j = 0; j < lista_obst.getTam(); j++)
		{
			Entidades::Obstaculos::Obstaculo* obst = static_cast<Entidades::Obstaculos::Obstaculo*>(lista_obst.getEntidade(j));
			if (verificarColisao(ini, obst) && ini->getAtivo())
			{
				obst->obstacularizar(ini);
				colidiu = true;
			}
		}

		if (!colidiu)
		{
			ini->setNaSuperficie(false);
		}
	}


	for (int j = 0; j < lista_jogadores.getTam(); j++) // Jogadores
	{
		Entidades::Personagens::Jogador* jog = static_cast<Entidades::Personagens::Jogador*>(lista_jogadores.getEntidade(j));
		bool colidiu = false;

		for (int i = 0; i < lista_obst.getTam(); i++)
		{
			Entidades::Obstaculos::Obstaculo* obst = static_cast<Entidades::Obstaculos::Obstaculo*>(lista_obst.getEntidade(i));
			if (verificarColisao(jog, obst) && jog->getAtivo())
			{
				obst->obstacularizar(jog);
				colidiu = true;
			}
		}
		if (!colidiu)
		{
			jog->setNaSuperficie(false);
		}
	}

	for (int i = 0; i < lista_obst.getTam(); i++) // Obstaculos
	{
		Entidades::Obstaculos::Obstaculo* obst1 = static_cast<Entidades::Obstaculos::Obstaculo*>(lista_obst.getEntidade(i));
		bool colidiu = false;

		for (int j = 0; j < lista_obst.getTam(); j++) // Verificar colisao com todos os outros obstaculos 
		{
			if (i == j)
			{
				continue; // Nao verificar colisao consigo mesmo
			}
			Entidades::Obstaculos::Obstaculo* obst2 = static_cast<Entidades::Obstaculos::Obstaculo*>(lista_obst.getEntidade(j));

			if (verificarColisao(obst1, obst2))
			{
				obst1->obstacularizar(obst2);
				colidiu = true;
			}
			if (!colidiu)
			{
				obst2->setNaSuperficie(false);
			}
		}
	}
}

void GerenciadorColisao::deletar()
{
	if (pGerenciadorColisao)
	{
		delete pGerenciadorColisao;
		pGerenciadorColisao = nullptr;
	}
}

GerenciadorColisao* GerenciadorColisao::pGerenciadorColisao = nullptr;