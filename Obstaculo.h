#pragma once
#include "Entidade.h"
#include "Cavaleiro.h"
#include "Curandeira.h"


namespace Masmorra
{
	namespace Entidades
	{
		namespace Obstaculos
		{
			class Obstaculo : public Entidade
			{
			protected:
				static Personagens::Cavaleiro* pCavaleiro;
				static Personagens::Curandeira* pCurandeira;

			public:
				Obstaculo(
					int id,
					sf::Vector2f tam,
					sf::Vector2f posicao
				);
				~Obstaculo();
				static void setCavaleiro(Personagens::Cavaleiro* pCa);
				static void setCurandeira(Personagens::Curandeira* pCu);
				virtual void executar() = 0;
				virtual void obstacularizar(Entidade* pE) = 0;
				virtual void salvarDataBuffer() = 0;
			};
		}
	}
}