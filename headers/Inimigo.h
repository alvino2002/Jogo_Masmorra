#pragma once
#include "Personagem.h"
#include "Cavaleiro.h"
#include "Curandeira.h"


namespace Masmorra
{
	namespace Entidades
	{
		namespace Personagens
		{
			class Inimigo : public Personagem
			{
			protected:
				static Cavaleiro* pCavaleiro;
				static Curandeira* pCurandeira;
				float alcance;
				int nivelDeMaldade;

			public:
				Inimigo(
					int id,
					sf::Vector2f tamanho,
					sf::Vector2f posicao,
					sf::Vector2f velocidade,
					int vida,
					int nivelDeMal,
					float alcance = 0.0f // Mago nao tem alcance
				);
				~Inimigo();
				static void setCavaleiro(Cavaleiro* pCa);
				static void setCurandeira(Curandeira* pCu);
				Jogador* getMaisProximo();
				virtual void executar() = 0;
				void mover();
				void andarDir();
				void andarEsq();
				virtual void danificar(Jogador* pJ) = 0;
				virtual void salvarDataBuffer() = 0;
			};
		}
	}
}