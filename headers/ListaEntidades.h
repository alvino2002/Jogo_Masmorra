#pragma once
#include "Lista.h"
#include "Entidade.h"

namespace Masmorra
{
	namespace Listas
	{
		class ListaEntidades
		{
		private:
			Lista<Entidades::Entidade> listaDeEntidades;

		public:
			ListaEntidades();
			~ListaEntidades();
			void incluirEntidade(Entidades::Entidade* pEntidade);
			Entidades::Entidade* getEntidade(int pos);
			int getTam();
			void limparLista();
			void removerNos();
		};
	}
}