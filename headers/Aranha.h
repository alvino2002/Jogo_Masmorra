#pragma once
#include "Inimigo.h"


namespace Masmorra
{
	namespace Entidades
	{
		namespace Personagens
		{
			class Aranha : public Inimigo
			{
			private:
				int mordida;
				int veneno;
				sf::Texture* texturaAranha;

			public:
				Aranha(
					int id,
					sf::Vector2f tamanho,
					sf::Vector2f posicao,
					sf::Vector2f velocidade,
					int vida,
					int nivelMaldade,
					float alcance
				);
				~Aranha();
				void executar();
				void morder(Jogador* pJ) const;
				void aplicarVeneno() const;
				void danificar(Jogador* pJ);
				void salvarDataBuffer();
			};
		}
	}
}
