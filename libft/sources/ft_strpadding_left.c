/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpadding_left.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 14:50:56 by jmoucade          #+#    #+#             */
/*   Updated: 2016/12/11 08:05:16 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strpadding_left(char **str, int len_max)
{
	int			len;
	char		*new;
	char		*tmp;

	if (!*str)
		return (0);
	len = (int)ft_strlen(*str);
	if (len < len_max)
	{
		if (!(new = ft_strnew(len_max)))
			return (-1);
		new = ft_memset(new, ' ', len_max);
		tmp = new;
		new = ft_memrcpy(new, *str, len);
		if (*str)
			free(*str);
		*str = tmp;
		return (1);
	}
	return (0);
}
