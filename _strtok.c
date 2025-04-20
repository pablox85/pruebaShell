#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - Entre point
 *
 * Return: 0 if succes
 */

int main (void)
{

	int indice = 0, flagInWord = 0, contadorDeRecorrer = 0;
	char *recorrer = "( ) hola mundo/putos	<-tabulaso";
	char tab = 9; // tabulacion
	char esp = 32; // espacio

	printf("La string es: %s\n", recorrer); //debug

	while (recorrer[indice] != '\0')
	{
		if (recorrer[indice] != 9 && recorrer[indice] != 32)
		{
			if (flagInWord == 0)
			{
				contadorDeRecorrer++;
				flagInWord = 1;
			}
		}
		else
		{
			flagInWord = 0;
		}
		indice++;
	}		
		printf ("pablabras: %d\n", contadorDeRecorrer);
	
	return (0);

}
