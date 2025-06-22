#pragma once
#include "Obstaculo.h"
#include "GerenciadorColisao.h"


namespace Masmorra
{
	namespace Entidades
	{
		namespace Obstaculos
		{
			class Plataforma : public Obstaculo
			{
			private:
				bool armadilha; // Algumas plataformas têm armadilhas, provocando dano ao Jogador quando pisar nela

			public:
				Plataforma(
					int id,
					sf::Vector2f tam,
					sf::Vector2f posicao,
					bool arm);
				~Plataforma();
				void executar();
				void obstacularizar(Entidade* pE);
				void flutuar(float deltaTempo); // Funcao para "anular" a forca gravitacional
				void salvarDataBuffer();
			};

		}
	}
}