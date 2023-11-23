/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_arg1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconde-a <jconde-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:05:54 by jconde-a          #+#    #+#             */
/*   Updated: 2023/11/22 11:06:46 by jconde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pr_c(va_list args)
{
	int	num;
	int	lettr;

	lettr = va_arg(args, int);
	num = ft_putchar (lettr);
	return (num);
}

int	ft_pr_s(va_list args)
{
	int		num;
	char	*word;

	word = va_arg(args, char *);
	if (word == NULL)
		num = ft_putstr ("(null)");
	else
		num = ft_putstr (word);
	return (num);
}

int	ft_pr_id( va_list args)
{
	int			num;
	int long	number;

	number = (long int)va_arg(args, int);
	num = 0;
	if (number < 0)
	{
		num = ft_putchar('-');
		number *= -1;
	}
	num += ft_printconvert_base((unsigned long long int)number, DECIMAL, 10, 0);
	return (num);
}

int	ft_pr_u(va_list args)
{
	int						num;
	unsigned long long int	number;

	number = (unsigned long long int)va_arg(args, unsigned int);
	num = ft_printconvert_base(number, DECIMAL, 10, 0);
	return (num);
}
