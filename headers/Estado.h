#pragma once
#include "GerenciadorTempo.h"

/* Classe voltada ao padrao de projeto State */
/* As classes derivadas seguem o mesmo padrao */
/* Em conjunto com a classe Observador, é formada um relação entre sujeito e observador*/

namespace Masmorra
{
	namespace Estados
	{
		class Estado
		{
		protected:
			Gerenciadores::GerenciadorTempo* pGT;

		public:
			Estado();
			virtual ~Estado();
			virtual void executar() = 0;
			virtual void verificarEvento() = 0;
		};
	}
}