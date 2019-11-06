#include "structs.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	/*recuperarCatPregResp(unaListaCat);

	ListaCategoria* unaListaCat = new ListaCategoria();
	iniciarCategoriasPreguntasRespuestas(unaListaCat);
	*/

	FILE* archivoContenido = fopen("contenido.dat", "rb");

	Juego* unJuego = new Juego();
	int idCategoriaAnterior, idPreguntaAnterior;
	
	fread(unJuego, sizeof(Juego), 1, archivoContenido);
	
	while(!feof(archivoContenido))
	{
		idCategoriaAnterior = unJuego->idCategoria;
		idPreguntaAnterior = unJuego->idPregunta;
		while(!feof(archivoContenido) && idCategoriaAnterior == unJuego->idCategoria)
		{
			while(!feof(archivoContenido) && idPreguntaAnterior == unJuego->idPregunta)
			{
				cout<<unJuego->descripcionPregunta;
				fread(unJuego, sizeof(Juego), 1, archivoContenido);
			}
			
		}
			
	}
	
	fclose(archivoContenido);
	
	
	/*strcpy(unJuego->nombreCategoria, "Historia");
	strcpy(unJuego->descripcionPregunta, "?Como se llamo la bomba lanzada en la ciudad de Hiroshima el 6 de Agosto de 1945?");
	strcpy(unJuego->descripcionRespuesta, "A. Fat Man");
	unJuego->esCorrecta = false;
	unJuego->idCategoria = 1;
	unJuego->idPregunta = 1;
	fwrite(unJuego, sizeof(Juego), 1, archivoContenido);
	strcpy(unJuego->nombreCategoria, "Historia");
	strcpy(unJuego->descripcionPregunta, "?Como se llamo la bomba lanzada en la ciudad de Hiroshima el 6 de Agosto de 1945?");
	strcpy(unJuego->descripcionRespuesta, "B. Little Boy");
	unJuego->esCorrecta = true;
	unJuego->idCategoria = 1;
	unJuego->idPregunta = 1;
	fwrite(unJuego, sizeof(Juego), 1, archivoContenido);
	
	strcpy(unJuego->nombreCategoria, "Historia");
	strcpy(unJuego->descripcionPregunta, "?En que anio se desarrollo la guerra de Malvinas?");
	strcpy(unJuego->descripcionRespuesta, "A. 1980");
	unJuego->esCorrecta = false;
	unJuego->idCategoria = 1;
	unJuego->idPregunta = 2;
	fwrite(unJuego, sizeof(Juego), 1, archivoContenido);
	strcpy(unJuego->nombreCategoria, "Historia");
	strcpy(unJuego->descripcionPregunta, "?En que anio se desarrollo la guerra de Malvinas?");
	strcpy(unJuego->descripcionRespuesta, "B. 1982");
	unJuego->esCorrecta = true;
	unJuego->idCategoria = 1;
	unJuego->idPregunta = 2;
	fwrite(unJuego, sizeof(Juego), 1, archivoContenido);
	
	strcpy(unJuego->nombreCategoria, "Geografia");
	strcpy(unJuego->descripcionPregunta, "?En que frontera se encuentra el Monte Everest?");
	strcpy(unJuego->descripcionRespuesta, "A. Nepal e India");
	unJuego->esCorrecta = false;
	unJuego->idCategoria = 2;
	unJuego->idPregunta = 1;
	fwrite(unJuego, sizeof(Juego), 1, archivoContenido);
	strcpy(unJuego->nombreCategoria, "Geografia");
	strcpy(unJuego->descripcionPregunta, "?En que frontera se encuentra el Monte Everest?");
	strcpy(unJuego->descripcionRespuesta, "B. China y Nepal");
	unJuego->esCorrecta = false;
	unJuego->idCategoria = 2;
	unJuego->idPregunta = 1;
	fwrite(unJuego, sizeof(Juego), 1, archivoContenido);
	
	strcpy(unJuego->nombreCategoria, "Geografia");
	strcpy(unJuego->descripcionPregunta, "?Cual es el rio mas grande?");
	strcpy(unJuego->descripcionRespuesta, "A. Rio Nilo");
	unJuego->esCorrecta = false;
	unJuego->idCategoria = 2;
	unJuego->idPregunta = 2;
	fwrite(unJuego, sizeof(Juego), 1, archivoContenido);
	strcpy(unJuego->nombreCategoria, "Geografia");
	strcpy(unJuego->descripcionPregunta, "?Cual es el rio mas grande?");
	strcpy(unJuego->descripcionRespuesta, "B. Rio Amazonas");
	unJuego->esCorrecta = true;
	unJuego->idCategoria = 2;
	unJuego->idPregunta = 2;
	fwrite(unJuego, sizeof(Juego), 1, archivoContenido);
	
	strcpy(unJuego->nombreCategoria, "Entretenimiento");
	strcpy(unJuego->descripcionPregunta, "?Cual es el apellido de Apu en Los Simpsons?");
	strcpy(unJuego->descripcionRespuesta, "A. Nahasapeemapetilon");
	unJuego->esCorrecta = true;
	unJuego->idCategoria = 3;
	unJuego->idPregunta = 1;
	fwrite(unJuego, sizeof(Juego), 1, archivoContenido);
	strcpy(unJuego->nombreCategoria, "Entretenimiento");
	strcpy(unJuego->descripcionPregunta, "?Cual es el apellido de Apu en Los Simpsons?");
	strcpy(unJuego->descripcionRespuesta, "B. Nahasapasapetilon");
	unJuego->esCorrecta = false;
	unJuego->idCategoria = 3;
	unJuego->idPregunta = 1;
	fwrite(unJuego, sizeof(Juego), 1, archivoContenido);
	
	strcpy(unJuego->nombreCategoria, "Entretenimiento");
	strcpy(unJuego->descripcionPregunta, "?Quien realiza la voz de El Burro en la pelicula de Shrek?");
	strcpy(unJuego->descripcionRespuesta, "A. Cody Cameron");
	unJuego->esCorrecta = false;
	unJuego->idCategoria = 3;
	unJuego->idPregunta = 2;
	fwrite(unJuego, sizeof(Juego), 1, archivoContenido);
	strcpy(unJuego->nombreCategoria, "Entretenimiento");
	strcpy(unJuego->descripcionPregunta, "?Quien realiza la voz de El Burro en la pelicula de Shrek?");
	strcpy(unJuego->descripcionRespuesta, "B. Eddie Murphy");
	unJuego->esCorrecta = true;
	unJuego->idCategoria = 3;
	unJuego->idPregunta = 2;
	fwrite(unJuego, sizeof(Juego), 1, archivoContenido);*/
	
	/*strcpy(unJuego->nombreCategoria, "Geografia");
	fwrite(unJuego, sizeof(Juego), 1, archivoContenido);
	strcpy(unJuego->nombreCategoria, "Deportes");
	fwrite(unJuego, sizeof(Juego), 1, archivoContenido);
	strcpy(unJuego->nombreCategoria, "Arte");
	fwrite(unJuego, sizeof(Juego), 1, archivoContenido);
	strcpy(unJuego->nombreCategoria, "Ciencia");
	fwrite(unJuego, sizeof(Juego), 1, archivoContenido);
	strcpy(unJuego->nombreCategoria, "Entretenimiento");
	fwrite(unJuego, sizeof(Juego), 1, archivoContenido);*/
	
	/*while (fread(unJuego, sizeof(Juego), 1, archivoContenido))
	{
		cout<<unJuego->nombreCategoria;
	}*/
	

	
// ====== LOGICA DE TURNOS Y RONDAS DURANTE EL JUEGO =======
	ListaParticipantes* participantesEnJuego =  ingresarParticipantes();
   	ListaRondas* rondasIniciales = generarRondas(5,participantesEnJuego);
	NodoRonda* rondaAuxiliar = rondasIniciales->primerElemento;

	// ========== Empiezo a recorrer las rondas =========
	while(rondaAuxiliar != NULL){
		NodoTurno* turnoAuxiliar = rondaAuxiliar->turnos->primerElemento;
		// ======== Empiezo a recorrer los turnos de cada ronda ======
		while(turnoAuxiliar != NULL){
			Respuesta respuestaJugador = new Respuesta();
			Participante participanteActual = turnoAuxiliar->turno->participante;


			cout << "Es el turno de " << participanteActual->nombre;
			cout << turnoAuxiliar->unaPregunta->descripcion << endl;


			for (int i = 0; i < 4; ++i)
			{
				
				cout << turnoAuxiliar->unaPregunta->respuestas[i]->descripcion<<endl; 
			}
			cout << "Elija su respuesta." << endl;
			int nroRespuesta = NULL;
			cin >> nroRespuesta;
			while(nroRespuesta != 0 && nroRespuesta != 1 && nroRespuesta != 2 && nroRespuesta != 3){
				cout << "Respuesta inválida. Ingrese su respuesta nuevamente." << endl;
				cin >> nroRespuesta;
			}
			respuestaJugador = turnoAuxiliar->unaPregunta->respuestas[nroRespuesta];
			turnoAuxiliar->unaRespuesta = respuestaJugador; 

			if (respuestaJugador->correcta == 1) 
			{	
				cout << "¡Respuesta Correcta!" << endl;
				participanteActual->puntos = puntos + 1;
			} else {
				cout << "Respuesta Incorrecta" << endl;
			}
			NodoParticipante* participanteAuxiliar = participantesEnJuego->primerElemento;
			while(participanteAuxiliar != NULL){
				unParticipante = participanteAuxiliar->participante;
				cout << "Participante: " << unParticipante->nombre << endl;
				cout << "Puntos: " << unParticipante->puntos << endl;

				participanteAuxiliar = participanteAuxiliar->siguienteElemento;
			}

			// ============= Opciones Turno ==============

			opcionesTurno(participanteActual, rondasIniciales);

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
