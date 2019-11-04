#include "structs.hpp"
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

	unaCategoria.nombre = "Historia";
	unaPregunta.descripcion = "¿En que anio se desarrollo la guerra de Malvinas?";
	
	fread(&unaPregunta, sizeof(Pregunta), 1, archivoContenido);
	
	
	
	
	return 0;
}
