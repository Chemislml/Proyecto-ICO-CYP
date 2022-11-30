
#include "stdafx.h"
#include <string.h>
#include "corrector.h"
#define TAMTOKEN 50

//Funciones publicas del proyecto
/*****************************************************************************************************************
	DICCIONARIO: Esta funcion crea el diccionario completo
	char *	szNombre				:	Nombre del archivo de donde se sacaran las palabras del diccionario	
	char	szPalabras[][TAMTOKEN]	:	Arreglo con las palabras completas del diccionario
	int		iEstadisticas[]			:	Arreglo con el numero de veces que aparecen las palabras en el diccionario
	int &	iNumElementos			:	Numero de elementos en el diccionario
******************************************************************************************************************/
void	Diccionario			(char *szNombre, char szPalabras[][TAMTOKEN], int iEstadisticas[], int &iNumElementos)
{

	//Sustituya estas lineas por su código
	iNumElementos=1;
	strcpy(szPalabras[0],"AquiVaElDiccionario");
	iEstadisticas[0] = 1; // la primer palabra aparece solo una vez.

	FILE* archivo;

		char textoEnBruto[700];

		//Leer todo el archivo hasta su final, guardando todo el texto del mismo en un arr|ay
		while (!feof(archivo))
		{
			for (int i = 0; i != NUMPALABRAS; i++)
			{
				//fgets(texto[i], NUMPALABRAS, archivo);
				fscanf(archivo, "%s", textoEnBruto[i]);
				//printf("%s\n", texto[i]);
			}
			fclose(archivo);
		}

		int caracterszNombre, numpalabra = 0, j = 0;
		char szpalabrasinorden[][TAMTOKEN]{ 'hola','pepe','C' };
		char arrayAxiliar[TAMTOKEN];
		struct PALABRA_CON_FREC
		{
			char laPalabra[TAMTOKEN];
				int frecuencia = 1;
			}unaPalabra;

		//empezar a separar el array palabra por palabra en un array exclusivo para cada palabra
		while (szNombre[caracterszNombre] != '\0')
		{
			caracterszNombre = 0;
			//va a evitar tomar como valido cararcteres vacios y signos de puntuación
			while (caracterszNombre != ' ' && caracterszNombre != '\0' && caracterszNombre != '	' && caracterszNombre != ',' && caracterszNombre != '.' && caracterszNombre != '(' && caracterszNombre != ')' && caracterszNombre != '¿' && caracterszNombre != '?' && caracterszNombre != '!' && caracterszNombre != '¡')
			{
				//en este caso lo que pasa es que toma el valor caracterszNombre y despues de usar el valor le suma 1 a el valor
				szpalabrasinorden[numpalabra][caracterszNombre++] = szNombre[caracterszNombre];
			}
			//se salio de este ciclo porque encontro un carater que debe de evitar
			caracterszNombre = '\0';
			numpalabra++;

			if (szNombre[caracterszNombre] != '\0')
			{
				/*esta linea es necesaria para hacer que recorra la siguiente casilla del
				arreglo ya que si se deja en la misma casilla nuca más va entar al while
				de arriba y solo va almacenar una sola palabra*/
				caracterszNombre++;
			}
		}
		/*solo va a poder salir del while en cunato acabe el arreglo ahora solo queda ordenar las palabras alfabeticamente e
		e identificar las palabras que se repiten*/
		for (int i = 0; i < caracterszNombre; i++)
		{
			for (int posicionDelantera = 1; posicionDelantera < caracterszNombre; posicionDelantera++)
			{
				if (strcmp(szpalabrasinorden[i], szpalabrasinorden[posicionDelantera]) == 0)
					/*esto es en caso de que las palabras son iguales, deja vacia a tabla[posicionDelantera] y a la
					frecuencia le suma 1*/
				{
					szpalabrasinorden[posicionDelantera][0] = '\0';
					unaPalabra.frecuencia++;
				}
}

/*****************************************************************************************************************
	ListaCandidatas: Esta funcion recupera desde el diccionario las palabras validas y su peso
	Regresa las palabras ordenadas por su peso
	char	szPalabrasSugeridas[][TAMTOKEN],	//Lista de palabras clonadas
	int		iNumSugeridas,						//Lista de palabras clonadas
	char	szPalabras[][TAMTOKEN],				//Lista de palabras del diccionario
	int		iEstadisticas[],					//Lista de las frecuencias de las palabras
	int		iNumElementos,						//Numero de elementos en el diccionario
	char	szListaFinal[][TAMTOKEN],			//Lista final de palabras a sugerir
	int		iPeso[],							//Peso de las palabras en la lista final
	int &	iNumLista)							//Numero de elementos en la szListaFinal
******************************************************************************************************************/
void	ListaCandidatas		(
	char	szPalabrasSugeridas[][TAMTOKEN],	//Lista de palabras clonadas
	int		iNumSugeridas,						//Lista de palabras clonadas
	char	szPalabras[][TAMTOKEN],				//Lista de palabras del diccionario
	int		iEstadisticas[],					//Lista de las frecuencias de las palabras
	int		iNumElementos,						//Numero de elementos en el diccionario
	char	szListaFinal[][TAMTOKEN],			//Lista final de palabras a sugerir
	int		iPeso[],							//Peso de las palabras en la lista final
	int &	iNumLista)							//Numero de elementos en la szListaFinal
{

	//Sustituya estas lineas por su código
	strcpy(szListaFinal[0], szPalabrasSugeridas[ 0] ); //la palabra candidata
	iPeso[0] = iEstadisticas[0];			// el peso de la palabra candidata
	
	iNumLista = 1;							//Una sola palabra candidata
}

/*****************************************************************************************************************
	ClonaPalabras: toma una palabra y obtiene todas las combinaciones y permutaciones requeridas por el metodo
	char *	szPalabraLeida,						// Palabra a clonar
	char	szPalabrasSugeridas[][TAMTOKEN], 	//Lista de palabras clonadas
	int &	iNumSugeridas)						//Numero de elementos en la lista
******************************************************************************************************************/
void	ClonaPalabras(
	char *	szPalabraLeida,						// Palabra a clonar
	char	szPalabrasSugeridas[][TAMTOKEN], 	//Lista de palabras clonadas
	int &	iNumSugeridas)						//Numero de elementos en la lista
{
	//Sustituya estas lineas por su código
	strcpy(szPalabrasSugeridas[0], szPalabraLeida); //lo que sea que se capture, es sugerencia
	iNumSugeridas = 1;							//Una sola palabra sugerida
}
