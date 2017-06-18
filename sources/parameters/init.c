/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 18:02:23 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/17 22:54:32 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parameters.h>

void	init_parameters(t_params *parameters, char **env)
{
	if (!parameters)
		exit(EXIT_FAILURE);
	if (!(parameters->environment = import_env(env)))
		exit(EXIT_FAILURE);
	parameters->temporary = NULL;
}