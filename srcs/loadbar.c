/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadbar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 13:49:49 by cballest          #+#    #+#             */
/*   Updated: 2018/05/01 13:49:51 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		fill_img(char *data, int w, int h, t_col color)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			i = ((h - y - 1) * w + x) * 4;
			data[i] = color.c[0];
			data[++i] = color.c[1];
			data[++i] = color.c[2];
			x++;
		}
		y++;
	}
}

void		ft_loadbar(t_coef *t, int n)
{
	t_col	color1;
	t_col	color2;

	color1.color = 0x00000000;
	color2.color = 0x00ff0000;
	if (n <= 10)
	{
		t->load->img = mlx_new_image(t->mlx, W, 10);
		t->load->data = mlx_get_data_addr(t->load->img, &t->load->bpp, \
				&t->load->sl, &t->load->end);
		fill_img(t->load->data, W, 10, color1);
		mlx_put_image_to_window(t->mlx, t->win, t->load->img, 0, H - 10);
		mlx_destroy_image(t->mlx, t->load->img);
	}
	t->load->img = mlx_new_image(t->mlx, n * (W + 250) / H, 10);
	t->load->data = mlx_get_data_addr(t->load->img, &t->load->bpp, \
			&t->load->sl, &t->load->end);
	fill_img(t->load->data, n * (W + 250) / H, 10, color2);
	mlx_put_image_to_window(t->mlx, t->win, t->load->img, 0, H - 10);
	mlx_destroy_image(t->mlx, t->load->img);
}
