#pragma once
#include "EstadoPrimeiraFase.h"
#include "EstadoPause.h"
#include "Ente.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEstado.h"


namespace Masmorra
{
	class MasmorraJogo
	{
	private:
		/*Nao necessariamente estatico, mas conforme o modelo Singleton, todos os ponteiros apontarao para o mesmo local*/
		Gerenciadores::GerenciadorEstado* pGEs;
		Gerenciadores::GerenciadorColisao* pGC;
		Gerenciadores::GerenciadorGrafico* pGG;

	public:
		MasmorraJogo();
		~MasmorraJogo();
		void rodarJogo();
	};
}