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
	Nodo respuestas;
};

struct ListaPreguntas
{
	Pregunta* pregunta;
	ListaPreguntas* siguiente;
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
	string nombre;
	int puntos;
	ListaTurnos* turnos;
};

struct Turno
{
	Pregunta* unaPregunta;
	Respuesta* unaRespuesta;
	string horarioTurno;
	Participante* proximoParticipante;
};

struct ListaTurnos
{
	Turno* turno;
	LIstaTurnos* siguiente;
}

#ifndef funciones
#define funciones

bool estaHabilitada(); // Faltan parametros
int sumarPuntos(); // Faltan parametros

#endif
