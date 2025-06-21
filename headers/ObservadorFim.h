#pragma once
#include "Observador.h"
#include "Fim.h"

namespace Masmorra
{
	namespace Estados
	{
		class EstadoMenu;
	}
}

namespace Masmorra
{
	namespace Observadores
	{
		class ObservadorFim : public Observador
		{
		private:
			Masmorra::Estados::EstadoMenu* pMenu;

		public:
			ObservadorFim();
			~ObservadorFim();
			void notificarEvento(const std::string& evento);
		};
	}
}
