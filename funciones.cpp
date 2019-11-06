#include "structs.h"
#include <string>
#include <iostream>
using namespace std;


ListaPreguntas* listaPreguntasCreate()
{
	ListaPreguntas* listaPreguntas = new ListaPreguntas();
	listaPreguntas->primerElemento = NULL;
	return listaPreguntas;
}

ListaRespuestas* listaRespuestasCreate()
{
	ListaRespuestas* respuestas = new ListaRespuestas();
	respuestas->primerElemento = NULL;
	return respuestas;
}

NodoRespuesta* nodoRespuestaCreate(Respuesta* unaRespuesta)
{
	NodoRespuesta* nuevoNodo = new NodoRespuesta();
	nuevoNodo->unaRespuesta = unaRespuesta;
	nuevoNodo->siguienteElemento = NULL;
	return nuevoNodo;
};

NodoPregunta* nodoPreguntaCreate(Pregunta* unaPregunta)
{
	NodoPregunta* nuevoNodo = new NodoPregunta();
	nuevoNodo->unaPregunta = unaPregunta;
	nuevoNodo->siguienteElemento = NULL;
	return nuevoNodo;
}

NodoCategoria* nodoCategoriaCreate(Categoria* unaCategoria)
{
	NodoCategoria* nuevoNodo = new NodoCategoria();
	nuevoNodo->unaCategoria = unaCategoria;
	nuevoNodo->siguienteElemento = NULL;
	return nuevoNodo;
}

Categoria* categoriaCreate(string nombre)
{
	Categoria* nuevaCategoria = new Categoria();
	nuevaCategoria->habilitada = true;
	nuevaCategoria->nombre = nombre;
	nuevaCategoria->preguntas = listaPreguntasCreate();
	return nuevaCategoria;
}

Pregunta* preguntaCreate(string descripcion)
{
	Pregunta* nuevaPregunta = new Pregunta();
	nuevaPregunta->descripcion = descripcion;
	nuevaPregunta->habilitada = true;
	return nuevaPregunta;
}

Respuesta* respuestaCreate(bool esCorrecta, string descripcion)
{
	Respuesta* unaRespuesta = new Respuesta();
	unaRespuesta->correcta = esCorrecta;
	unaRespuesta->descripcion = descripcion;
	return unaRespuesta;
}


Pregunta* traerPreguntaHabilitada()
{
	
}


Pregunta traerPreguntaHabilitada(ListaCategorias* categorias)
{
	NodoCategoria* categoriaAuxiliar = categorias->primerElemento;
	NodoPregunta* preguntaAuxiliar = NULL;
	while(categoriaAuxiliar != NULL && categoriaAuxiliar->unaCategoria->habilitada == 0){
		categoriaAuxiliar = categoriaAuxiliar->siguienteElemento;
	}
	if (categoriaAuxiliar != NULL)
	{
		preguntaAuxiliar = categoriaAuxiliar->unaCategoria->preguntas->primerElemento;
		while(preguntaAuxiliar != NULL && preguntaAuxiliar->unaPregunta->habilitada == 0){
			preguntaAuxiliar = preguntaAuxiliar->siguienteElemento;
		}
		if(preguntaAuxiliar != NULL){
			preguntaAuxiliar->unaPregunta->habilitada = 0;
			// Deshabilito la categoria si es la ultima pregunta.
			if(preguntaAuxiliar->siguienteElemento == NULL){
				categoriaAuxiliar->unaCategoria->habilitada = 0;
			}
		}
	} 
	return preguntaAuxiliar;
}



Ronda generarRonda(ListaParticipantes* participantes, int nroRonda, ListaCategorias* categorias)
{
	ListaTurnos* turnos = new ListaTurnos();
	Ronda ronda = new Ronda();
	NodoParticipante* participanteAuxiliar = participantes->primerElemento;
	while(participanteAuxiliar->siguiente != NULL && participanteAuxiliar->participante->habilitado == 1){
		nuevo_turno = new Turno();
		nuevo_turno->participante = participanteAuxiliar->participante;
		// =============== HACER FUNCTION TRAER PREGUNTA HABILITADA ===============
		nuevo_turno->pregunta = traerPreguntaHabilitada(categorias); //Chequear si devuelve pregunta nula.
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

ListaRondas generarRondas(int cantidadRondas, ListaParticipantes* participantes, ListaCategoria* categorias)
{
	ListaRondas* rondasIniciales = new ListaRondas();
	for (int i = 0; i < cantidadRondas; i++)
	{	
		Ronda* nueva_ronda = generarRonda(participantes, i, categorias);
		NodoRonda *nodo_ronda = new NodoRonda();
        nodo_ronda->unaRonda = nueva_ronda;
        nodo_ronda->siguienteElemento = NULL;
        if (i == 0)
        {
        	rondasIniciales->primerElemento = nodo_ronda;

        } else{
        	NodoRonda* ultimoNodo = buscarUltimaRonda(rondasIniciales);
        	ultimoNodo->siguienteElemento = nodo_ronda;
        }   
	}
	return rondasIniciales;
}



void agregarTurno(Turno* turno, ListaTurnos* turnos)
{
	NodoTurno* nodoAuxiliar = turnos->primerElemento;
	// agregar chequeo lista vacia 
	while(nodoAuxiliar->siguiente != NULL){
		nodoAuxiliar = nodoAuxiliar->siguienteElemento;
	}
	NodoTurno* nuevo_nodo_turno = new NodoTurno();
	nuevo_nodo_turno->turno = turno;
	nuevo_nodo_turno->siguienteElemento = NULL;
	nodoAuxiliar->siguienteElemento = nuevo_nodo_turno;
}

bool estaHabilitada()
{
	// Completar
}

int sumarPuntos()
{
	// Completar
}

ListaParticipantes* ingresarParticipantes()
{
	ListaParticipantes* participantes = new ListaParticipantes();
    for(int i = 0; i < 5; i++){
    	Participante* nuevo_participante = new Participante();
    	nuevo_participante->idParticipante = i;
    	nuevo_participante->habilitado = 1;
    	nuevo_participante->puntos = 0;
        cout << "Ingrese un Jugador" << endl;
        cin << nuevo_participante->nombre << endl;
        NodoParticipante* nodo = new NodoParticipante();
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



NodoRonda* buscarUltimaRonda(ListaRondas* rondas)
{
	NodoRonda* nodoAuxiliar = rondas->primerElemento;
	while(nodoAuxiliar->siguienteElemento != NULL){
		nodoAuxiliar = nodoAuxiliar->siguienteElemento;
	}
	return nodoAuxiliar;
}

NodoParticipante* buscarUltimoParticipante(ListaParticipantes* participantes)
d{

	NodoParticipante* nodoAuxiliar = participantes->primerElemento;
	while(nodoAuxiliar->siguiente != NULL){
		nodoAuxiliar = nodoAuxiliar->siguiente;
	}
	return nodoAuxiliar;	
}

void opcionesTurno(Participante* participante){
		cout << "1. Ver puntaje total" << endl;
		cout << "2. Ver preguntas respondidas" <<endl;
		cout << "3. Siguiente Jugador" << endl;
		int opcionElegida;
		cin >> opcionElegida;

		while(opcionElegida != 1 && opcionElegida != 2 && opcionElegida != 3)
		{
			cout << "Opcion invalida. Reingrese la opcion." << endl;
			cin >> opcionElegida; 
		}
		switch(opcionElegida){
			case 1:

				cout << "El puntaje de " << participante->nombre << " es " << participante->puntos << endl;
				opcionesTurno(participante);
				break;
			case 2:
				//Traer turnos del participante
				opcionesTurno(participante);
				break;
			case 3: 
				return;
		}

}

ListaTurnos turnosJugadosDelParticipante(Participante* participante){
	
}


