#include "Estado.h"
#include "GerenciadorEstado.h"


using namespace Masmorra::Estados;


Estado::Estado()
{
	pGT = Gerenciadores::GerenciadorTempo::getGerenciadorTempo();
}

Estado::~Estado()
{
	pGT = nullptr;
}