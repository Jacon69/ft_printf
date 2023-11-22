/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconde-a <jconde-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:09:11 by jconde-a          #+#    #+#             */
/*   Updated: 2023/11/16 18:07:36 by jconde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFT_H
# define PRINTFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putnbr(int nb, int len);
int	ft_putstr(char *s);
int	ft_printconvert_base(unsigned long long n, char *base, int nbase, int lng);
int ft_pr_c(va_list args);
int ft_pr_s(va_list args);
int ft_pr_i(va_list args);
int ft_pr_d(va_list args);
int ft_pr_u(va_list args);
int ft_pr_p(va_list args);
int ft_pr_x(va_list args);
int ft_pr_X(va_list args);
#endif
#ifndef  HIGHHEX
# define HIGHHEX "0123456789ABCDEF"
#endif
#ifndef  LOWHEX
# define LOWHEX "0123456789abcdef"
#endif
#ifndef  DECIMAL
# define DECIMAL "0123456789"
#endif
#ifndef  ULL
# define ULL unsigned long long int
#endif
#ifndef  UI
# define UI unsigned int
#endif