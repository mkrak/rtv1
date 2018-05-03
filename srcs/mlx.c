/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 15:26:02 by cballest          #+#    #+#             */
/*   Updated: 2018/05/01 15:26:05 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	put_pixel_circle(t_img i, t_circle c, int x, int y)
{
	int		n;

	if (x >= (c.r * 2) || x < 0 || y >= (c.r * 2) || y < 0)
		return ;
	n = ((c.r * 2 - x - 1) * (c.r * 2) + y) * 4;
	i.data[n] = c.c.c[0];
	i.data[++n] = c.c.c[1];
	i.data[++n] = c.c.c[2];
	i.data[++n] = c.c.c[3];
}

void	mlx_image_to_alpha(t_img img, int n)
{
	int		i;

	i = 3;
	while (i <= n)
	{
		img.data[i] = 0xff;
		i += 4;
	}
}

void	put_pixel_rect(t_img i, t_rect r, int x, int y)
{
	int		n;

	if (x >= r.h || x < 0 || y >= r.w || y < 0)
		return ;
	n = ((r.h - x - 1) * r.w + y) * 4;
	i.data[n] = r.c.c[0];
	i.data[++n] = r.c.c[1];
	i.data[++n] = r.c.c[2];
}

void	mlx_rect(t_rect rect, t_coef *coef)
{
	t_img	img;
	int		x;
	int		y;

	img.img = mlx_new_image(coef->mlx, rect.w, rect.h);
	img.data = mlx_get_data_addr(img.img, &img.bpp, &img.sl, &img.end);
	y = 0;
	while (y <= rect.h)
	{
		x = 0;
		while (x <= rect.w)
		{
			if ((x >= 0 && x <= rect.border) ||
				(x <= rect.w && x >= rect.w - rect.border))
				put_pixel_rect(img, rect, y, x);
			if ((y >= 0 && y <= rect.border) ||
				(y <= rect.h && y >= rect.h - rect.border))
				put_pixel_rect(img, rect, y, x);
			if (rect.type == 1)
				put_pixel_rect(img, rect, y, x);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(coef->mlx, coef->win, img.img, rect.x, rect.y);
	mlx_destroy_image(coef->mlx, img.img);
}

void	mlx_scroll_bar(t_scrol s, t_coef *coef)
{
	t_rect	rect;

	rect = s.bar;
	if (s.id == 0)
		s.value = coef->sat;
	if (s.id == 1)
		s.value = coef->lum;
	s.bar.c.color = s.c2.color;
	mlx_rect(s.bar, coef);
	if (s.id == 0)
		rect.w = s.value * s.bar.w / 100;
	if (s.id == 1)
		rect.w = (s.value + 255) * s.bar.w / 510;
	rect.c.color = s.c1.color;
	mlx_rect(rect, coef);
	if (s.id == 0)
		s.cir.x = s.bar.x + (s.bar.w * s.value / 100);
	if (s.id == 1)
		s.cir.x = s.bar.x + (s.bar.w * (s.value + 255) / 510);
	s.cir.y = s.bar.y + 1;
	s.cir.r = 5;
	s.cir.c.color = s.c1.color;
	mlx_circle(s.cir, coef);
}
