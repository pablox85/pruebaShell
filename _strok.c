#include <stdlib.h>
#include <stdio.h>

/**
 * _strok - separa una cadena en palabras usando espacio o tab
 * @recorrer: cadena de entrada
 *
 * Return: array de strings (char **), terminado en NULL
 */
char **_strok(char *recorrer)
{
	int i = 0, start = 0, end = 0, palabra = 0;
	int flagInWord = 0, contador = 0;
	char **tokens;
	char tab = 9, esp = 32;

	if (recorrer == NULL)
		return (NULL);

	/* Contar palabras */
	while (recorrer[i] != '\0')
	{
		if (recorrer[i] != tab && recorrer[i] != esp)
		{
			if (flagInWord == 0)
			{
				contador++;
				flagInWord = 1;
			}
		}
		else
		{
			flagInWord = 0;
		}
		i++;
	}

	tokens = malloc(sizeof(char *) * (contador + 1));
	if (tokens == NULL)
		return (NULL);

	/* Copiar palabras al array */
	i = 0;
	while (recorrer[i] != '\0')
	{
		while (recorrer[i] == tab || recorrer[i] == esp)
			i++;

		if (recorrer[i] == '\0')
			break;

		start = i;

		while (recorrer[i] != tab && recorrer[i] != esp && recorrer[i] != '\0')
			i++;

		end = i;

		tokens[palabra] = malloc(end - start + 1);
		if (tokens[palabra] == NULL)
		{
			while (palabra > 0)
			{
				free(tokens[--palabra]);
			}
			free(tokens);
			return (NULL);
		}

		for (int j = 0; j < end - start; j++)
			tokens[palabra][j] = recorrer[start + j];

		tokens[palabra][end - start] = '\0';
		palabra++;
	}

	tokens[palabra] = NULL;
	return (tokens);
}
