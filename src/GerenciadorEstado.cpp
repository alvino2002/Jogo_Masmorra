#include "../headers/GerenciadorEstado.h"


using namespace Masmorra::Gerenciadores;


GerenciadorEstado::GerenciadorEstado()
{
}

GerenciadorEstado* GerenciadorEstado::getGerenciadorEstado()
{
	if (pGerenciadorEstado == nullptr)
	{
		pGerenciadorEstado = new GerenciadorEstado();
	}
	else
	{
		return pGerenciadorEstado;
	}
}

GerenciadorEstado::~GerenciadorEstado()
{
}

void GerenciadorEstado::executar()
{
	if (!pilhaEstados.empty() && pilhaEstados.top() != nullptr)
	{
		pilhaEstados.top()->executar();
		pilhaEstados.top()->verificarEvento();
	}
}

void GerenciadorEstado::adicionarEstado(Estados::Estado* estado)
{
	if (estado)
	{
		pilhaEstados.push(estado);
	}
}

void GerenciadorEstado::removerTopo()
{
	if (!pilhaEstados.empty() && pilhaEstados.top() != nullptr)
	{
		delete (pilhaEstados.top());
		pilhaEstados.pop();
	}
}

void GerenciadorEstado::limparPilha()
{
	while (pilhaEstados.empty() != true)
	{
		if (pilhaEstados.top() != nullptr)
		{
			delete (pilhaEstados.top());
			pilhaEstados.pop();
		}
	}
}

Masmorra::Estados::Estado* GerenciadorEstado::getEstado(int i)
{
	std::stack<Estados::Estado*> auxiliar;

	for (int j = 0; j < i; j++)
	{
		auxiliar.push(pilhaEstados.top());
		pilhaEstados.pop();
	}

	Estados::Estado* pEstado = pilhaEstados.top();

	while (!auxiliar.empty())
	{
		pilhaEstados.push(auxiliar.top());
		auxiliar.pop();
	}

	return pEstado;
}

void GerenciadorEstado::deletar()
{
	if (pGerenciadorEstado)
	{
		delete pGerenciadorEstado;
		pGerenciadorEstado = nullptr;
	}
}

GerenciadorEstado* GerenciadorEstado::pGerenciadorEstado = nullptr;