/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*     rt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:02:30 by mkrakows          #+#    #+#             */
/*   Updated: 2017/04/13 21:47:35 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void				init_struct(t_coef *scoef)
{
	scoef->mlx = mlx_init();
	scoef->win = mlx_new_window(scoef->mlx, W, H, "mlx 42");
}

void				new_image(t_coef *scoef)
{
	int		bpp;
	int		endian;

	scoef->img = mlx_new_image(scoef->mlx, W, H);
	scoef->data = mlx_get_data_addr(scoef->img, &bpp, &scoef->sl, &endian);
}

void				put_pixel(t_coef *s, int x, int y, t_point color)
{
	int	i = 0;

	if (x >= H || x < 0 || y >= W || y < 0)
		return ;

	i = ((H - x - 1) * W + y) * 4; 	
	color.posx = fmin(255, fmax(0, pow(color.posx, 1 / 2.2)));
	color.posy = fmin(255, fmax(0, pow(color.posy, 1 / 2.2)));
	color.posz = fmin(255, fmax(0, pow(color.posz, 1 / 2.2)));
	// color.posx = fmin(255, fmax(0, color.posx));
	// color.posy = fmin(255, fmax(0, color.posy));
	// color.posz = fmin(255, fmax(0, color.posz));

	s->data[i] =  color.posz;
	s->data[++i] = color.posy;
	s->data[++i] = color.posx;
}

int					quit(void)
{
	exit(0);
}

int					main(int ac, char **av)
{
	t_control	lll;

	if (ac != 2 && av)
	{
		ft_putendl("Usage : ../wolf3d [map valide]");
		return (-1);
	}
	lll.av = ft_atoi(av[1]);
	lll.r = (t_ray*)malloc(sizeof(t_ray));
	lll.coef = (t_coef*)malloc(sizeof(t_coef));
	lll.l = (t_luz*)malloc(sizeof(t_luz));
	lll.obj = (t_obj*)malloc(sizeof(t_obj) * lll.av);
	init_struct(lll.coef);
	new_image(lll.coef);

	init_w(&lll);
	mlx_key_hook(lll.coef->win, ft_keyhook, &lll);
	mlx_hook(lll.coef->win, 17, 0L, &quit, lll.coef);
	mlx_loop(lll.coef->mlx);
	return (0);
}
