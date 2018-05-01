/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_info_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 14:06:33 by cballest          #+#    #+#             */
/*   Updated: 2018/05/01 14:06:35 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void				trace_info_2(t_control *c)
{
	t_img	img;
	t_img	bl;

	bl.img = mlx_new_image(c->coef->mlx, 350, H);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, bl.img, W, 0);
	mlx_destroy_image(c->coef->mlx, bl.img);
	img.img = mlx_xpm_file_to_image(c->coef->mlx, \
			"ressources/img/SPHERE.XPM", &img.w, &img.h);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, img.img, W + 45, 15);
	img.img = mlx_xpm_file_to_image(c->coef->mlx, \
			"ressources/img/PLAN.XPM", &img.w, &img.h);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, \
			img.img, W + 45, 15 + 85);
	img.img = mlx_xpm_file_to_image(c->coef->mlx, \
			"ressources/img/CYLINDRE.XPM", &img.w, &img.h);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, \
			img.img, W + 45, 15 + 85 * 2);
	img.img = mlx_xpm_file_to_image(c->coef->mlx, \
			"ressources/img/CONE.XPM", &img.w, &img.h);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, \
			img.img, W + 45, 15 + 85 * 3);
}
