#include "structs.hpp"
#include <iostream>
using namespace std;

Pregunta* traerPreguntaHabilitada()
{
	
}

Ronda generarRonda(ListaParticipantes* participantes, ListaTurnos* turnos){
	NodoParticipante* participanteAuxiliar = participantes->primerElemento;
	// Participante participanteActual = participantes->participante;
	while(participanteAuxiliar->siguiente != NULL && participanteAuxiliar->participante->habilitado == 1){
		nuevo_turno = new Turno();
		nuevo_turno->participante = participanteAuxiliar->participante;
		nuevo_turno->pregunta = traerPreguntaHabilitada();
		nuevo_turno->respuesta = NULL;
		nuevo_turno->horarioTurno = NULL;
		agregarTurno(nuevo_turno, turnos);

		participanteAuxiliar->participante->habilitado = 0;
		// participantes->participante->habilitado = 0;
		participanteAuxiliar = participanteAuxiliar->siguiente;
	}
	participanteAuxiliar = participantes->primerElemento;
	while(participanteAuxiliar->siguiente != NULL && participanteAuxiliar->participante->habilitado == 0){
		participanteAuxiliar->participante->habilitado = 1;
		participanteAuxiliar = participanteAuxiliar->siguiente;
	}
}

void agregarTurno(Turno* turno, ListaTurnos* turnos){
	NodoTurno* nodoAuxiliar = turnos->primerElemento;
	// agregar chequeo lista vacia 
	while(nodoAuxiliar->siguiente != NULL){
		nodoAuxiliar = nodoAuxiliar->siguiente;
	}
	NodoTurno* nuevo_nodo_turno = new NodoTurno();
	nuevo_nodo_turno->turno = turno;
	nuevo_nodo_turno->siguiente = NULL;
	nodoAuxiliar->siguiente = nuevo_nodo_turno;
}

bool estaHabilitada()
{
	// Completar
}

int sumarPuntos()
{
	// Completar
}
