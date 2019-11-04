#include <string>
using namespace std;

struct Nodo
{
	Nodo* siguiente;
	int info;
};

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
	ListaPreguntas* preguntas;
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
};

struct NodoRonda
{
	Ronda* unaRonda;
	NodoRonda* siguienteElemento;
};

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
