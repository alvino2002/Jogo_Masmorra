#pragma once
#include "Observador.h"
#include "SelecaoSegunda.h"

namespace Masmorra
{
	namespace Estados
	{
		class EstadoSegundaFase;
	}
}

namespace Masmorra
{
	namespace Observadores
	{
		class ObservadorSelecaoSeg : public Observador
		{
		private:
			Estados::EstadoSegundaFase* pSeg;

		public:
			ObservadorSelecaoSeg();
			~ObservadorSelecaoSeg();
			void notificarEvento(const std::string& evento);
		};
	}
}