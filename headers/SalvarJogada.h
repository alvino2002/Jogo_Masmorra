#pragma once
#include "GerenciadorEstado.h"
#include "EstadoPrimeiraFase.h"
#include "EstadoSegundaFase.h"

/* A utilização e construção de buffers nessa classe e em outros locais foi auxiliada pela IA ChatGPT*/

namespace Masmorra
{
	class SalvarJogada
	{
	private:
		static Fases::ZonaDosEsqueletos* pPrimeira;
		static Fases::RecintoDosMagos* pSegunda;
		Gerenciadores::GerenciadorEstado* pGEs;

	public:
		SalvarJogada();
		~SalvarJogada();
		static void setPrimeiraFase(Fases::ZonaDosEsqueletos* pP);
		static void setSegundaFase(Fases::RecintoDosMagos* pS);
		void salvarFase(int fase);
		void executar();
	};
}