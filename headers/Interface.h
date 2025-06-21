#pragma once
#include "Ente.h"

/* A constru��o dessa classe e de suas derivadas tiveram aux�lio da ferramenta de intelig�ncia artificial ChatGPT */

namespace Masmorra
{
	namespace Interfaces
	{
		class Interface : public Ente
		{
		protected:
			sf::Font* fonte;
			std::vector<sf::Text> textos;
			sf::Sprite* fundo;
			sf::Texture* imagem;

		public:
			Interface(int id);
			~Interface();
			const std::vector<sf::Text>& getTextos();
			const sf::Sprite& getFundo();
			virtual void inicializar() = 0;
			virtual void executar() = 0;
		};
	}
}