/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_arg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconde-a <jconde-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:06:39 by jconde-a          #+#    #+#             */
/*   Updated: 2023/11/22 13:55:54 by jconde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pr_p(va_list args)
{
	int						num;
	unsigned long long int	number;

	number = (unsigned long long int )va_arg(args, void *);
	if (number == 0)
		num = ft_putstr ("0x0");
	else
	{
		num = ft_putchar ('0');
		num += ft_putchar ('x');
		num += ft_prconvert_basep(number, LOWHEX, 16, 0);
	}
	return (num);
}

int	ft_prconvert_basep(unsigned long long int n, char *base, int nbase, int lng)
{
	if (n / nbase == 0)
	{
		n = n % nbase;
		lng++;
		ft_putchar(base[n]);
	}
	else
	{
		lng += ft_prconvert_basep(n / nbase, base, nbase, lng);
		n = n % nbase;
		lng++;
		ft_putchar(base[n]);
	}
	return (lng);
}

int	ft_pr_x(va_list args)
{
	int	num;
	int	number;

	number = va_arg(args, unsigned int);
	num = ft_printconvert_base(number, LOWHEX, 16, 0);
	return (num);
}

int	ft_pr_ux(va_list args)
{
	int	num;
	int	number;

	number = va_arg(args, unsigned int);
	num = ft_printconvert_base(number, HIGHHEX, 16, 0);
	return (num);
}
