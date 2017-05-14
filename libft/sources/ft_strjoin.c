/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:40:49 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/25 22:19:46 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;

	ptr = NULL;
	if (s1 && s2)
	{
		if ((ptr = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		{
			ptr = ft_strcpy(ptr, s1);
			ptr = ft_strcat(ptr, s2);
		}
	}
	return (ptr);
}
