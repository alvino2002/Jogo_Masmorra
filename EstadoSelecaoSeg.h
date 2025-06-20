#pragma once
#include "Estado.h"
#include "SelecaoSegunda.h"
#include "ObservadorSelecaoSeg.h"

namespace Masmorra
{
	namespace Estados
	{
		class EstadoSelecaoSeg : public Estado
		{
		private:
			Masmorra::Interfaces::SelecaoSegunda* pSelecaoSegunda;
			Observadores::ObservadorSelecaoSeg* pObs;

		public:
			EstadoSelecaoSeg();
			~EstadoSelecaoSeg();
			void executar();
			void verificarEvento();
		};
	}
}