#include "structs.hpp"
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	recuperarCatPregResp(unaListaCat);

	ListaCategoria* unaListaCat = new ListaCategoria();
	iniciarCategoriasPreguntasRespuestas(unaListaCat);
	ListaParticipantes* participantes =  ingresarParticipantes();

	FILE* archivoContenido = fopen("contenido.dat", "rb");

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

	
// ====== LOGICA DE TURNOS Y RONDAS DURANTE EL JUEGO =======

	ListaRondas* rondasIniciales = generarRondas(5,participantesEnJuego);
	NodoRonda* rondaAuxiliar = rondasIniciales->primerElemento;

	while(rondaAuxiliar->siguienteElemento != NULL){
		NodoTurno* turnoAuxiliar = rondaAuxiliar->turnos->primerElemento;
		while(turnoAuxiliar->siguienteElemento != NULL){
			Respuesta respuestaJugador = new Respuesta();
			cout << turnoAuxiliar->unaPregunta->descripcion << endl;
			for (int i = 0; i < 4; ++i)
			{
				cout << turnoAuxiliar->respuestas[i]<<endl;
			}
			cout << Elija su respuesta << endl;
			cin >> respuestaJugador;

			if (respuestaJugador->correcta == 1)
			{
				turnoAuxiliar->participante->puntos = puntos + 1;
			}

			turnoAuxiliar = turnoAuxiliar->siguienteElemento;
		}

		rondaAuxiliar = rondaAuxiliar->siguienteElemento;
	}
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
