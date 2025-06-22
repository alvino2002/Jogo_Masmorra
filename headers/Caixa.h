#pragma once
#include "Obstaculo.h"
#include "Jogador.h"
#include "GerenciadorColisao.h"


namespace Masmorra
{
	namespace Entidades
	{
		namespace Obstaculos
		{
			class Caixa : public Obstaculo
			{
			private:
				float lentidao;
				sf::Texture* texturaCaixa;

			public:
				Caixa(
					int id,
					sf::Vector2f tam,
					sf::Vector2f posicao
				);
				~Caixa();
				void executar();
				void obstacularizar(Entidade* pE);
				void salvarDataBuffer();
			};
		}
	}
}
