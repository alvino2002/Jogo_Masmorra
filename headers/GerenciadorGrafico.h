#pragma once
#include <SFML/Graphics.hpp>
#include "Ente.h"
#include "Entidade.h"
#include "Interface.h"

/* Referencia utilizada: Ex-Monitor de Tecnicas De Programacao Giovane Limas Salvi */
/* Canal: https://www.youtube.com/@gege171/featured */

namespace Masmorra
{
	namespace Gerenciadores
	{
		class GerenciadorGrafico
		{
		private:
			sf::RenderWindow* janela;
			static GerenciadorGrafico* pGerenciadorGrafico;
			GerenciadorGrafico();

		public:
			~GerenciadorGrafico();
			sf::RenderWindow* getJanela();
			static GerenciadorGrafico* getGerenciadorGrafico();
			void limparJanela();
			void fecharJanela();
			void desenharEntes(Ente* pE);
			void mostrarEntes();
			const bool verificaJanelaAberta();
			static void deletar();
		};
	}
}