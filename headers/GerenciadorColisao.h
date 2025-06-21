#pragma once
#include "Entidade.h"
#include "ListaEntidades.h"
#include "Inimigo.h"
#include "Jogador.h"
#include "GerenciadorTempo.h"
#include "Plataforma.h"

namespace Masmorra
{
	namespace Gerenciadores
	{
		class GerenciadorColisao
		{
		private:
			static GerenciadorColisao* pGerenciadorColisao;
			Listas::ListaEntidades lista_obst;
			Listas::ListaEntidades lista_ini;
			Listas::ListaEntidades lista_jogadores;
			Listas::ListaEntidades lista_projeteis;
			GerenciadorTempo* pGT;
			GerenciadorColisao();
			float delta_x;
			float delta_y;
			float interseccao_x;
			float interseccao_y;

		public:
			~GerenciadorColisao();
			static GerenciadorColisao* getGerenciadorColisao();
			void executar();
			bool verificarColisao(Entidades::Entidade* e1, Entidades::Entidade* e2);
			void incluirProjetil(Entidades::Entidade* pF);
			void incluirJogador(Entidades::Personagens::Jogador* pJ);
			void incluirInimigo(Entidades::Personagens::Inimigo* pI);
			void incluirObstaculo(Entidades::Obstaculos::Obstaculo* pO);
			float getDeltaX()const;
			float getDeltaY()const;
			float getInterseccaoX()const;
			float getInterseccaoY()const;
			Listas::ListaEntidades& getListaProjeteis();
			void zerarListas(); // Metodo para remover todos os nós alocados da lista
			static void deletar();

		private:
			void colisaoJogadorInimigo();
			void colisaoJogadorProjetil();
			void colisaoObstaculosEntidades();
		};
	}
}
