/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_info_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 14:06:37 by cballest          #+#    #+#             */
/*   Updated: 2018/05/01 14:06:39 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	trace_info_3(t_control *l, int status)
{
	void	*img;
	int		w;
	int		h;
	t_img	bl;
	char	rot[2];

	bl.img = mlx_new_image(l->coef->mlx, 350, H);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, bl.img, W, 0);
	mlx_destroy_image(l->coef->mlx, bl.img);
	if (status == 0)
	{
		l->coef->posx = 0;
		l->coef->posy = 0;
		l->coef->posz = 0;
		l->coef->rotx = 0;
		l->coef->roty = 0;
		l->coef->rotz = 0;
		l->coef->strx = 0;
		l->coef->stry = 0;
		l->coef->strz = 0;
		l->coef->rad = 0;
		l->coef->r = 0;
		l->coef->g = 0;
		l->coef->b = 0;
		l->coef->type = 0;
		l->coef->axe = 'x';
		rot[0] = l->coef->axe;
		rot[1] = '\0';
	}
	if (status == 2)
	{
		l->coef->shape = l->obj[l->coef->cur].attr.id;
		l->coef->color.color = (int)l->obj[l->coef->cur].attr.color;
		l->coef->posx = (int)l->obj[l->coef->cur].attr.pos.x;
		l->coef->posy = (int)l->obj[l->coef->cur].attr.pos.y;
		l->coef->posz = (int)l->obj[l->coef->cur].attr.pos.z;
		l->coef->rotx = (int)l->obj[l->coef->cur].attr.rot.x;
		l->coef->roty = (int)l->obj[l->coef->cur].attr.rot.y;
		l->coef->rotz = (int)l->obj[l->coef->cur].attr.rot.z;
		l->coef->strx = (int)l->obj[l->coef->cur].attr.str.x * 100;
		l->coef->stry = (int)l->obj[l->coef->cur].attr.str.y * 100;
		l->coef->strz = (int)l->obj[l->coef->cur].attr.str.z * 100;
		l->coef->rad = (int)l->obj[l->coef->cur].attr.radius;
		l->coef->r = l->coef->color.c[0];
		l->coef->g = l->coef->color.c[1];
		l->coef->b = l->coef->color.c[2];
		l->coef->type = (int)l->obj[l->coef->cur].attr.type;
		l->coef->axe = l->obj[l->coef->cur].attr.axe;
		rot[0] = l->coef->axe;
		rot[1] = '\0';
	}
	img = mlx_xpm_file_to_image(l->coef->mlx, "ressources/img/ADD_BAR.XPM", &w,\
			&h);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 10);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 50);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 90);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 150);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 190);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 230);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 290);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 330);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 370);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 430);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 490);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 530);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 570);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 630);
	if (l->obj[l->coef->cur].attr.id != 0)
		mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 690);
	img = mlx_xpm_file_to_image(l->coef->mlx, "ressources/img/UPDATE.XPM", &w, \
			&h);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 750);
	mlx_string_put(l->coef->mlx, l->coef->win, W + 149, 25 - (OS * 9), \
			0x00000000, ft_itoa(l->coef->posx));
	mlx_string_put(l->coef->mlx, l->coef->win, W + 149, 65 - (OS * 9), \
			0x00000000, ft_itoa(l->coef->posy));
	mlx_string_put(l->coef->mlx, l->coef->win, W + 149, 105 - (OS * 9), \
			0x00000000, ft_itoa(l->coef->posz));
	mlx_string_put(l->coef->mlx, l->coef->win, W + 149, 165 - (OS * 9), \
			0x00000000, ft_itoa(l->coef->rotx));
	mlx_string_put(l->coef->mlx, l->coef->win, W + 149, 205 - (OS * 9), \
			0x00000000, ft_itoa(l->coef->roty));
	mlx_string_put(l->coef->mlx, l->coef->win, W + 149, 245 - (OS * 9), \
			0x00000000, ft_itoa(l->coef->rotz));
	mlx_string_put(l->coef->mlx, l->coef->win, W + 149, 305 - (OS * 9), \
			0x00000000, ft_itoa(l->coef->strx));
	mlx_string_put(l->coef->mlx, l->coef->win, W + 149, 345 - (OS * 9), \
			0x00000000, ft_itoa(l->coef->stry));
	mlx_string_put(l->coef->mlx, l->coef->win, W + 149, 385 - (OS * 9), \
			0x00000000, ft_itoa(l->coef->strz));
	mlx_string_put(l->coef->mlx, l->coef->win, W + 149, 445 - (OS * 9), \
			0x00000000, ft_itoa(l->coef->rad));
	mlx_string_put(l->coef->mlx, l->coef->win, W + 149, 505 - (OS * 9), \
			0x00000000, ft_itoa(l->coef->r));
	mlx_string_put(l->coef->mlx, l->coef->win, W + 149, 545 - (OS * 9), \
			0x00000000, ft_itoa(l->coef->g));
	mlx_string_put(l->coef->mlx, l->coef->win, W + 149, 585 - (OS * 9), \
			0x00000000, ft_itoa(l->coef->b));
	mlx_string_put(l->coef->mlx, l->coef->win, W + 149, 645 - (OS * 9), \
			0x00000000, ft_itoa(l->coef->type));
	if (l->coef->shape != 0)
		mlx_string_put(l->coef->mlx, l->coef->win, W + 149, 705 - (OS * 9), \
				0x00000000, rot);
	mlx_destroy_image(l->coef->mlx, img);
}

