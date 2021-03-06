#include "structs.h"
#include <iostream>
#pragma warning(disable : 4996)
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
	respuestas->primerElemento  = NULL;
	return respuestas;
}

NodoRespuesta* nodoRespuestaCreate(Respuesta* unaRespuesta)
{
	NodoRespuesta* nuevoNodo     = new NodoRespuesta();
	nuevoNodo->unaRespuesta      = unaRespuesta;
	nuevoNodo->siguienteElemento = NULL;
	return nuevoNodo;
};

NodoPregunta* nodoPreguntaCreate(Pregunta* unaPregunta)
{
	NodoPregunta* nuevoNodo      = new NodoPregunta();
	nuevoNodo->unaPregunta       = unaPregunta;
	nuevoNodo->siguienteElemento = NULL;
	return nuevoNodo;
}

NodoCategoria* nodoCategoriaCreate(Categoria* unaCategoria)
{
	NodoCategoria* nuevoNodo     = new NodoCategoria();
	nuevoNodo->unaCategoria      = unaCategoria;
	nuevoNodo->siguienteElemento = NULL;
	return nuevoNodo;
}

NodoCategoria* listaCategoriaUltimoElemento(ListaCategoria *unaLista)
{
	NodoCategoria* unNodoAuxiliar = unaLista->primerElemento;
	while(unNodoAuxiliar->siguienteElemento != NULL){
		unNodoAuxiliar = unNodoAuxiliar->siguienteElemento;
	}
	return unNodoAuxiliar;
}

void listaCategoriaAgregarElemento(ListaCategoria *unaLista, Categoria *unaCategoria)
{
	NodoCategoria *unNodo = nodoCategoriaCreate(unaCategoria);
	if(unaLista->primerElemento == NULL){
		unaLista->primerElemento = unNodo;
	}
	else{
		NodoCategoria *ultimoNodo = listaCategoriaUltimoElemento(unaLista);
		ultimoNodo->siguienteElemento = unNodo;
	}
}

Categoria* categoriaCreate(string nombre)
{
	Categoria* nuevaCategoria  = new Categoria();
	nuevaCategoria->habilitada = true;
	nuevaCategoria->nombre     = nombre;
	nuevaCategoria->preguntas  = listaPreguntasCreate();
	return nuevaCategoria;
}

Pregunta* categoriaBuscarUltimaPregunta(Categoria* unaCategoria)
{
	NodoPregunta* preguntaAuxiliar = unaCategoria->preguntas->primerElemento;
	while(preguntaAuxiliar->siguienteElemento != NULL){
		preguntaAuxiliar = preguntaAuxiliar->siguienteElemento;
	}
	
	return preguntaAuxiliar->unaPregunta;
}

Pregunta* preguntaCreate(string descripcion)
{
	Pregunta* nuevaPregunta    = new Pregunta();
	nuevaPregunta->descripcion = descripcion;
	nuevaPregunta->habilitada  = true;
	return nuevaPregunta;
}

NodoPregunta* listaPreguntasUltimoElemento(ListaPreguntas* unaLista)
{
	NodoPregunta* unNodoAuxiliar = unaLista->primerElemento;
	while(unNodoAuxiliar->siguienteElemento != NULL){
		unNodoAuxiliar = unNodoAuxiliar->siguienteElemento;
	}
	return unNodoAuxiliar;
}

void listaPreguntasAgregarElemento(ListaPreguntas* unaLista, Pregunta* unaPregunta)
{
	NodoPregunta* nuevoNodo = nodoPreguntaCreate(unaPregunta);
	if(unaLista->primerElemento == NULL){
		unaLista->primerElemento = nuevoNodo;
	}else{
		NodoPregunta* ultimoNodo = listaPreguntasUltimoElemento(unaLista);
		ultimoNodo->siguienteElemento = nuevoNodo;
	}
}

Respuesta* respuestaCreate(bool esCorrecta, string descripcion)
{
	Respuesta* unaRespuesta   = new Respuesta();
	unaRespuesta->correcta    = esCorrecta;
	unaRespuesta->descripcion = descripcion;
	return unaRespuesta;
}

Pregunta* traerPreguntaHabilitada(ListaCategoria* categorias)
{
	NodoCategoria* categoriaAuxiliar = categorias->primerElemento;
	NodoPregunta* preguntaAuxiliar   = NULL;
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
	return preguntaAuxiliar->unaPregunta;
}



Ronda* generarRonda(ListaParticipantes* participantes, int nroRonda, ListaCategoria* categorias)
{
	ListaTurnos* turnos	= new ListaTurnos();
	Ronda* ronda		= new Ronda();
	NodoParticipante* participanteAuxiliar = participantes->primerElemento;
	while(participanteAuxiliar->siguiente != NULL && participanteAuxiliar->participante->habilitado == 1){
		Turno* nuevo_turno = new Turno();
		nuevo_turno->participante = participanteAuxiliar->participante;
		nuevo_turno->unaPregunta = traerPreguntaHabilitada(categorias); 
		nuevo_turno->unaRespuesta = NULL;
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

ListaRondas* generarRondas(int cantidadRondas, ListaParticipantes* participantes, ListaCategoria* categorias)
{
	ListaRondas* rondasIniciales = new ListaRondas();
	for (int i = 0; i < cantidadRondas; i++)
	{	
		Ronda* nueva_ronda    = generarRonda(participantes, i, categorias);
		NodoRonda *nodo_ronda = new NodoRonda();
        nodo_ronda->unaRonda  = nueva_ronda;
        nodo_ronda->siguienteElemento = NULL;
        if (i == 0)
        {
        	rondasIniciales->primerElemento = nodo_ronda;
        }else{
        	NodoRonda* ultimoNodo         = buscarUltimaRonda(rondasIniciales);
        	ultimoNodo->siguienteElemento = nodo_ronda;
        }   
	}
	return rondasIniciales;
}



void agregarTurno(Turno* turno, ListaTurnos* turnos)
{
	NodoTurno* nuevo_nodo_turno = new NodoTurno();
	nuevo_nodo_turno->turno = turno;
	nuevo_nodo_turno->siguienteElemento = NULL;

	if (turnos->primerElemento == NULL) {
		turnos->primerElemento = nuevo_nodo_turno;
	}
	else {
		NodoTurno* nodoAuxiliar = turnos->primerElemento;
		while (nodoAuxiliar->siguienteElemento != NULL) {
			nodoAuxiliar = nodoAuxiliar->siguienteElemento;
		}
		nodoAuxiliar->siguienteElemento = nuevo_nodo_turno;
	}
}

ListaParticipantes* ingresarParticipantes(int numeroDeParticipantes)
{
	ListaParticipantes* participantes = new ListaParticipantes();
    for(int i = 0; i < numeroDeParticipantes; i++){
    	Participante* nuevo_participante = new Participante();
    	nuevo_participante->idParticipante = i;
    	nuevo_participante->habilitado = 1;
    	nuevo_participante->puntos = 0;
        cout << "Ingrese un Jugador" << endl;
        cin >> nuevo_participante->nombre;
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
{

	NodoParticipante* nodoAuxiliar = participantes->primerElemento;
	while(nodoAuxiliar->siguiente != NULL){
		nodoAuxiliar = nodoAuxiliar->siguiente;
	}
	return nodoAuxiliar;	
}

void opcionesTurno(Participante* participante, ListaRondas* rondas){
		cout << "1. Ver mi puntaje total" << endl;
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
				opcionesTurno(participante, rondas); 
				break;
			case 2:
				turnosJugados(participante, rondas);
				opcionesTurno(participante, rondas);
				break;
			case 3: 
				return;
		}

}

ListaCategoria* iniciarCategoriasPreguntasRespuestas()
{
	ListaCategoria* listaCategoria = new ListaCategoria();
	FILE* archivoContenido = fopen("contenido.dat", "rb");

	Juego* unJuego = new Juego();
	int idCategoriaAnterior, idPreguntaAnterior;

	fread(unJuego, sizeof(Juego), 1, archivoContenido);

	while (!feof(archivoContenido))
	{
		idCategoriaAnterior = unJuego->idCategoria;
		Categoria* unaCategoria = categoriaCreate(string(unJuego->nombreCategoria));
		listaCategoriaAgregarElemento(listaCategoria, unaCategoria);

		while (!feof(archivoContenido) && idCategoriaAnterior == unJuego->idCategoria)
		{
			idPreguntaAnterior = unJuego->idPregunta;
			Pregunta* unaPregunta = preguntaCreate(string(unJuego->descripcionPregunta));
			listaPreguntasAgregarElemento(unaCategoria->preguntas, unaPregunta);

			int i = 0;
			while (!feof(archivoContenido) && idPreguntaAnterior == unJuego->idPregunta)
			{
				Pregunta* ultimaPregunta = categoriaBuscarUltimaPregunta(unaCategoria);
				ultimaPregunta->respuestas[i] = respuestaCreate(unJuego->esCorrecta, string(unJuego->descripcionRespuesta));
				i++;

				//cout << unJuego->nombreCategoria << " " << unJuego->descripcionPregunta << " " << unJuego->descripcionRespuesta << endl;

				fread(unJuego, sizeof(Juego), 1, archivoContenido);
			}
			idPreguntaAnterior = unJuego->idPregunta;
		}
		idCategoriaAnterior = unJuego->idCategoria;

	}

	fclose(archivoContenido);
	return listaCategoria;
}

void turnosJugados(Participante* participante, ListaRondas* rondas){
	NodoRonda* rondaAuxiliar = rondas->primerElemento;
	int contadorRespuestas = 0;
	while(rondaAuxiliar != NULL){
		NodoTurno* turnoAuxiliar = rondaAuxiliar->unaRonda->turnos->primerElemento;
		while(turnoAuxiliar != NULL){
			if (participante->idParticipante == turnoAuxiliar->turno->participante->idParticipante)
			{
				if (turnoAuxiliar->turno->unaRespuesta != NULL)
				{
					contadorRespuestas++;
					cout << "Preguntas Respondidas Por " << turnoAuxiliar->turno->participante->nombre << ":" << endl;
					cout << "Datos de la pregunta numero" << " " << contadorRespuestas << endl;
					cout << turnoAuxiliar->turno->unaPregunta->descripcion << endl;
					cout << "Su respuesta fue: " << endl;
					cout << turnoAuxiliar->turno->unaRespuesta->descripcion << endl;
					if (turnoAuxiliar->turno->unaRespuesta->correcta == 1)
					{
						cout << "La respuesta es CORRECTA" << endl << endl;
					} else{
						cout << "La respuesta es INCORRECTA" << endl << endl;

					}
				}
			}
			turnoAuxiliar = turnoAuxiliar->siguienteElemento;
		}
		rondaAuxiliar = rondaAuxiliar->siguienteElemento;
	}
	return;

}


