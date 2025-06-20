#pragma once
#include "Interface.h"


namespace Masmorra
{
	namespace Interfaces
	{
		class SelecaoSegunda : public Interface
		{
		private:
			std::vector<std::string> opcoes;
			std::vector<sf::Vector2f> coordenadas;
			std::vector<std::size_t> tamanhos;


		public:
			SelecaoSegunda(int id);
			~SelecaoSegunda();
			void inicializar();
			void executar();
		};
	}
}