#pragma once
#include "Estado.h"
#include "Menu.h"
#include "ObservadorMenu.h"


namespace Masmorra
{
	namespace Estados
	{
		class EstadoMenu : public Estado
		{
		private:
			Masmorra::Interfaces::Menu* pMenu;
			Observadores::ObservadorMenu* pObs;

		public:
			EstadoMenu();
			~EstadoMenu();
			void executar();
			void verificarEvento();
		};
	}
}