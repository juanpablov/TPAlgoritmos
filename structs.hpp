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
	ListaTurnos* turnos;
};

struct Turno
{	
	int idTurno;
	Participante* participante;
	Pregunta* unaPregunta;
	Respuesta* unaRespuesta;
	string horarioTurno;
};

struct ListaTurnos
{
	Turno* turno;
	ListaTurnos* siguiente;
}
struct Ronda{
	int idRonda;
	ListaTurnos* turnos;
}
struct ListaRondas{
	Ronda* ronda;
	ListaRondas* siguiente;
}

#ifndef funciones
#define funciones

bool estaHabilitada(); // Faltan parametros
int sumarPuntos(); // Faltan parametros

#endif
