#include "printft.h"

int	ft_pr_p(va_list args)
{
	int num;
	ULL number;

	number = (ULL)va_arg(args, void*);
	if (number == 0)
		num = ft_putstr ("(nil)");
	else
	{
		num = ft_putchar ('0');
		num += ft_putchar ('x');
		num += ft_printconvert_base(number, LOWHEX, 16, 0);
	}
	return (num);
}

int	ft_pr_x(va_list args)
{
	int num;
	ULL number;

	number = (ULL)va_arg(args, void*);
	num = ft_printconvert_base(number, LOWHEX, 16, 0);
	return (num);
}

int	ft_pr_X(va_list args)
{
{
	int num;
	ULL number;

	number = (ULL)va_arg(args, void*);
	num = ft_printconvert_base(number, HIGHHEX, 16, 0);
	return (num);
}
}

