/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconde-a <jconde-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:43:56 by jconde-a          #+#    #+#             */
/*   Updated: 2023/11/16 18:26:19 by jconde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

int	ft_impdec(va_list args)
{
	int	nb;

	nb = va_arg(args, int);
	if (nb < 0)
	{
		nb =ft_putchar('-');
		nb *= -1;
	}
	nb += ft_printconvert_base(nb, "0123456789", 10, 0);
	return (nb);
}

int	ft_num(char *str, va_list args)
{
	int	num;

	num = 0;
	if (*str == 'i' || *str == 'd')
		num = ft_impdec(args);
	else if (*str == 'u')
		num = 
		ft_printconvert_base((unsigned long long)va_arg(args, unsigned int),"0123456789", 10, 0);
	else if (*str == 'x')
		num = ft_printconvert_base((unsigned long long)va_arg(args, unsigned int), "0123456789abcdef", 16, 0);
	else if (*str == 'X')
		num = ft_printconvert_base((unsigned long long)va_arg(args, unsigned int), "0123456789ABCDEF", 16, 0);
	else if (*str == 'p')
	{
		num += ft_putchar ('0');
		num += ft_putchar ('x');
		num = ft_printconvert_base((unsigned long long)va_arg(args, void*),
				"0123456789abcdef", 16, 0);
	}
	num = ft_putnbr(num, 1);
	return (num);
}

int	ft_printconvert_base(unsigned long long n, char *base, int nbase, int lng)
{
	if (n / nbase == 0)
	{
		n = n % nbase;
		lng++;
		ft_putchar( base[n]);
	}
	else
	{
		lng += ft_printconvert_base(n / nbase, base, nbase, lng);
		n = n % nbase;
		lng++;
		ft_putchar( base[n]);
	}
	return (lng);
}


int static	ft_primpara(char *str, va_list args)
{
	int		lng;
	char	lettr;
	char	*word;

	lng = 0;
	if (*str == 'c')
	{
		lettr = va_arg(args, int);
		lng += ft_putchar (lettr);
	}
	else if (*str == 's')
	{
		word = va_arg(args, char *);
		lng += ft_putstr (word);
	}
	else if (*str == 'i' || *str == 'd' || *str == 'u')
		lng += ft_num(str, args);
	else if (*str == 'p' || *str == 'x' || *str == 'X')
		lng += ft_num(str, args);
	else if (*str == '%')
		lng += ft_putchar ('%');
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
