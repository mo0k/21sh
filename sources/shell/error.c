/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 00:52:06 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/11 20:19:18 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_21sh.h>

void		ft_fatal(char *error)
{
	char	error_message[100];

	ft_bzero(error_message, 100);
	ft_strcpy(error_message, "[!!] Fatal Error ");
	ft_strncat(error_message, error, 83);
	ft_putendl_fd(error_message, 2);
	exit(EXIT_FAILURE);
}

void		ft_error(char *error)
{
	char	error_message[100];

	ft_bzero(error_message, 100);
	ft_strcpy(error_message, "[!!] Error ");
	ft_strncat(error_message, error, 89);
	ft_putendl_fd(error_message, 2);
}

void		ft_shell_error(char *error)
{
	char	error_message[100];

	ft_bzero(error_message, 100);
	ft_strcpy(error_message, "21sh: ");
	ft_strncat(error_message, error, 94);
	ft_putendl_fd(error_message, 2);
}