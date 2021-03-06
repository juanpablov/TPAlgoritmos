#pragma once
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
	//puede ser un array de respuestas?
	Respuesta* respuestas[4];
	//ListaRespuestas respuestas;
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
	char descripcionPregunta[150];
	char descripcionRespuesta[150];
	int idCategoria, idPregunta;
	bool esCorrecta;
};


void agregarTurno(Turno* turno, ListaTurnos* turnos);
Ronda generarRonda(ListaParticipantes* participantes, ListaTurnos* turnos);
void recuperarCatPregResp(ListaCategoria* unaListaCat);
void iniciarCategoriasPreguntasRespuestas(ListaCategoria* categorias);
Categoria* inicializarNuevaCategoria();
ListaPreguntas* listaPreguntasCreate();
ListaRespuestas* listaRespuestasCreate();
NodoRespuesta* nodoRespuestaCreate(Respuesta* unaRespuesta);
NodoPregunta* nodoPreguntaCreate(Pregunta* unaPregunta);
NodoCategoria* nodoCategoriaCreate(Categoria* unaCategoria);
Categoria* categoriaCreate(string nombre);
Pregunta* preguntaCreate(string descripcion);
Respuesta* respuestaCreate(bool esCorrecta, string descripcion);
ListaParticipantes* ingresarParticipantes(int numeroDeParticipantes);
NodoParticipante* buscarUltimoParticipante(ListaParticipantes* participantes);
bool estaHabilitada();
int sumarPuntos();

void turnosJugados(Participante* participante, ListaRondas* rondas);
void listaPreguntasAgregarElemento(ListaPreguntas* unaLista, Pregunta* unaPregunta);
Ronda* generarRonda(ListaParticipantes* participantes, int nroRonda, ListaCategoria* categorias);
ListaRondas* generarRondas(int cantidadRondas, ListaParticipantes* participantes, ListaCategoria* categorias);
ListaCategoria* iniciarCategoriasPreguntasRespuestas();
void opcionesTurno(Participante* participante, ListaRondas* rondas);

NodoRonda* buscarUltimaRonda(ListaRondas* rondas);