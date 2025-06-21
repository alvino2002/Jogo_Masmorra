#pragma once
#include "Interface.h"
#include "GerenciadorGrafico.h"


namespace Masmorra
{
	namespace Interfaces
	{
		class Menu : public Interface
		{
		private:
			std::vector<std::string> opcoes;
			std::vector<sf::Vector2f> coordenadas;
			std::vector<std::size_t> tamanhos;

		public:
			Menu(int id);
			~Menu();
			void inicializar();
			void executar();
		};
	}
}