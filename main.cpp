#include "structs.hpp"
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	
	//ListaCategoria* unaListaCat = new ListaCategoria();
	
	//recuperarCatPregResp(unaListaCat);
	
	//ListaCategoria* unaListaCat = new ListaCategoria();
	//iniciarCategoriasPreguntasRespuestas(unaListaCat);
	//ListaParticipantes* participantes =  ingresarParticipantes();
	
	FILE* archivoContenido = fopen("contenido.dat", "wb");

	Categoria unaCategoria;
	PreguntaParaArchivo unaPregunta;
	RespuestaParaArchivo unaRespuesta;

	unaCategoria.nombre = "Historia";
	unaCategoria.nombre = "Geografia";
	unaCategoria.nombre = "Arte";
	unaPregunta.descripcion = "¿En que anio se desarrollo la guerra de Malvinas?";
	
	fwrite(&unaCategoria, sizeof(Categoria), 1, archivoContenido);
	
	//fread(&unaPregunta, sizeof(Pregunta), 1, archivoContenido);
	//cout<<unaPregunta.descripcion;

	
	return 0;
}

/* void iniciarCategoriasPreguntasRespuestas(ListaCategoria* categorias){
	//Abro archivo
	int index = 1;
	while (index < 100) {
		//CategoriaToRead cat  = fread(sizeof(CategoriaToRead))
		Categoria* unaCategoria = categoriaCreate(cat);
		//
		index++;
	}
}*/
