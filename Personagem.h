#pragma once
#include "Entidade.h"


namespace Masmorra
{
	namespace Entidades
	{
		namespace Personagens
		{
			class Personagem : public Entidade
			{
			protected:
				int vida;
				bool olhandoDireita;

			public:
				Personagem(
					int id,
					sf::Vector2f tam,
					sf::Vector2f posicao,
					sf::Vector2f velocidade,
					int v
				);
				~Personagem();
				void setVida(int v);
				int getVida()const;
				void setVivo(bool v);
				bool getOlhandoDireita()const;
				virtual void executar() = 0;
				virtual void mover() = 0;
				virtual void salvarDataBuffer() = 0;
			};
		}
	}
}