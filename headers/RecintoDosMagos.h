#pragma once
#include "Fase.h"
#include "time.h"
#include "Aranha.h"
#include "Lava.h"
#include "Cavaleiro.h"
#include "Curandeira.h"
#include "Mago.h"

/*Oi*/

namespace Masmorra
{
	namespace Fases
	{
		class RecintoDosMagos : public Fase
		{
		private:
			int numeroChefoes; // Numero de magos
			int pontuacaoFinal;
			bool venceu;
			sf::RenderWindow* janela;

		public:
			RecintoDosMagos(
				int id,
				int qtdeJogadores,
				bool novoJogo
			);

			~RecintoDosMagos();
			void criarCenario();
			void criarPlataformas();
			void criarInimigos();
			void criarObstaculos();
			void criarAranhas();
			void criarMagos();
			void criarLavas();
			void executar();
			int getPontuacao();
			void setVenceu(bool v);
			bool getVenceu()const;
			void escreverNome();
			void salvarFase();
			void carregarFase();
		};
	}
}