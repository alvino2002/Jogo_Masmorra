#pragma once
#include "Interface.h"
#include "GerenciadorGrafico.h"


namespace Masmorra
{
    namespace Interfaces
    {
        class Fim : public Interface
        {
        private:
            sf::RenderWindow* janela;
            sf::Text titulo;
            sf::Text instrucao;

        public:
            Fim(int id);
            ~Fim();
            void executar();
            void inicializar();
        };
    }
}