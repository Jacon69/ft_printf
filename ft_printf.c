/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconde-a <jconde-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:10:25 by jconde-a          #+#    #+#             */
/*   Updated: 2023/11/22 12:45:05 by jconde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	l;

	l = 0;
	while (*s)
	{
		l += ft_putchar(*s);
		s++;
	}
	return (l);
}

int	ft_printconvert_base(unsigned int n, char *base, int nbase, int lng)
{
	if (n / nbase == 0)
	{
		n = n % nbase;
		lng++;
		ft_putchar(base[n]);
	}
	else
	{
		lng += ft_printconvert_base(n / nbase, base, nbase, lng);
		n = n % nbase;
		lng++;
		ft_putchar(base[n]);
	}
	return (lng);
}

int	ft_primpara(char *str, va_list args)
{
	int		lng;

	lng = 0;
	if (*str == 'c')
		return (ft_pr_c(args));
	else if (*str == 's')
		return (ft_pr_s(args));
	else if ((*str == 'i') || (*str == 'd'))
		return (ft_pr_id(args));
	else if (*str == 'u')
		return (ft_pr_u(args));
	else if (*str == 'p')
		return (ft_pr_p(args));
	else if (*str == 'x')
		return (ft_pr_x(args));
	else if (*str == 'X')
		return (ft_pr_ux(args));
	else if (*str == '%')
		return (ft_putchar ('%'));
	return (lng);
}

int	ft_printf(const char *stc, ...)
{
	int		lng;
	va_list	args;
	char	*ptr;

	va_start(args, stc);
	lng = 0;
	while (*stc)
	{
		if (*stc == '%')
		{
			ptr = (char *) stc;
			lng += ft_primpara (++ptr, args);
			stc++;
		}
		else
			lng += ft_putchar(*stc);
		stc++;
	}
	va_end(args);
	return (lng);
}
/*
#include "printft.h"

int main (void)
{
   // char cadena[] =  "a";
    int nimpresion;
   // int nume;

	//nume = 8756;
    nimpresion = ft_printf("%c", 1);
    printf ("\nSe han imprespo %i caracteres\n",nimpresion);
    nimpresion = printf("%c", 1);
    printf ("\nSe han imprespo %i caracteres\n",nimpresion);
	return(0);
}

//gcc -Wall -Werror -Wextra main.c libftprintf.a -o prin
*/