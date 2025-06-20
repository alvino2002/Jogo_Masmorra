#pragma once
#include "Observador.h"
#include "SelecaoPrimeira.h"

namespace Masmorra
{
	namespace Estados
	{
		class EstadoPrimeiraFase;
	}
}


namespace Masmorra
{
	namespace Observadores
	{
		class ObservadorSelecaoPrim : public Observador
		{
		private:
			Estados::EstadoPrimeiraFase* pPrim;

		public:
			ObservadorSelecaoPrim();
			~ObservadorSelecaoPrim();
			void notificarEvento(const std::string& evento);
		};
	}
}