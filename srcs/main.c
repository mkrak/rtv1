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
	int	i = 0;
	double	p;
	t_vec3 tmp;

if (x >= H / 8 || x < 0 || y >= W || y < 0)
		return ;

	i = ((H / 8 - x - 1) * W + y) * 4;
	if (!c->wtf)
	{
		color.x = fmin(255, fmax(0, pow(color.x, 1 / 2.2)));
		color.y = fmin(255, fmax(0, pow(color.y, 1 / 2.2)));
		color.z = fmin(255, fmax(0, pow(color.z, 1 / 2.2)));
	}
	if (c->cartoon == 1)
	{
		if (color.z > 0 && color.z < 50)
			color.z = 25;
		else if (color.z >= 50 && color.z < 100)
			color.z = 75;
		else if (color.z >= 100 && color.z < 150)
			color.z = 125;
		else if (color.z >= 150 && color.z < 200)
			color.z = 175;
		else if (color.z >= 200 && color.z <= 255)
			color.z = 225;
		if (color.y > 0 && color.y < 50)
			color.y = 25;
		else if (color.y >= 50 && color.y < 100)
			color.y = 75;
		else if (color.y >= 100 && color.y < 150)
			color.y = 125;
		else if (color.y >= 150 && color.y < 200)
			color.y = 175;
		else if (color.y >= 200 && color.y <= 255)
			color.y = 225;
		if (color.x > 0 && color.x < 50)
			color.x = 25;
		else if (color.x >= 50 && color.x < 100)
			color.x = 75;
		else if (color.x >= 100 && color.x < 150)
			color.x = 125;
		else if (color.x >= 150 && color.x < 200)
			color.x = 175;
		else if (color.x >= 200 && color.x <= 255)
			color.x = 225;
	}
	if (c->negatif == 1)
	{
		color.x = 255 - color.x;
		color.y = 255 - color.y;
		color.z = 255 - color.z;
	}
	if (c->bnw)
	{
		color.x = (color.z + color.y + color.z) / 3;
		color.y = color.x;
		color.z = color.x;
	}
	if(c->sepia)
	{
	tmp = color;
	color.x = fmin(255, fmax(0, ((tmp.x * 0.393) + (tmp.y * 0.769) + (tmp.z * 0.189)) + 15));
	color.y = fmin(255, fmax(0, ((tmp.x * 0.349) + (tmp.y * 0.686) + (tmp.z * 0.168)) + 5)); 
	color.z = fmin(255, fmax(0, ((tmp.x * 0.272) + (tmp.y * 0.534) + (tmp.z * 0.131)) - 5));
	}
	if (!c->wtf)
	{
		p = sqrt(color.x*color.x*0.299 + color.y*color.y*0.587 + color.z*color.z*0.114);
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
//	void		*menu_win;

	if (ac != 2 && av)
	{
		ft_putendl("Usage : ../rt [Scene valide]");
		return (-1);
	}
	lll.nb_obj = ft_atoi(av[1]);
	lll.nb_luz = 3; 
	lll.coef = (t_coef*)malloc(sizeof(t_coef));
	lll.l = (t_luz*)malloc(sizeof(t_luz) * lll.nb_luz);
	lll.obj = init_obj(lll.nb_obj);
//	lll.obj = (t_obj*)malloc(sizeof(t_obj) * lll.nb_obj);
	init_struct(lll.coef);
//	menu_win = mlx_new_window(lll.coef->mlx, 250, 500, "Menu");
//	fill_menu(lll.coef, menu_win);
	ft_logo(lll.coef);

	new_image(lll.coef);
	init_w(&lll);

//	mlx_mouse_hook(menu_win, mouse_hook, &lll);
	mlx_hook(lll.coef->win, 6, (1L<<6), main_mouse_hook_not, &lll);
	mlx_mouse_hook(lll.coef->win, main_mouse_hook, &lll);
//	mlx_key_hook(menu_win, ft_keyhook, &lll);
	lll.roll = 0;
	lll.rolr = 0;
	lll.rotl = 0;
	lll.rotr = 0;
	lll.rotu = 0;
	lll.rotd = 0;
	lll.au = 0;
	lll.ad = 0;
	lll.al = 0;
	lll.ar = 0;
	lll.ctrl = 0;
	lll.shif = 0;
	lll.kalisub = 0;
	lll.kaliadd = 0;
	lll.kaa = 0;
	trace_info(&lll);
	mlx_key_hook(lll.coef->win, ft_keyhook, &lll);
	mlx_hook(lll.coef->win, 2, (1L << 0), &key_p, &lll);
	mlx_hook(lll.coef->win, 3, (1L << 1), &key_r, &lll);
	mlx_hook(lll.coef->win, 17, 0L, &quit, lll.coef);
	mlx_loop_hook(lll.coef->mlx, main_loop, &lll);
	mlx_loop(lll.coef->mlx);
	return (0);
}
