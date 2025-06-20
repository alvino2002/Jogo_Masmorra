#pragma once
#include "Estado.h"
#include "ZonaDosEsqueletos.h"
#include "ObservadorPrimeiraFase.h"
#include "SalvarJogada.h"


namespace Masmorra
{
	namespace Estados
	{
		class EstadoPrimeiraFase : public Estado
		{
		private:
			Fases::ZonaDosEsqueletos* pPrimFase;
			Observadores::ObservadorPrimeiraFase* pObs;

		public:
			EstadoPrimeiraFase(int qtdeJogadores, bool novoJogo);
			~EstadoPrimeiraFase();
			void executar();
			void verificarEvento();
		};
	}
}