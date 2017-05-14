/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrcolor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 23:42:20 by mo0ky             #+#    #+#             */
/*   Updated: 2017/03/16 00:06:40 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbrcolor(int nb, char *color)
{
	long	l_nbr;
	long	d;

	l_nbr = (long)nb;
	if (l_nbr == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (l_nbr < 0)
	{
		ft_putchar('-');
		l_nbr *= -1;
	}
	d = 1;
	while (l_nbr / d != 0)
		d *= 10;
	ft_putstr(color);
	while (d - 1)
	{
		ft_putchar((l_nbr - (l_nbr / d * d)) / (d / 10) + 48);
		d /= 10;
	}
	ft_putstr(C_DFL);
}