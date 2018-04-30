/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*     rt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:02:30 by mkrakows          #+#    #+#             */
/*   Updated: 2018/04/27 17:12:48 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void				init_struct(t_coef *scoef)
{
	scoef->mlx = mlx_init();
	scoef->win = mlx_new_window(scoef->mlx, W + 350, H, "mlx 42");
	scoef->load = malloc(sizeof(t_img));
}

void				new_image(t_coef *scoef)
{
	int		bpp;
	int		endian;

	scoef->img = mlx_new_image(scoef->mlx, W, H);
	scoef->data = mlx_get_data_addr(scoef->img, &bpp, &scoef->sl, &endian);
}

void				put_pixel(t_img s, int x, int y, t_vec3 color, t_coef *c)
{
	int		i;
	double	p;

	i = 0;
	if (x >= H / 8 || x < 0 || y >= W || y < 0)
		return ;
	i = ((H / 8 - x - 1) * W + y) * 4;
	if (!c->wtf)
		borne(&color);
	if (c->cartoon == 1)
		cartoon(&color);
	if (c->negatif == 1)
		negatif(&color);
	if (c->bnw)
		black_n_white(&color);
	if (c->sepia)
		sepia(&color);
	if (!c->wtf)
	{
		p = sqrt(color.x * color.x * 0.299 + color.y * color.y * 0.587 + \
			color.z * color.z * 0.114);
		s.data[i] = fmin(fmax((p + (color.z - p) * c->sat / 100) + c->lum, 0), 255);
		s.data[++i] = fmin(fmax((p + (color.y - p) * c->sat / 100) + c->lum, 0), 255);
		s.data[++i] = fmin(fmax((p + (color.x - p) * c->sat / 100) + c->lum, 0), 255);
	}
	else
	{
		s.data[i] = color.z;
		s.data[++i] = color.y;
		s.data[++i] = color.x;
	}
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
		ft_putendl("Usage : ../rt [Scene valide]");
		return (-1);
	}
	lll.nb_obj = ft_atoi(av[1]);
	lll.nb_luz = 1;
	lll.coef = (t_coef*)malloc(sizeof(t_coef));
	lll.l = (t_luz*)malloc(sizeof(t_luz) * lll.nb_luz);
	lll.obj = init_obj(lll.nb_obj);
	init_struct(lll.coef);
	ft_logo(lll.coef);
	new_image(lll.coef);
	init_w(&lll);
	mlx_hook(lll.coef->win, 6, (1L << 6), main_mouse_hook_not, &lll);
	mlx_mouse_hook(lll.coef->win, main_mouse_hook, &lll);
	init_mouv(&lll);
	trace_info(&lll);
	mlx_key_hook(lll.coef->win, ft_keyhook, &lll);
	mlx_hook(lll.coef->win, 2, (1L << 0), &key_p, &lll);
	mlx_hook(lll.coef->win, 3, (1L << 1), &key_r, &lll);
	mlx_hook(lll.coef->win, 17, 0L, &quit, lll.coef);
	mlx_loop_hook(lll.coef->mlx, main_loop, &lll);
	mlx_loop(lll.coef->mlx);
	return (0);
}
