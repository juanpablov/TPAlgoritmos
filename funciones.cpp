#include "structs.hpp"
#include <iostream>
using namespace std;

Pregunta* traerPreguntaHabilitada()
{
	
}

Ronda generarRonda(ListaParticipantes* participantes, ListaTurnos* turnos){
	Ronda ronda = new Ronda();
	NodoParticipante* participanteAuxiliar = participantes->primerElemento;
	while(participanteAuxiliar->siguiente != NULL && participanteAuxiliar->participante->habilitado == 1){
		nuevo_turno = new Turno();
		nuevo_turno->participante = participanteAuxiliar->participante;
		nuevo_turno->pregunta = traerPreguntaHabilitada();
		nuevo_turno->respuesta = NULL;
		nuevo_turno->horarioTurno = NULL;
		agregarTurno(nuevo_turno, turnos);
		participanteAuxiliar->participante->habilitado = 0;
		participanteAuxiliar = participanteAuxiliar->siguiente;
	}
	participanteAuxiliar = participantes->primerElemento;
	while(participanteAuxiliar->siguiente != NULL && participanteAuxiliar->participante->habilitado == 0){
		participanteAuxiliar->participante->habilitado = 1;
		participanteAuxiliar = participanteAuxiliar->siguiente;
	}
	ronda->turnos = turnos;
	return ronda;
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

ListaParticipantes ingresarParticipantes(){
	ListaParticipantes *participantes = new ListaParticipantes();
    for(int i = 0; i < 5; i++){
    	Participante *nuevo_participante = new Participante();
    	nuevo_participante->id = i;
    	nuevo_participante->habilitado = 1;
    	nuevo_participante->puntos = 0;
        cout << "Ingrese un Jugador" << endl;
        cin << nuevo_participante->nombre << endl;
        NodoParticipante *nodo = new NodoParticipante();
        nodo->participante = nuevo_participante;
        nodo->siguiente = NULL;
        if (i == 0)
        {
        	participantes->primerElemento = nodo;

        } else{
        	NodoParticipante* ultimoNodo = buscarUltimoParticipante(participantes);
        	ultimoNodo->siguiente = nodo;
        }   
    }
    return participantes;
}

NodoParticipante* buscarUltimoParticipante(ListaParticipantes* participantes){
	NodoParticipante* nodoAuxiliar = participantes->primerElemento;
	while(nodoAuxiliar->siguiente != NULL){
		nodoAuxiliar = nodoAuxiliar->siguiente;
	}
	return nodoAuxiliar;	
}










