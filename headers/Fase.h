#pragma once
#include "Ente.h"
#include "Cavaleiro.h"
#include "Curandeira.h"
#include "ListaEntidades.h"
#include "GerenciadorGrafico.h"


namespace Masmorra
{
	namespace Fases
	{
		class Fase : public Ente
		{
		protected:
			Entidades::Personagens::Cavaleiro* pCav;
			Entidades::Personagens::Curandeira* pCur;
			Listas::ListaEntidades listaEntidades;
			sf::View camera;
			int numeroInimigos;
			int numeroAranhas;
			bool fimDaFase;
			int quantidadeJogadores;
			sf::RenderWindow* janela;

		public:
			Fase(int id, int qtdeJogadores, bool novoJogo);
			~Fase();

		protected:
			virtual void criarCenario() = 0;
			virtual void criarInimigos() = 0;
			virtual void criarObstaculos() = 0;
			virtual void criarAranhas() = 0; // Ambas as fases vao ter Aranhas, inimigo em comum
			virtual void criarPlataformas() = 0; // Ambas as fases vao ter plataformas

		public:
			virtual void executar() = 0;
			void setFimDaFase(bool fim); // Fase acaba quando todos os inimigos forem derrotados
			bool getFimDaFase()const;
			int getQtdeJogadores()const;
			void setarCamera();
			virtual void salvarFase() = 0;
			virtual void carregarFase() = 0;
		};
	}
}