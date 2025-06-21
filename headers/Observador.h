#pragma once
#include <string>
#include "GerenciadorEstado.h"

/* Classe voltada ao padrão de projeto Observer, baseada em um sistema de notificações */

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