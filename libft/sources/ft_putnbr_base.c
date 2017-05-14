/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 14:55:49 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/30 14:56:23 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int			check_base(char *base, int len)
{
	if (len == 10)
		return (ft_strcmp(base, "0123456789"));
	if (len == 2)
		return (ft_strcmp(base, "01"));
	if (len == 16)
		return (ft_strcmp(base, "0123456789ABCDEF"));
	if (len == 8)
		return (ft_strcmp(base, "01234567"));
	if (len == 3)
		return (ft_strcmp(base, "rwx"));
	return (0);
}

static void			display_octal_base(int nbr)
{
	if (nbr == 0)
		ft_putchar('0');
	if (nbr == 1)
		ft_putchar('1');
	if (nbr == 2)
		ft_putchar('2');
	if (nbr == 3)
		ft_putchar('3');
	if (nbr == 4)
		ft_putchar('4');
	if (nbr == 5)
		ft_putchar('5');
	if (nbr == 6)
		ft_putchar('6');
	if (nbr == 7)
		ft_putchar('7');
}

static void			ft_putnbr_b(int nbr, char *base, int len_base)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > len_base - 1)
	{
		ft_putnbr_b(nbr / len_base, base, len_base);
		ft_putnbr_b(nbr % len_base, base, len_base);
	}
	else
	{
		if (len_base == 16 && nbr >= 10)
			ft_putchar(nbr + 48 + 7);
		else if (len_base == 8)
		{
			display_octal_base(nbr);
		}
		else
			ft_putchar(nbr + 48);
	}
}

void				ft_putnbr_base(int nbr, char *base)
{
	int				len;

	len = 0;
	while (base[len])
		len++;
	if (len <= 1 || (len != 10 && len != 2 && len != 16 && len != 8))
		return ;
	else
	{
		if (check_base(base, len) != 0)
			return ;
		else
			return (ft_putnbr_b(nbr, base, len));
	}
}
