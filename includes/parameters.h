/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 18:02:46 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/19 09:26:32 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETERS_H
# define PARAMETERS_H

# include <libft.h>
# include <ft_types.h>

void	init_parameters(t_params *parameters, char **environment);
t_list	*import_env(char **env);
char	**export_env(t_list *env);
int		set_param(t_list **params, char *value);
char	*get_param(t_list *param, char *key);
void 	print_all_params(t_params *params);
void 	print_param_all(t_list *param);
void	print_param(t_list *param);

#endif