#pragma once
#include "SFML/Graphics.hpp"


namespace Masmorra
{
	namespace Gerenciadores
	{
		class GerenciadorGrafico;
		class GerenciadorColisao;
		class GerenciadorTempo;
		class GerenciadorAnimacao;
	}
}

namespace Masmorra
{
	class Ente
	{
	protected:

		/*Utilizamos static pois sao ponteiros globais, compartilhado para todos*/
		static Gerenciadores::GerenciadorGrafico* pGG;
		static Gerenciadores::GerenciadorColisao* pGC;
		static Gerenciadores::GerenciadorTempo* pGT;

	protected:
		Gerenciadores::GerenciadorAnimacao* pGA; // Equivalente à pFig no modelo proposto

	protected:
		int id; // Entes fisicos receberao id = 1 e entes nao fisicos receberao id = 2

	public:
		Ente(int i);
		virtual ~Ente();
		int getId()const;
		void desenhar();
	};
}