#include "structs.hpp"
#include "funciones.cpp"
#include <iostream>
using namespace std;

int main()
{

	ListaCategoria* unaListaCat = new ListaCategoria();
	iniciarCategoriasPreguntasRespuestas(unaListaCat);
	ListaParticipantes* participantes =  ingresarParticipantes();
	


	return 0;
}

void iniciarCategoriasPreguntasRespuestas(ListaCategoria* categorias) {
	//Abro archivo
	int index = 1;
	while (index < 100) {
		//CategoriaToRead cat  = fread(sizeof(CategoriaToRead))
		Categoria* unaCategoria = categoriaCreate(cat);
		//
		index++;
	}
}
