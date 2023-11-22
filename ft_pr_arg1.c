#include "printft.h"

int ft_pr_c(va_list args)
{
	int num;
	int lettr;

	lettr = va_arg(args, int);

		num = ft_putchar (lettr);

	return(num);
}

int ft_pr_s(va_list args)
{
	int 	num;
	char	*word;

		word = va_arg(args, char *);
		if (word == NULL)
			num = ft_putstr ("(null)");
		else
			num = ft_putstr (word);
	return(num);
}

int ft_pr_i( va_list args)
{
	int			num;
	int long	number;

	number = (long int)va_arg(args, int);
	num = 0;
	if (number < 0)
	{
		num =ft_putchar('-');
		number *= -1;
	}
	num += ft_printconvert_base(number, DECIMAL, 10, 0);
	return (num);
}

int ft_pr_d( va_list args)
{
	int			num;
	int long	number;

	number = (long int)va_arg(args, int);
	num = 0;
	if (number < 0)
	{
		num =ft_putchar('-');
		number *= -1;
	}
	num += ft_printconvert_base(number, DECIMAL, 10, 0);
	return (num);
}

int ft_pr_u(va_list args)
{
	int num;
	ULL number;

	number = (ULL)va_arg(args, UI);
	num = ft_printconvert_base(number, DECIMAL, 10, 0);
	return (num);
}
