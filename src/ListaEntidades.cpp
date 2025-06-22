#include "../headers/ListaEntidades.h"



using namespace Masmorra::Listas;


ListaEntidades::ListaEntidades() :
	listaDeEntidades()
{
}

ListaEntidades::~ListaEntidades()
{
}

void ListaEntidades::incluirEntidade(Entidades::Entidade* pEntidade)
{
	if (pEntidade)
	{
		listaDeEntidades.push(pEntidade);
	}
}

Masmorra::Entidades::Entidade* ListaEntidades::getEntidade(int pos)
{
	return listaDeEntidades.getpInfo(pos);
}

int ListaEntidades::getTam()
{
	return listaDeEntidades.getTam();
}


void ListaEntidades::limparLista()
{
	listaDeEntidades.clear();
}

void ListaEntidades::removerNos()
{
	listaDeEntidades.removerNos();
}