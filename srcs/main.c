/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:54:08 by cballest          #+#    #+#             */
/*   Updated: 2018/05/02 21:02:49 by lgautier         ###   ########.fr       */
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
	t_obj		*pd;
	t_control	lll;

	if (ac != 2)
		exit_error(ERR_USAGE);
	if (!(file = get_file(av[1])))
		exit_error(ERR_FILE);
	lll.nb_luz = 1;
	lll.coef = (t_coef*)malloc(sizeof(t_coef));
	lll.l = (t_luz*)malloc(sizeof(t_luz) * lll.nb_luz);
	lll.obj = handle_scene(file);
	lll.nb_obj = get_n_obj(&(lll.obj));
	init_struct(lll.coef);
	ft_logo(lll.coef);
	new_image(lll.coef);
	init_w(&lll);
	mlx_hook(lll.coef->win, 6, (1L << 6), main_mouse_hook_not, &lll);
	mlx_mouse_hook(lll.coef->win, main_mouse_hook, &lll);
	init_mouv(&lll);
	trace_info(&lll);
	mlx_hook(lll.coef->win, 2, (1L << 0), &key_p, &lll);
	mlx_hook(lll.coef->win, 3, (1L << 1), &key_r, &lll);
	mlx_hook(lll.coef->win, 17, 0L, &quit, lll.coef);
	mlx_loop_hook(lll.coef->mlx, main_loop, &lll);
	mlx_loop(lll.coef->mlx);
	return (0);
}
