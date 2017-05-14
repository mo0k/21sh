/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:39:30 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/23 20:25:43 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	int		ct;
	char	*ptr;

	ct = 0;
	ptr = NULL;
	if (!src)
		return (NULL);
	if (!(ptr = (char*)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (NULL);
	while (src[ct])
	{
		ptr[ct] = src[ct];
		ct++;
	}
	ptr[ct] = '\0';
	return (ptr);
}
