/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 21:47:57 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/17 21:48:37 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void		expension(char **value, t_params *params)
{
	if (!value || !*value)
		return ;
	tilde_expension(value, params);
	param_expension(value, params);
}