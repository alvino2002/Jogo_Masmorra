#pragma once
#include <stack>
#include "Estado.h"

/* Esta classe, em conjunto com a classe Estado, definem o estado atual do jogo */

namespace Masmorra
{
	namespace Gerenciadores
	{
		class GerenciadorEstado
		{
		private:
			std::stack <Estados::Estado*> pilhaEstados;
			static GerenciadorEstado* pGerenciadorEstado;
			GerenciadorEstado();

		public:
			~GerenciadorEstado();
			static GerenciadorEstado* getGerenciadorEstado();
			void executar();
			void adicionarEstado(Estados::Estado* estado);
			void removerTopo();
			void limparPilha();
			Estados::Estado* getEstado(int i);
			static void deletar();
		};
	}
}