#pragma once
#include "Observador.h"


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
		class ObservadorRanking : public Observador
		{
		private:
			Estados::EstadoMenu* pMenu;

		public:
			ObservadorRanking();
			~ObservadorRanking();
			void notificarEvento(const std::string& evento);
		};
	}
}
