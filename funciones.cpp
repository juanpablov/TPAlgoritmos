#include "structs.hpp"
#include <iostream>
using namespace std;

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
	
}