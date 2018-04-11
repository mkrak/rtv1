/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    rt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:40:56 by mkrakows          #+#    #+#             */
/*   Updated: 2018/04/03 16:10:27 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void				trace_info(t_control *c)
{
	t_img	img;
	t_rect	rect;
	t_scrol	scroll;
	float	f;
	char	s[255];
	int		h;
	int		col;
	void	*bouton;
	int		width;
	int		height;

	scroll.bar.x = W + 45;
	scroll.bar.y = 450;
	scroll.bar.w = 165;
	scroll.bar.h = 2;
	scroll.bar.type = 0;
	scroll.bar.border = 1;
	scroll.c1.color = 0x0000b0b2;
	scroll.c2.color = 0x00002324;
	scroll.value = 35;
	scroll.id = 0;
	rect.x = W + 45;
	rect.y = 25;
	rect.w = 165;
	rect.h = 320;
	rect.type = 0;
	rect.border = 1;
	rect.c.color = 0x0000b0b2;
	h = 0;
	col = 0x00ffffff;
	f = (float)(c->coef->time - c->coef->prev_time) / 1000000;
	ftoa(f, s, 4);
	img.img = mlx_new_image(c->coef->mlx, 250, H);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, img.img, W, 0);
	mlx_destroy_image(c->coef->mlx, img.img);
	mlx_rect(rect, c->coef);
	bouton = mlx_xpm_file_to_image(c->coef->mlx, "ressources/img/add_filter_norm.XPM", &width, &height);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, bouton, W + 45, 360);
	bouton = mlx_xpm_file_to_image(c->coef->mlx, "ressources/img/add_obj_norm.XPM", &width, &height);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, bouton, W + 45, 390);
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, h += 40, col, "    Scene");
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, h += 15, col, ft_strjoin("Width             : ", ft_itoa(W)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, h += 15, col, ft_strjoin("Height            : ", ft_itoa(H)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, h += 15, col, ft_strjoin("Aliasing     (+/-): ", ft_itoa(c->aliasing)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, h += 15, col, ft_strjoin("Anti-aliasing  (P): ", ft_itoa(c->antial)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, h += 15, col, ft_strjoin("Cartoon        (C): ", ft_itoa(c->coef->cartoon)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, h += 15, col, ft_strjoin("Negatif        (N): ", ft_itoa(c->coef->negatif)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, h += 15, col, ft_strjoin("WTF            (X): ", ft_itoa(c->coef->wtf)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, h += 15, col, ft_strjoin("Time (in sec)     : ", s));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, h += 25, col, "    Camera");
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, h += 15, col, ft_strjoin("Pos X      (AU/AD): ", ft_itoa(c->coef->pos_x)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, h += 15, col, ft_strjoin("Pos Y      (AL/AR): ", ft_itoa(c->coef->pos_y)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, h += 15, col, ft_strjoin("Pos Z (CTRL/SHIFT): ", ft_itoa(c->coef->pos_z)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, h += 20, col, ft_strjoin("Rot X        (A/D): ", ft_itoa(c->coef->rot_x)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, h += 15, col, ft_strjoin("Rot Y        (W/S): ", ft_itoa(c->coef->rot_y)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, h += 15, col, ft_strjoin("Rot Z        (Q/E): ", ft_itoa(c->coef->rot_z)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, h += 25, col, "    Objets");
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, h += 15, col, ft_strjoin("Spheres           : ", ft_itoa(c->nb_obj)));
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, h += 15, col, ft_strjoin("Lumieres          : ", ft_itoa(c->nb_luz)));
	mlx_scroll_bar(scroll, c->coef);
}

int					ft_keyhook(int key, t_control *e)
{
//	if (key == K_ESC)
//	{
//		mlx_destroy_image(e->coef->mlx, e->coef->img);
//		free(e->coef);
//		free(e->obj);
//		free(e->l);
//		exit(EXIT_SUCCESS);
//	}
//	if ((!OS && key == K_W) || (OS && key == K_Z))
//		rename_win(e);
//	if (ft_key_aa(key, e))
//		multithread(e);
//	if (ft_key_camtrans(key, e))
//		multithread(e);
//	if (ft_key_camrot(key, e))
//		multithread(e);
	if (key == K_C)
	{
		if (e->coef->cartoon == 0)
			e->coef->cartoon = 1;
		else
			e->coef->cartoon = 0;
		multithread(e);
	}
	if (key == K_X)
	{
		if (e->coef->wtf == 0)
			e->coef->wtf = 1;
		else
			e->coef->wtf = 0;
		multithread(e);
	}
	trace_info(e);
	return (0);
}

int		ft_key_aa(t_control *e)
{
	if (e->kalisub)
	{
		if (e->aliasing > 1)
			e->aliasing -= 1;
		else
		{
			e->aliasing = 1;
			return (0);
		}
	}
	else if (e->kaliadd)
		e->aliasing += 1;
	else if (e->kaa)
	{
		if (e->antial == 1)
			e->antial *= 4;
		else
			e->antial = 1;
	}
	else
		return (0);
	return (1);
}

int		ft_key_camrot(t_control *e)
{
	if (e->roll)
		e->coef->rot_z += 5;
	else if (e->rolr)
		e->coef->rot_z -= 5;
	else if (e->rotr)
		e->coef->rot_x += 50;
	else if (e->rotl)
		e->coef->rot_x -= 50;
	else if (e->rotu)
		e->coef->rot_y += 50;
	else if (e->rotd)
		e->coef->rot_y -= 50;
	else
		return (0);
	return (1);
}

int		ft_key_camtrans(t_control *e)
{
	if (e->au)
		e->coef->pos_x -= 1;
	if (e->ad)
		e->coef->pos_x += 1;
	if (e->ctrl)
		e->coef->pos_z -= 1;
	if (e->shif)
		e->coef->pos_z += 1;
	if (e->al)
		e->coef->pos_y -= 1;
	if (e->ar)
		e->coef->pos_y += 1;
	if (!e->au && !e->ad && !e->ctrl && !e->shif && !e->al && !e->ar)
		return (0);
	return (1);
}
