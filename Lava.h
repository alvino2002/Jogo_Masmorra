#pragma once
#include "Obstaculo.h"
#include "GerenciadorColisao.h"


namespace Masmorra
{
	namespace Entidades
	{
		namespace Obstaculos
		{
			class Lava : public Obstaculo
			{
			private:
				int dano;
				sf::Texture* texturaLava;

			public:
				Lava(
					int id,
					sf::Vector2f tam,
					sf::Vector2f posicao
				);
				~Lava();
				void executar();
				void obstacularizar(Entidade* pE);
				void salvarDataBuffer();
			};
		}
	}
}