/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconde-a <jconde-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:55:26 by jconde-a          #+#    #+#             */
/*   Updated: 2023/11/16 13:40:25 by jconde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"



int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int nb, int len)
{
	int	r;

	if (nb < 0)
	{
		ft_putchar('-');
		len ++;
		nb *= -1;
	}
	r = nb / 10;
	if (r > 0)
		len = ft_putnbr (r, ++len);
	ft_putchar((nb % 10) + '0');
	return (len);
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