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

struct NodoPregunta
{
	Pregunta* unaPregunta;
	NodoPregunta* siguienteElemento;
};

struct ListaPreguntas
{
	NodoPregunta* primerElemento;
};


struct Categoria
{
	string nombre;
	ListaPregunta* preguntas;
	bool habilitada;
};

struct NodoCategoria
{
	Categoria* unaCategoria;
	NodoCategoria* siguienteElemento;
};

struct ListaCategoria
{
	NodoCategoria* primerElemento;
}

struct Respuesta
{
	string descripcion;
	bool correcta;
};

struct NodoRespuesta
{
	Respuesta* unaRespuesta;
	NodoRespuesta* siguienteElemento;
};

struct ListaRespuestas
{
	NodoRespuesta* primerElemento;
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

struct NodoParticipante
{
	Participante* participante;
	NodoParticipante* siguienteElemento;
};

struct ListaParticipantes
{
	NodoParticipante* primerElemento;
};

struct Turno
{
	int idTurno;
	Participante* participante;
	Pregunta* unaPregunta;
	Respuesta* unaRespuesta;
	string horarioTurno;
};

struct NodoTurno
{
	Turno* turno;
	NodoTurno* siguienteElemento;
};

struct ListaTurnos
{
	NodoTurno* primerElemento;
};

struct Ronda
{
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

struct NodoRonda
{
	Ronda* unaRonda;
	NodoRonda* siguienteElemento;
}

struct ListaRondas
{
	NodoRonda* primerElemento;
};

#ifndef funciones
#define funciones

void agregarTurno(Turno* turno, ListaTurnos* turnos);
Ronda generarRonda(ListaParticipantes* participantes, ListaTurnos* turnos);
void recuperarCatPregResp(ListaCategoria* unaListaCat);
Categoria* inicializarNuevaCategoria();
bool estaHabilitada(); // Faltan parametros
int sumarPuntos(); // Faltan parametros

#endif
