#pragma once
#include <string>
using namespace std;

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
	Respuesta* respuestas[4];
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
};

struct NodoParticipante
{
	Participante* participante;
	NodoParticipante* siguiente;
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
	int nroRonda;
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

struct Juego
{
	char nombreCategoria[50];
	char descripcionPregunta[200];
	char descripcionRespuesta[200];
	int idCategoria, idPregunta, idRespuesta;
	bool esCorrecta;
};


void agregarTurno(Turno* turno, ListaTurnos* turnos);
void turnosJugados(Participante* participante, ListaRondas* rondas);
void listaPreguntasAgregarElemento(ListaPreguntas* unaLista, Pregunta* unaPregunta);
void opcionesTurno(Participante* participante, ListaRondas* rondas);
ListaPreguntas* listaPreguntasCreate();
ListaRespuestas* listaRespuestasCreate();
ListaRondas* generarRondas(int cantidadRondas, ListaParticipantes* participantes, ListaCategoria* categorias);
ListaCategoria* iniciarCategoriasPreguntasRespuestas();
ListaParticipantes* ingresarParticipantes(int numeroDeParticipantes);
NodoRespuesta* nodoRespuestaCreate(Respuesta* unaRespuesta);
NodoPregunta* nodoPreguntaCreate(Pregunta* unaPregunta);
NodoCategoria* nodoCategoriaCreate(Categoria* unaCategoria);
NodoRonda* buscarUltimaRonda(ListaRondas* rondas);
NodoParticipante* buscarUltimoParticipante(ListaParticipantes* participantes);
Pregunta* preguntaCreate(string descripcion);
Pregunta* traerPreguntaHabilitada(ListaCategoria* categorias);
Categoria* categoriaCreate(string nombre);
Respuesta* respuestaCreate(bool esCorrecta, string descripcion);
Ronda* generarRonda(ListaParticipantes* participantes, int nroRonda, ListaCategoria* categorias);

// Pensar funcion para calcular la cantidad de rondas




