#include "../headers/Estado.h"
#include "../headers/GerenciadorEstado.h"


using namespace Masmorra::Estados;


Estado::Estado()
{
	pGT = Gerenciadores::GerenciadorTempo::getGerenciadorTempo();
}

Estado::~Estado()
{
	pGT = nullptr;
}