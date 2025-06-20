#pragma once
#include "Estado.h"
#include "RecintoDosMagos.h"
#include "ObservadorSegundaFase.h"
#include "SalvarJogada.h"


namespace Masmorra
{
	namespace Estados
	{
		class EstadoSegundaFase : public Estado
		{
		private:
			Fases::RecintoDosMagos* pSegFase;
			Observadores::ObservadorSegundaFase* pObs;

		public:
			EstadoSegundaFase(int qtdeJogadores, bool novoJogo);
			~EstadoSegundaFase();
			void executar();
			void verificarEvento();
		};
	}
}