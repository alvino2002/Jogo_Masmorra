#include "MasmorraJogo.h"
//OLA ALVINO ESSE EH O TESTE

int main()
{
	Masmorra::MasmorraJogo jogo;
	jogo.rodarJogo();

	Masmorra::Gerenciadores::GerenciadorColisao::deletar();
	Masmorra::Gerenciadores::GerenciadorEstado::deletar();
	Masmorra::Gerenciadores::GerenciadorGrafico::deletar();
	Masmorra::Gerenciadores::GerenciadorTempo::deletar();
}