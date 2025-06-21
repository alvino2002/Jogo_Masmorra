#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorTempo.h"

namespace Masmorra
{
	namespace Gerenciadores
	{
		class GerenciadorAnimacao
		{
		private:
			sf::Vector2u numeroImgs;
			sf::Vector2u imgAtual;
			sf::IntRect frameAtual;
			float duracaoFrame;
			float tempoTotal;
			GerenciadorTempo* pGT;

		public:
			GerenciadorAnimacao();
			~GerenciadorAnimacao();
			void pegarAnimacao(sf::Texture* textura, sf::Vector2u qtdeImgs);
			void atualizar(int linha, bool olhandoDireita);
			const sf::IntRect& getFrameAtual() const;
		};
	}
}