/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharcolor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 23:41:50 by mo0ky             #+#    #+#             */
/*   Updated: 2017/03/16 00:06:28 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putcharcolor(char c, char *color)
{
	ft_putstr(color);
	write(1, (unsigned char *)(&c), 1);
	ft_putstr(C_DFL);
}