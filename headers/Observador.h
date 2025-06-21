#pragma once
#include <string>
#include "GerenciadorEstado.h"

/* Classe voltada ao padr�o de projeto Observer, baseada em um sistema de notifica��es */

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