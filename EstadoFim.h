#pragma once
#include "Estado.h"
#include "Fim.h"
#include "ObservadorFim.h"


namespace Masmorra
{
	namespace Estados
	{
		class EstadoFim : public Estado
		{
		private:
			Masmorra::Interfaces::Fim* pFim;
			Observadores::ObservadorFim* pObs;

		public:
			EstadoFim();
			~EstadoFim();
			void executar();
			void verificarEvento();
		};
	}
}