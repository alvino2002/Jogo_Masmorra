#pragma once
#include "Observador.h"
#include "Menu.h"
#include "SalvarJogada.h"


namespace Masmorra
{
	namespace Estados
	{
		class EstadoRanking;
		class EstadoSelecaoSeg;
		class EstadoSelecaoPrim;
	}
}

namespace Masmorra
{
	namespace Observadores
	{
		class ObservadorMenu : public Observador
		{
		private:
			Estados::EstadoRanking* pR;
			Estados::EstadoSelecaoPrim* pPrim;
			Estados::EstadoSelecaoSeg* pSeg;

		private:
			SalvarJogada* pSalvar;

		public:
			ObservadorMenu();
			~ObservadorMenu();
			void notificarEvento(const std::string& evento);
		};
	}
}