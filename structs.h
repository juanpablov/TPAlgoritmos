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
	//puede ser un array de respuestas?
	Respuesta* respuestas[4];
	ListaRespuestas* respuestass;
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
	int idCategoria, idPregunta, idRespuesta;
	bool esCorrecta;
};

#ifndef funciones
#define funciones

void agregarTurno(Turno* turno, ListaTurnos* turnos);
Ronda generarRonda(ListaParticipantes* participantes, ListaTurnos* turnos);
void recuperarCatPregResp(ListaCategoria* unaListaCat);
ListaCategorias* iniciarCategoriasPreguntasRespuestas();
Categoria* inicializarNuevaCategoria();
ListaPreguntas* listaPreguntasCreate();
ListaRespuestas* listaRespuestasCreate();
NodoRespuesta* nodoRespuestaCreate(Respuesta* unaRespuesta);
NodoPregunta* nodoPreguntaCreate(Pregunta* unaPregunta);
NodoCategoria* nodoCategoriaCreate(Categoria* unaCategoria);
Categoria* categoriaCreate(string nombre);
Pregunta* preguntaCreate(string descripcion);
Respuesta* respuestaCreate(bool esCorrecta, string descripcion );
Pregunta* traerPreguntaHabilitada();
ListaParticipantes* ingresarParticipantes();
NodoParticipante* buscarUltimoParticipante(ListaParticipantes* participantes);
void listaCategoriaAgregarElemento(ListaCategoria *unaLista, Categoria *unaCategoria);
NodoCategoria* listaCategoriaUltimoElemento(ListaCategoria *unaLista);
NodoPregunta* listaPreguntasUltimoElemento(ListaPreguntas* unaLista);
void listaPreguntasAgregarElemento(ListaPreguntas* unaLista, Pregunta* unaPregunta);
bool estaHabilitada(); 
int sumarPuntos(); 

#endif
