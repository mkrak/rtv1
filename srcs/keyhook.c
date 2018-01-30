/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    rt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:40:56 by mkrakows          #+#    #+#             */
/*   Updated: 2017/04/13 22:00:46 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int					ft_keyhook(int key, t_control *e)
{
	if (key == 53)
	{
		mlx_destroy_image(e->coef->mlx, e->coef->img);
		free(e->coef);
		free(e->r);
		free(e->s);
		free(e->p);
		exit(EXIT_SUCCESS);
	}
	else
		return (0);
	return (0);
}