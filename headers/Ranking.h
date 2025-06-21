#pragma once
#include "Interface.h"
#include "GerenciadorGrafico.h"
#include <string>


namespace Masmorra
{
    namespace Interfaces
    {
        class Ranking : public Interface
        {
        private:
            std::string nome;
            int pontuacao;
            std::vector<std::pair<std::string, int>> ranking;
            sf::RenderWindow* janela;
            sf::Text titulo;
            sf::Text instrucao;

        public:
            Ranking(int id);
            ~Ranking();
            void executar();
            void inicializar();
            void carregarRanking();
            static void salvar(int pontuacao, const std::string& nome);
        };
    }
}