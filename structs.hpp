using namespace std;

struct Nodo
{
	Nodo* siguiente;
	int info;
};

struct Pregunta
{
	char descripcion[150];
	bool habilitada;
};

struct Categoria
{
	Pregunta preguntas;
	bool habilitada;	
};

struct Respuesta
{
	char descripcion[150];
	bool correcta;
};

struct Participante
{
	char nombre[50];
	int puntos;
};

struct Turno
{
	Pregunta unaPregunta;
	Respuesta unaRespuesta;
	Participante proxParticipante;
};

#ifndef funciones
#define funciones

bool estaHabilitada(); // Faltan parametros
int sumarPuntos(); // Faltan parametros

#endif
