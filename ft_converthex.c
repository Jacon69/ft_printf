
#include "printft.h"

int	ftconvert_base(unsigned long long n, char *base, int nbase, int lng)
{
	if (n / nbase == 0)
	{
		n = n % nbase;
		lng++;
		ft_putchar( base[n]);
	}
	else
	{
		lng += ftconvert_base(n / nbase, base, nbase, lng);
		n = n % nbase;
		lng++;
		ft_putchar( base[n]);
	}
	return (lng);
}

int main (void)
{
	int num;

	num =16;
	num = ftconvert_base((unsigned long long) num, "0123456789abcdef", 16, 0);
	printf ("\nHe impreso %i caracteres \n", num);
	return (0);
}