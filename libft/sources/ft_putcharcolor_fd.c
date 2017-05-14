/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharcolor_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 23:42:12 by mo0ky             #+#    #+#             */
/*   Updated: 2017/03/16 00:06:26 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putcharcolor_fd(char c, int fd, char *color)
{
	if (fd < 0)
		return ;
	ft_putstr_fd(color, fd);
	write(fd, &c, 1);
	ft_putstr_fd(C_DFL, fd);
}