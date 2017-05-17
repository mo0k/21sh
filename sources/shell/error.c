/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 00:52:06 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/17 05:01:08 by jmoucade         ###   ########.fr       */
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
