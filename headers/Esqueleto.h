#pragma once
#include "Inimigo.h"
#include "GerenciadorAnimacao.h"


namespace Masmorra
{
	namespace Entidades
	{
		namespace Personagens
		{
			class Esqueleto : public Inimigo
			{
			private:
				int batida;
				sf::Texture* texturaEsqueleto;

			public:
				Esqueleto(
					int id,
					sf::Vector2f tamanho,
					sf::Vector2f posicao,
					sf::Vector2f velocidade,
					int vida,
					int nivelMaldade,
					float alcance
				);

				~Esqueleto();
				void executar();
				void danificar(Jogador* pJ);
				void bater(Jogador* pJ) const;
				void salvarDataBuffer();
			};
		}
	}
}
