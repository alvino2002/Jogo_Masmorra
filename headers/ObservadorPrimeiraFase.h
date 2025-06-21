#pragma once
#include "Observador.h"
#include "ZonaDosEsqueletos.h"


namespace Masmorra
{
	namespace Estados
	{
		class EstadoSegundaFase;
		class EstadoPause;
		class EstadoFim;
	}
}

namespace Masmorra
{
	namespace Observadores
	{
		class ObservadorPrimeiraFase : public Observador
		{
		private:
			Fases::ZonaDosEsqueletos* pPrim;
			Estados::EstadoSegundaFase* pSeg;
			Estados::EstadoPause* pPause;
			Estados::EstadoFim* pFim;

		public:
			ObservadorPrimeiraFase();
			~ObservadorPrimeiraFase();
			void notificarEvento(const std::string& evento);
			void setPrimeiraFase(Fases::ZonaDosEsqueletos* pP);
		};
	}
}