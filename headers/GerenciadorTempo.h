#pragma once
#include <SFML/Graphics.hpp>


namespace Masmorra
{
	namespace Gerenciadores
	{
		class GerenciadorTempo
		{
		private:
			static GerenciadorTempo* pGerenciadorTempo; // Modelo Singleton, uma instancia para todo o jogo.
			float deltaTempo;
			sf::Clock relogio;
			GerenciadorTempo();

		public:
			~GerenciadorTempo();
			static GerenciadorTempo* getGerenciadorTempo();
			void reiniciar();
			float getDeltaTempo() const;
			static void deletar();
		};
	}
}