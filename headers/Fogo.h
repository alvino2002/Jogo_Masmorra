#pragma once
#include "Entidade.h"
#include "Jogador.h"


namespace Masmorra
{
	namespace Entidades
	{
		class Fogo : public Entidade
		{
		private:
			int dano;
			bool sentido;
			sf::Texture* texturaFogo;

		public:
			Fogo(
				int id,
				const sf::Vector2f tam,
				sf::Vector2f posicao,
				sf::Vector2f vel,
				bool direita
			);
			~Fogo();
			void executar();
			void atingir(Personagens::Jogador* pJ);
			void salvarDataBuffer();
			void setSentido(bool sent);
		};
	}
}