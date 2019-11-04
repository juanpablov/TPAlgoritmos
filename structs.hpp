#include <string>
using namespace std;

struct Nodo
{
	Nodo* siguiente;
	int info;
};

struct Pregunta
{
	string descripcion;
	bool habilitada;
	ListaRespuestas respuestas;
};

struct ListaPreguntas
{
	Pregunta* pregunta;
	ListaPreguntas* siguiente;
};

struct ListaRespuestas
{
	Respuesta* respuesta;
	ListaRespuestas* siguiente;
};


struct Categoria
{
	ListaPregunta* preguntas;
	bool habilitada;
};

struct Respuesta
{
	string descripcion;
	bool correcta;
};

struct Participante
{	
	int idParticipante;
	string nombre;
	bool habilitado;
	int puntos;
	// int posUltPreg;
	//ListaTurnos* turnos;
};
struct NodoParticipante{
	Participante* participante;
	NodoParticipante* siguiente;
}
struct ListaParticipantes{
	NodoParticipante* primerElemento;
}

struct Turno
{	
	int idTurno;
	Participante* participante;
	Pregunta* unaPregunta;
	Respuesta* unaRespuesta;
	string horarioTurno;
};
struct NodoTurno{
	Turno* turno;
	NodoTurno* siguiente;
};

struct ListaTurnos
{
	NodoTurno* primerElemento;
}
struct Ronda{
	int idRonda;
	ListaTurnos* turnos;
}
struct ListaRondas{
	Ronda* ronda;
	ListaRondas* siguiente;
}


// ========== MODELO FUNCION GENERAR RONDA ==========
Ronda generarRonda(ListaParticipantes* participantes, ListaTurnos* turnos){
	Ronda nueva_ronda = new Ronda();
	NodoParticipante* participanteAuxiliar = participantes->primerElemento;
	while(participanteAuxiliar->siguiente != NULL && participanteAuxiliar->participante->habilitado == 1){
		Turno nuevo_turno = new Turno();
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
	nueva_ronda->turnos = turnos;
	return nueva_ronda;
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



#ifndef funciones
#define funciones

bool estaHabilitada(); // Faltan parametros
int sumarPuntos(); // Faltan parametros

#endif
