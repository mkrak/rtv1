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
	scoef->load = malloc(sizeof(t_img));
}

void				new_image(t_coef *scoef)
{
	int		bpp;
	int		endian;

	scoef->img = mlx_new_image(scoef->mlx, W, H);
	scoef->data = mlx_get_data_addr(scoef->img, &bpp, &scoef->sl, &endian);
}

void				put_pixel(t_img s, int x, int y, t_point color)
{
	int	i = 0;

	if (x >= H / 8 || x < 0 || y >= W || y < 0)
		return ;

	i = ((H / 8 - x - 1) * W + y) * 4; 	
	color.posx = fmin(255, fmax(0, pow(color.posx, 1 / 2.2)));
	color.posy = fmin(255, fmax(0, pow(color.posy, 1 / 2.2)));
	color.posz = fmin(255, fmax(0, pow(color.posz, 1 / 2.2)));
	// if (color.posz > 0 && color.posz < 50)
	// 	color.posz = 25;
	// else if (color.posz >= 50 && color.posz < 100)
	// 	color.posz = 75;
	// else if (color.posz >= 100 && color.posz < 150)
	// 	color.posz = 125;
	// else if (color.posz >= 150 && color.posz < 200)
	// 	color.posz = 175;
	// else if (color.posz >= 200 && color.posz <= 255)
	// 	color.posz = 225;

	// if (color.posy > 0 && color.posy < 50)
	// 	color.posy = 25;
	// else if (color.posy >= 50 && color.posy < 100)
	// 	color.posy = 75;
	// else if (color.posy >= 100 && color.posy < 150)
	// 	color.posy = 125;
	// else if (color.posy >= 150 && color.posy < 200)
	// 	color.posy = 175;
	// else if (color.posy >= 200 && color.posy <= 255)
	// 	color.posy = 225;

	// if (color.posx > 0 && color.posx < 50)
	// 	color.posx = 25;
	// else if (color.posx >= 50 && color.posx < 100)
	// 	color.posx = 75;
	// else if (color.posx >= 100 && color.posx < 150)
	// 	color.posx = 125;
	// else if (color.posx >= 150 && color.posx < 200)
	// 	color.posx = 175;
	// else if (color.posx >= 200 && color.posx <= 255)
	// 	color.posx = 225;
	s.data[i] =  color.posz;
	s.data[++i] = color.posy;
	s.data[++i] = color.posx;

	// s->data[i] =  color.posz;
	// s->data[++i] = color.posy;
	// s->data[++i] = color.posx;
}

int					quit(void)
{
	exit(0);
}

int					main(int ac, char **av)
{
	t_control	lll;
	void		*menu_win;

	if (ac != 2 && av)
	{
		ft_putendl("Usage : ../rt [Scene valide]");
		return (-1);
	}
	lll.nb_obj = ft_atoi(av[1]);
	lll.nb_luz = 3; 
	lll.coef = (t_coef*)malloc(sizeof(t_coef));
	lll.l = (t_luz*)malloc(sizeof(t_luz) * 3);
	lll.obj = (t_obj*)malloc(sizeof(t_obj) * lll.nb_obj);
	init_struct(lll.coef);
	lll.coef->cur = 8;
	lll.coef->total = 8;
	menu_win = mlx_new_window(lll.coef->mlx, 250, 500, "Menu");
	fill_menu(lll.coef, menu_win);
	ft_logo(lll.coef);

	new_image(lll.coef);
	init_w(&lll);

	mlx_mouse_hook(menu_win, mouse_hook, &lll);
	mlx_mouse_hook(lll.coef->win, main_mouse_hook, &lll);
	mlx_key_hook(menu_win, ft_keyhook, &lll);

	mlx_key_hook(lll.coef->win, ft_keyhook, &lll);
	mlx_hook(lll.coef->win, 17, 0L, &quit, lll.coef);
	mlx_loop(lll.coef->mlx);
	return (0);
}
