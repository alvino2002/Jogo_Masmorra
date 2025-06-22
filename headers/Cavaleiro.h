#pragma once
#include "Jogador.h"


namespace Masmorra
{
	namespace Entidades
	{
		namespace Personagens
		{
			class Curandeira;
		}
	}
}


namespace Masmorra
{
	namespace Entidades
	{
		namespace Personagens
		{
			class Cavaleiro : public Jogador
			{
			private:
				bool estaAtacando;
				int dano;
				int energia;
				sf::Clock tempoRecuperar; // Temporalizador para a energia
				float duracaoRecuperacao; // Tempo para recuperar energia
				sf::Clock tempoAtaque;  // Temporizador para o ataque
				float recargaAtaque;  // Tempo de espera entre ataques
				bool ataquePronto;
				static int inimigosEliminados; // Apenas cavaleiro consegue eliminar 
				sf::Texture* texturaCavaleiro;
				Curandeira* pCurandeira;

			public:
				Cavaleiro(
					int id,
					sf::Vector2f tamanho,
					sf::Vector2f posicao,
					sf::Vector2f velocidade,
					int vida,
					float pulo,
					int energia
				);

				~Cavaleiro();
				void executar();
				bool getEstaAtacando()const;
				void setEstaAtacando(bool atacando);
				int getDano()const;
				void operator--(); // Decrementar energia
				void recuperar();
				void operator++(); // Incrementar numero de inimigos eliminados
				static int getInimigosEliminados();
				static void setInimigosEliminados(int numeroInimigos);
				void setCurandeira(Curandeira* pCur);
				void enfurecer();
				void salvarDataBuffer();
			};
		}
	}
}