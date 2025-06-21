#pragma once
#include "GerenciadorTempo.h"

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