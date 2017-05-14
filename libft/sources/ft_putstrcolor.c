/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrcolor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 23:40:02 by mo0ky             #+#    #+#             */
/*   Updated: 2017/03/16 00:07:01 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstrcolor(const char *str, char *color)
{
	if (!str)
		return ;
	ft_putstr(color);
	write(1, str, (int)ft_strlen(str));
	ft_putstr(C_DFL);
}