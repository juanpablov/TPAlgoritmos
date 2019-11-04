#include "structs.hpp"
#include <iostream>
using namespace std;


ListaPreguntas* listaPreguntasCreate() {
	ListaPreguntas* listaPreguntas = new ListaPreguntas();
	listaPreguntas->primerElemento = NULL;
	return listaPreguntas;
}

ListaRespuestas* listaRespuestasCreate() {
	ListaRespuestas* respuestas = new ListaRespuestas();
	respuestas->primerElemento = NULL;
	return respuestas;
}

NodoRespuesta* nodoRespuestaCreate(Respuesta* unaRespuesta) {
	NodoRespuesta* nuevoNodo = new NodoRespuesta();
	nuevoNodo->unaRespuesta = unaRespuesta;
	nuevoNodo->siguienteElemento = NULL
	return nuevoNodo;
}

NodoPregunta* nodoPreguntaCreate(Pregunta* unaPregunta) {
	NodoPregunta* nuevoNodo = new NodoPregunta();
	nuevoNodo->unaPregunta = unaPregunta;
	nuevoNodo->siguienteElemento = NULL;
	return nuevoNodo;
}

NodoCategoria* nodoCategoriaCreate(Categoria* unaCategoria) {
	NodoCategoria* nuevoNodo = new NodoCategoria();
	nuevoNodo->unaCategoria = unaCategoria;
	nuevoNodo->siguienteElemento = NULL;
	return nuevoNodo;
}

Categoria* categoriaCreate(string nombre) {
	Categoria* nuevaCategoria = new Categoria();
	nuevaCategoria->habilitada = true;
	nuevaCategoria->nombre = nombre;
	nuevaCategoria->preguntas = listaPreguntasCreate();
	return nuevaCategoria;
}

Pregunta* preguntaCreate(string descripcion) {
	Pregunta* nuevaPregunta = new Pregunta();
	nuevaPregunta->descripcion = descripcion;
	nuevaPregunta->habilitada = true;
	nuevaPregunta->respuestas = listaRespuestasCreate();
	return nuevaPregunta;
}

Respuesta* respuestaCreate(bool esCorrecta, string descripcion ) {
	Respuesta* unaRespuesta = new Respuesta();
	unaRespuesta->correcta = esCorrecta;
	unaRespuesta->descripcion = descripcion;
	return unaRespuesta;
}


Pregunta* traerPreguntaHabilitada()
{
	
}

Ronda generarRonda(ListaParticipantes* participantes, ListaTurnos* turnos, int nroRonda){
	Ronda ronda = new Ronda();
	NodoParticipante* participanteAuxiliar = participantes->primerElemento;
	while(participanteAuxiliar->siguiente != NULL && participanteAuxiliar->participante->habilitado == 1){
		nuevo_turno = new Turno();
		nuevo_turno->participante = participanteAuxiliar->participante;
		// =============== HACER FUNCTION TRAER PREGUNTA HABILITADA ===============
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

ListaRondas generarRondas(int cantidadRondas, ListaParticipantes* participantes, ListaTurnos* turnos){
	ListaRondas rondasIniciales = new ListaRondas();
	for (int i = 0; i < cantidadRondas; ++i)
	{	
		nueva_ronda = generarRonda(participantes, turnos, i);
		NodoRonda *nodo_ronda = new NodoRonda();
        nodo_ronda->unaRonda = nueva_ronda;
        nodo_ronda->siguiente = NULL;
        if (i == 1)
        {
        	rondasIniciales->primerElemento = nodo_ronda;

        } else{
        	NodoRonda* ultimoNodo = buscarUltimaRonda(rondasIniciales);
        	ultimoNodo->siguiente = nodo_ronda;
        }   
	}
	return rondasIniciales;
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

ListaParticipantes* ingresarParticipantes(){
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

NodoRonda* buscarUltimaRonda(ListaRondas* rondas){
	NodoRonda* nodoAuxiliar = rondas->primerElemento;
	while(nodoAuxiliar->siguiente != NULL){
		nodoAuxiliar = nodoAuxiliar->siguiente;
	}
	return nodoAuxiliar;
}

NodoParticipante* buscarUltimoParticipante(ListaParticipantes* participantes){
	NodoParticipante* nodoAuxiliar = participantes->primerElemento;
	while(nodoAuxiliar->siguiente != NULL){
		nodoAuxiliar = nodoAuxiliar->siguiente;
	}
	return nodoAuxiliar;	
}



