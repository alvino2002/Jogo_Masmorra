#pragma once
#include "Fase.h"
#include "time.h"
#include "Aranha.h"
#include "Cavaleiro.h"
#include "Curandeira.h"
#include "Esqueleto.h"
#include "GerenciadorColisao.h"
#include "Caixa.h"


namespace Masmorra
{
	namespace Fases
	{
		class ZonaDosEsqueletos : public Fase
		{
		private:
			bool avance;
			int numeroEsqueletos;

		public:
			ZonaDosEsqueletos(
				int id,
				int qtdeJogadores,
				bool novoJogo
			);

			~ZonaDosEsqueletos();
			void criarCenario();
			void criarPlataformas();
			void criarInimigos();
			void criarObstaculos();
			void criarCaixas();  // Obstaculo exclusivo da fase
			void criarAranhas();
			void criarEsqueletos(); // Inimigo exclusivo da fase
			void executar();
			void salvarFase();
			void carregarFase();
			void setAvance(bool avancar);
			bool getAvance()const;
		};
	}
}