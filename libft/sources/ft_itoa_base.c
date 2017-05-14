/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:23:13 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/30 14:54:20 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
	return (0);
}

static char			*ft_strjoinc(char *s1, char const c)
{
	char			*ptr;

	ptr = NULL;
	if (s1)
	{
		if (*s1 == 0)
		{
			if (!(ptr = ft_strnew(1)))
				return (NULL);
			ptr[0] = c;
		}
		else
		{
			if ((ptr = ft_strnew(ft_strlen(s1) + 1)))
			{
				ptr = ft_strcpy(ptr, s1);
				ptr[ft_strlen(s1)] = c;
			}
		}
		free(s1);
	}
	return (ptr);
}

static char			*ft_itoa_b(char **ret, int n, char *base, int len_base)
{
	if (n < 0)
	{
		*ret = ft_strjoinc(*ret, '-');
		n *= -1;
	}
	if (n > len_base - 1)
	{
		ft_itoa_b(ret, n / len_base, base, len_base);
		ft_itoa_b(ret, n % len_base, base, len_base);
	}
	else
	{
		if (len_base == 16 && n >= 10)
			*ret = ft_strjoinc(*ret, n + 48 + 7);
		else
			*ret = ft_strjoinc(*ret, n + 48);
	}
	return (*ret);
}

char				*ft_itoa_base(int nbr, char *base)
{
	int				len;
	char			*ret;

	len = ft_strlen(base);
	if (!(ret = ft_strnew(ft_nbrlen(1))))
		return (NULL);
	if (len <= 1 || (len != 10 && len != 2 && len != 16 && len != 8))
		return (NULL);
	else
	{
		if (check_base(base, len) != 0)
			return (NULL);
		else
			return (ft_itoa_b(&ret, nbr, base, len));
	}
}
