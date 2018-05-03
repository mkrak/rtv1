/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 15:35:54 by cballest          #+#    #+#             */
/*   Updated: 2018/05/01 15:36:04 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	mlx_circle_1(t_circle c, t_img img, int i, int j)
{
	put_pixel_circle(img, c, c.r + j, c.r + i);
	put_pixel_circle(img, c, c.r + i, c.r + j);
	put_pixel_circle(img, c, c.r - j, c.r + i);
	put_pixel_circle(img, c, c.r - i, c.r + j);
	put_pixel_circle(img, c, c.r + j, c.r - i);
	put_pixel_circle(img, c, c.r + i, c.r - j);
	put_pixel_circle(img, c, c.r - j, c.r - i);
	put_pixel_circle(img, c, c.r - i, c.r - j);
}

void	mlx_circle_2(t_circle c, t_img img, int d)
{
	int			i;
	int			j;

	i = 0;
	j = c.r;
	while (j >= i)
	{
		mlx_circle_1(c, img, i, j);
		if (d >= 2 * i)
		{
			d -= 2 * i + 1;
			i++;
		}
		else if (d < 2 * (c.r - j))
		{
			d += 2 * j - 1;
			j--;
		}
		else
		{
			d += 2 * (j - i - 1);
			j--;
			i++;
		}
	}
}

void	mlx_circle(t_circle c, t_coef *coef)
{
	t_img		img;
	int			d;

	d = c.r - 1;
	img.img = mlx_new_image(coef->mlx, (c.r * 2), (c.r * 2));
	img.data = mlx_get_data_addr(img.img, &img.bpp, &img.sl, &img.end);
	mlx_circle_2(c, img, d);
	mlx_put_image_to_window(coef->mlx, coef->win, img.img, \
		c.x - c.r, c.y - c.r);
	mlx_destroy_image(coef->mlx, img.img);
}
