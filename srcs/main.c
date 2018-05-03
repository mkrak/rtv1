/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:54:08 by cballest          #+#    #+#             */
/*   Updated: 2018/05/03 19:09:42 by cballest         ###   ########.fr       */
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

void				put_pixel(t_img s, t_pxl p, t_vec3 color, t_coef *c)
{
	int		i;
	double	q;

	i = 0;
	if (p.x >= H / 8 || p.x < 0 || p.y >= W || p.y < 0)
		return ;
	i = ((H / 8 - p.x - 1) * W + p.y) * 4;
	filtre(c, &color);
	if (!c->wtf)
	{
		q = sqrt(color.x * color.x * 0.299 + color.y * color.y * 0.587 + \
			color.z * color.z * 0.114);
		s.data[i] = fmin(fmax((q + (color.z - q) * c->sat / 100) \
			+ c->lum, 0), 255);
		s.data[++i] = fmin(fmax((q + (color.y - q) * c->sat / 100) \
			+ c->lum, 0), 255);
		s.data[++i] = fmin(fmax((q + (color.x - q) * c->sat / 100) \
			+ c->lum, 0), 255);
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
	char		*file;
	t_control	lll;

	file = NULL;
	if (main_mallocs(&lll, ac, file, av) != 1)
		return (EXIT_FAILURE);
	get_n_obj(&(lll.obj), &(lll.nb_obj), &(lll.nb_luz));
	init_struct(lll.coef);
	ft_logo(lll.coef);
	new_image(lll.coef);
	init_w(&lll);
	init_mouv(&lll);
	lll.coef->menu_state = 0;
	trace_info(&lll);
	hooks(lll);
	free(lll.coef);
	free(lll.l);
	free_object(lll.obj);
	return (0);
}
