
#include "printft.h"

int main (void)
{
    char cadena[] =  "el mundo viene";
    int nimpresion;
    int nume;

	nume = 8755
    nimpresion = ft_printf(""Esto es con propia texto %s y numero %i ", cadena, nume);
    printf ("\nSe han imprespo %i caracteres\n",nimpresion);

        nimpresion = printf("Esto es con original texto %s y numero %i ", cadena, nume);
    printf ("\nSe han imprespo %i caracteres\n",nimpresion);
	return(0);
}