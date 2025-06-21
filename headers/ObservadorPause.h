#pragma once
#include "Observador.h"
#include "GerenciadorGrafico.h"



namespace Masmorra
{
	namespace Estados
	{
		class EstadoMenu;
	}
}

namespace Masmorra
{
	class SalvarJogada;
}


namespace Masmorra
{
	namespace Observadores
	{
		class ObservadorPause : public Observador
		{
		private:
			Estados::EstadoMenu* pMenu;
			Masmorra::SalvarJogada* pSalvar;
			Gerenciadores::GerenciadorGrafico* pGG;

		public:
			ObservadorPause();
			~ObservadorPause();
			void notificarEvento(const std::string& evento);
		};
	}
}