#pragma once
#include "GerenciadorGrafico.h"
#include "Interface.h"

namespace Masmorra
{
	namespace Interfaces
	{
		class Pause : public Interface
		{
		private:
			std::vector<std::string> opcoes;
			std::vector<sf::Vector2f> coordenadas;
			std::vector<std::size_t> tamanhos;

		public:
			Pause(int id);
			~Pause();
			void executar();
			void inicializar();
		};
	}
}