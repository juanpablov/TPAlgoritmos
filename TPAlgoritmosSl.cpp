// TPAlgoritmosSl.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <iostream>
#include "Estructuras.h"

using namespace std;


int main()
{
	// ====== LOGICA DE TURNOS Y RONDAS DURANTE EL JUEGO =======

	ListaCategoria *categorias = iniciarCategoriasPreguntasRespuestas();
	ListaParticipantes* participantesEnJuego = ingresarParticipantes(3);
	ListaRondas* rondasIniciales = generarRondas(3, participantesEnJuego, categorias);

	NodoRonda* rondaAuxiliar = rondasIniciales->primerElemento;

	// ========== Empiezo a recorrer las rondas =========
	while (rondaAuxiliar != NULL) {
		NodoTurno* turnoAuxiliar = rondaAuxiliar->unaRonda->turnos->primerElemento;
		// ======== Empiezo a recorrer los turnos de cada ronda ======
		while (turnoAuxiliar != NULL) {
			Respuesta *respuestaJugador = new Respuesta();
			Participante *participanteActual = turnoAuxiliar->turno->participante;


			cout << "Es el turno de " << participanteActual->nombre << endl;
			cout << turnoAuxiliar->turno->unaPregunta->descripcion << endl;


			for (int i = 0; i < 2; ++i)
			{

				cout << turnoAuxiliar->turno->unaPregunta->respuestas[i]->descripcion << endl;
			}
			cout << "Elija su respuesta." << endl;
			int nroRespuesta = NULL;
			cin >> nroRespuesta;
			nroRespuesta = nroRespuesta - 1;
			while (nroRespuesta != 0 && nroRespuesta != 1 && nroRespuesta != 2 && nroRespuesta != 3) {
				cout << "Respuesta invalida. Ingrese su respuesta nuevamente." << endl;
				cin >> nroRespuesta;
			}
			respuestaJugador = turnoAuxiliar->turno->unaPregunta->respuestas[nroRespuesta];
			turnoAuxiliar->turno->unaRespuesta = respuestaJugador;

			if (respuestaJugador->correcta == 1)
			{
				cout << "¡Respuesta Correcta!" << endl << endl;
				participanteActual->puntos += 1;
			}
			else {
				cout << "Respuesta Incorrecta" << endl << endl;
			}

			NodoParticipante* participanteAuxiliar = participantesEnJuego->primerElemento;
			while (participanteAuxiliar != NULL) {
				Participante *unParticipante = participanteAuxiliar->participante;
				cout << "Participante: " << unParticipante->nombre << " - ";
				cout << "Puntos: " << unParticipante->puntos << endl << endl;

				participanteAuxiliar = participanteAuxiliar->siguiente;
			}

			// ============= Opciones Turno ==============

			opcionesTurno(participanteActual, rondasIniciales);

			turnoAuxiliar = turnoAuxiliar->siguienteElemento;

		}

		rondaAuxiliar = rondaAuxiliar->siguienteElemento;

	}
	cout << "El juego ha finalizado" << endl << endl;
	NodoParticipante* participanteAuxiliar = participantesEnJuego->primerElemento;
	while (participanteAuxiliar != NULL) {
		cout << "El puntaje de " << participanteAuxiliar->participante->nombre << " es " << participanteAuxiliar->participante->puntos << endl;
		participanteAuxiliar = participanteAuxiliar->siguiente;
	}

	return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
