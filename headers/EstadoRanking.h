#pragma once
#include "Estado.h"
#include "Ranking.h"
#include "ObservadorRanking.h"


namespace Masmorra
{
	namespace Estados
	{
		class EstadoRanking : public Estado
		{
		private:
			Masmorra::Interfaces::Ranking* pR;
			Observadores::ObservadorRanking* pObs;

		public:
			EstadoRanking();
			~EstadoRanking();
			void executar();
			void verificarEvento();
		};
	}
}
