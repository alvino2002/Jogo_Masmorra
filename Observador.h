#pragma once
#include <string>
#include "GerenciadorEstado.h"


namespace Masmorra
{
	namespace Observadores
	{
		class Observador
		{
		protected:
			static Gerenciadores::GerenciadorEstado* pGEs;

		public:
			Observador();
			~Observador();
			virtual void notificarEvento(const std::string& evento) = 0;
		};
	}
}