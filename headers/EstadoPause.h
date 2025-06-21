#pragma once
#include "Estado.h"
#include "Pause.h"
#include "ObservadorPause.h"


namespace Masmorra
{
	namespace Estados
	{
		class EstadoPause : public Estado
		{
		private:
			Masmorra::Interfaces::Pause* pPause;
			Observadores::ObservadorPause* pObs;

		public:
			EstadoPause();
			~EstadoPause();
			void executar();
			void verificarEvento();
		};
	}
}