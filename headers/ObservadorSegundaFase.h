#pragma once
#include "Observador.h"
#include "RecintoDosMagos.h"


namespace Masmorra
{
	namespace Estados
	{
		class EstadoMenu;
		class EstadoFim;
		class EstadoPause;
	}
}

namespace Masmorra
{
	namespace Observadores
	{
		class ObservadorSegundaFase : public Observador
		{
		private:
			Fases::RecintoDosMagos* pSeg;
			Estados::EstadoFim* pFim;
			Estados::EstadoMenu* pMenu;
			Estados::EstadoPause* pPause;

		public:
			ObservadorSegundaFase();
			~ObservadorSegundaFase();
			void setSegundaFase(Fases::RecintoDosMagos* pSF);
			void notificarEvento(const std::string& evento);
		};
	}
}