#pragma once
#include "Ente.h"


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