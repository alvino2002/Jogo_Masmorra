#pragma once
#include "Ente.h"
#include <sstream>
#include "GerenciadorAnimacao.h"


namespace Masmorra
{
	namespace Entidades
	{
		class Entidade : public Ente
		{
		protected:
			sf::RectangleShape corpo;
			float gravidade;
			sf::Vector2f velocidade;
			bool naSuperficie;
			bool ativo;
			std::ostringstream buffer;

		public:
			/*Valor default para velocidade ja que nem todos as entidades terao velocidade*/
			Entidade(int id, const sf::Vector2f tam, sf::Vector2f posicao, sf::Vector2f vel = sf::Vector2f(0.0f, 0.0f));
			virtual ~Entidade();
			virtual void executar() = 0;
			sf::RectangleShape& getCorpo();
			sf::Vector2f getTamanho()const;
			void aplicarGravidade(float deltaTime);
			float getVelocidadeX()const;
			float getVelocidadeY()const;
			void setVelocidadeX(float vX);
			void setVelocidadeY(float vY);;
			void setNaSuperficie(bool superficie);
			void setPosicao(sf::Vector2f pos);
			void setAtivo(bool at);
			bool getAtivo()const;
			float getPosicaoX()const;
			float getPosicaoY()const;
			virtual void salvarDataBuffer() = 0;
			std::string getBuffer();
		};
	}
}