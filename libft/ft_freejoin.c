/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freejoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 01:45:05 by clanier           #+#    #+#             */
/*   Updated: 2018/05/03 22:10:50 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_freejoin(char *dst, char *src)
{
	if ((dst = ft_strjoin(dst, src)) == NULL)
		return (NULL);
	ft_strdel(&src);
	return (dst);
}
