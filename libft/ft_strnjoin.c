/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 20:00:49 by clanier           #+#    #+#             */
/*   Updated: 2018/05/03 20:01:14 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strnjoin(void *dst, const void *src, uint64_t n)
{
	uint64_t	len;
	char		*tmp;

	if (!dst)
	{
		if (!(dst = malloc(n + 1)))
			return (NULL);
		ft_memcpy(dst, src, n);
		tmp = dst;
		tmp[n] = 0;
		return (dst);
	}
	len = ft_strlen(dst);
	if (!(tmp = malloc(len)))
		return (NULL);
	ft_memcpy(tmp, dst, len);
	free(dst);
	if (!(dst = malloc(n + len + 1)))
		return (NULL);
	ft_memcpy(dst, tmp, len);
	ft_memcpy(dst + len, src, n);
	free(tmp);
	tmp = dst;
	tmp[n + len] = 0;
	return (dst);
}
