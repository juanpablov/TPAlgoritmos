#include "structs.hpp"
#include "funciones.cpp"
#include <iostream>
using namespace std;

int main()
{
	
	//ListaCategoria* unaListaCat = new ListaCategoria();
	
	//recuperarCatPregResp(unaListaCat);
	
	FILE* archivoContenido = fopen("contenido.dat", "wb");


	Categoria unaCategoria;
	Pregunta unaPregunta;
	Respuesta unaRespuesta;

	ListaCategoria* unaListaCat = new ListaCategoria();
	iniciarCategoriasPreguntasRespuestas(unaListaCat);
	ListaParticipantes* participantes =  ingresarParticipantes();
	

	unaCategoria.nombre = "Historia";
	unaPregunta.descripcion = "�En que anio se desarrollo la guerra de Malvinas?";
	
	fread(&unaPregunta, sizeof(Pregunta), 1, archivoContenido);
	
	
	
	
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
