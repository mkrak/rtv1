/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    rt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:40:56 by mkrakows          #+#    #+#             */
/*   Updated: 2018/04/27 17:17:04 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void				trace_info_0(t_control *c)
{
	t_img	img;
	t_rect	rect;
	float	f;
	char	s[255];
	int		h;
	int		col;
	void	*bouton;
	int		width;
	int		height;
	rect.x = W + 45;
	rect.y = 25;
	rect.w = 275;
	rect.h = 320;
	rect.type = 0;
	rect.border = 1;
	rect.c.color = 0x0000b0b2;
	h = 0;
	col = 0x00ffffff;
	f = (float)(c->coef->time - c->coef->prev_time) / 1000000;
	ftoa(f, s, 4);
	img.img = mlx_new_image(c->coef->mlx, 350, H);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, img.img, W, 0);
	mlx_destroy_image(c->coef->mlx, img.img);
	mlx_rect(rect, c->coef);
	bouton = mlx_xpm_file_to_image(c->coef->mlx, "ressources/img/menu_0/add_filter_norm.XPM", &width, &height);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, bouton, W + 45, 360);
	bouton = mlx_xpm_file_to_image(c->coef->mlx, "ressources/img/menu_0/add_obj_norm.XPM", &width, &height);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, bouton, W + 45, 400);
	mlx_string_put(c->coef->mlx, c->coef->win, W + 50, h += 25, col, "    Scene");
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
}

void				trace_info_1(t_control *c)
{
	t_img		bouton;
	t_img		img;
	t_scrol		lum;
	t_scrol		scroll;
	int			n;

	n = 0;
	lum.bar.x = W + 45;
	lum.bar.w = 275;
	lum.bar.h = 2;
	lum.bar.type = 0;
	lum.bar.border = 1;
	lum.c1.color = 0x0000b0b2;
	lum.c2.color = 0x00002324;
	lum.value = 15;
	lum.id = 1;

	scroll.bar.x = W + 45;
	scroll.bar.w = 275;
	scroll.bar.h = 2;
	scroll.bar.type = 0;
	scroll.bar.border = 1;
	scroll.c1.color = 0x0000b0b2;
	scroll.c2.color = 0x00002324;
	scroll.value = 35;
	scroll.id = 0;
	img.img = mlx_new_image(c->coef->mlx, 350, H);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, img.img, W, 0);
	mlx_destroy_image(c->coef->mlx, img.img);
	bouton.img = mlx_xpm_file_to_image(c->coef->mlx, "ressources/img/menu_1/title.XPM", &bouton.w, &bouton.h);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, bouton.img, W + 45, n + 25);
	bouton.img = mlx_xpm_file_to_image(c->coef->mlx, "ressources/img/menu_1/back.XPM", &bouton.w, &bouton.h);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, bouton.img, W + 45, n += 25);
	if (c->coef->negatif == 0)
		bouton.img = mlx_xpm_file_to_image(c->coef->mlx, "ressources/img/menu_1/neg/norm_0.XPM", &bouton.w, &bouton.h);
	else
		bouton.img = mlx_xpm_file_to_image(c->coef->mlx, "ressources/img/menu_1/neg/norm_1.XPM", &bouton.w, &bouton.h);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, bouton.img, W + 45, n += 35);
	if (c->coef->sepia == 0)
		bouton.img = mlx_xpm_file_to_image(c->coef->mlx, "ressources/img/menu_1/sepia/norm_0.XPM", &bouton.w, &bouton.h);
	else
		bouton.img = mlx_xpm_file_to_image(c->coef->mlx, "ressources/img/menu_1/sepia/norm_1.XPM", &bouton.w, &bouton.h);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, bouton.img, W + 45, n += 35);
	if (c->coef->cartoon == 0)
		bouton.img = mlx_xpm_file_to_image(c->coef->mlx, "ressources/img/menu_1/cartoon/norm_0.XPM", &bouton.w, &bouton.h);
	else
		bouton.img = mlx_xpm_file_to_image(c->coef->mlx, "ressources/img/menu_1/cartoon/norm_1.XPM", &bouton.w, &bouton.h);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, bouton.img, W + 45, n += 35);
	if (c->coef->wtf == 0)
		bouton.img = mlx_xpm_file_to_image(c->coef->mlx, "ressources/img/menu_1/wtf/norm_0.XPM", &bouton.w, &bouton.h);
	else
		bouton.img = mlx_xpm_file_to_image(c->coef->mlx, "ressources/img/menu_1/wtf/norm_1.XPM", &bouton.w, &bouton.h);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, bouton.img, W + 45, n += 35);
	bouton.img = mlx_xpm_file_to_image(c->coef->mlx, "ressources/img/menu_1/sat/img.XPM", &bouton.w, &bouton.h);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, bouton.img, W + 45, n += 35);
	scroll.bar.y = n += 45;
	mlx_scroll_bar(scroll, c->coef);
	bouton.img = mlx_xpm_file_to_image(c->coef->mlx, "ressources/img/menu_1/lum/img.XPM", &bouton.w, &bouton.h);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, bouton.img, W + 45, n += 25);
	lum.bar.y = n += 45;
	mlx_scroll_bar(lum, c->coef);
}

void				trace_info_2(t_control *c)
{

	t_img 	img;
	t_img 	bl;

	bl.img = mlx_new_image(c->coef->mlx, 350, H);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, bl.img, W, 0);
	mlx_destroy_image(c->coef->mlx, bl.img);
	img.img = mlx_xpm_file_to_image(c->coef->mlx, "ressources/img/SPHERE.XPM", &img.w, &img.h);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, img.img, W + 45, 15);
	img.img = mlx_xpm_file_to_image(c->coef->mlx, "ressources/img/PLAN.XPM", &img.w, &img.h);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, img.img, W + 45, 15 + 85);
	img.img = mlx_xpm_file_to_image(c->coef->mlx, "ressources/img/CYLINDRE.XPM", &img.w, &img.h);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, img.img, W + 45, 15 + 85 * 2);
	img.img = mlx_xpm_file_to_image(c->coef->mlx, "ressources/img/CONE.XPM", &img.w, &img.h);
	mlx_put_image_to_window(c->coef->mlx, c->coef->win, img.img, W + 45, 15 + 85 * 3);
}

void	trace_info_3(t_control *l, int status)
{
	void	*img;
	int		w;
	int		h;
	t_img 	bl;
	char	rot[2];

	bl.img = mlx_new_image(l->coef->mlx, 350, H);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, bl.img, W, 0);
	mlx_destroy_image(l->coef->mlx, bl.img);
	if (status == 0)
	{
			l->coef->posx = 0;
			l->coef->posy = 0;
			l->coef->posz = 0;
			l->coef->rotx = 0;
			l->coef->roty = 0;
			l->coef->rotz = 0;
			l->coef->strx = 0;
			l->coef->stry = 0;
			l->coef->strz = 0;
			l->coef->rad = 0;
			l->coef->r = 0;
			l->coef->g = 0;
			l->coef->b = 0;
			l->coef->type = 0;
			l->coef->axe = 'x';
			rot[0] = l->coef->axe;
			rot[1] = '\0';
	}
	if (status == 2)
	{
			l->coef->shape = l->obj[l->coef->cur].attr.id;
			l->coef->color.color = (int)l->obj[l->coef->cur].attr.color;
			l->coef->posx = (int)l->obj[l->coef->cur].attr.pos.x;
			l->coef->posy = (int)l->obj[l->coef->cur].attr.pos.y;
			l->coef->posz = (int)l->obj[l->coef->cur].attr.pos.z;
			l->coef->rotx = (int)l->obj[l->coef->cur].attr.rot.x;
			l->coef->roty = (int)l->obj[l->coef->cur].attr.rot.y;
			l->coef->rotz = (int)l->obj[l->coef->cur].attr.rot.z;
			l->coef->strx = (int)l->obj[l->coef->cur].attr.str.x * 100;
			l->coef->stry = (int)l->obj[l->coef->cur].attr.str.y * 100;
			l->coef->strz = (int)l->obj[l->coef->cur].attr.str.z * 100;
			l->coef->rad = (int)l->obj[l->coef->cur].attr.radius;
			l->coef->r = l->coef->color.c[0];
			l->coef->g = l->coef->color.c[1];
			l->coef->b = l->coef->color.c[2];
			l->coef->type = (int)l->obj[l->coef->cur].attr.type;
			l->coef->axe = l->obj[l->coef->cur].attr.axe;
			rot[0] = l->coef->axe;
			rot[1] = '\0';
	}
	img = mlx_xpm_file_to_image(l->coef->mlx, "ressources/img/ADD_BAR.XPM", &w, &h);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 10);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 50);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 90);

	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 150);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 190);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 230);

	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 290);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 330);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 370);

	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 430);

	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 490);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 530);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 570);

	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 630);
	if (l->obj[l->coef->cur].attr.id != 0)
		mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 690);
	img = mlx_xpm_file_to_image(l->coef->mlx, "ressources/img/UPDATE.XPM", &w, &h);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 750);

	mlx_string_put(l->coef->mlx, l->coef->win, (W + 45) + 109, 10 + 15 - (OS * 9), 0x00000000, ft_itoa(l->coef->posx));
	mlx_string_put(l->coef->mlx, l->coef->win, (W + 45) + 109, 50 + 15 - (OS * 9), 0x00000000, ft_itoa(l->coef->posy));
	mlx_string_put(l->coef->mlx, l->coef->win, (W + 45) + 109, 90 + 15 - (OS * 9), 0x00000000, ft_itoa(l->coef->posz));
	mlx_string_put(l->coef->mlx, l->coef->win, (W + 45) + 109, 150 + 15 - (OS * 9), 0x00000000, ft_itoa(l->coef->rotx));
	mlx_string_put(l->coef->mlx, l->coef->win, (W + 45) + 109, 190 + 15 - (OS * 9), 0x00000000, ft_itoa(l->coef->roty));
	mlx_string_put(l->coef->mlx, l->coef->win, (W + 45) + 109, 230 + 15 - (OS * 9), 0x00000000, ft_itoa(l->coef->rotz));
	mlx_string_put(l->coef->mlx, l->coef->win, (W + 45) + 109, 290 + 15 - (OS * 9), 0x00000000, ft_itoa(l->coef->strx));
	mlx_string_put(l->coef->mlx, l->coef->win, (W + 45) + 109, 330 + 15 - (OS * 9), 0x00000000, ft_itoa(l->coef->stry));
	mlx_string_put(l->coef->mlx, l->coef->win, (W + 45) + 109, 370 + 15 - (OS * 9), 0x00000000, ft_itoa(l->coef->strz));
	mlx_string_put(l->coef->mlx, l->coef->win, (W + 45) + 109, 430 + 15 - (OS * 9), 0x00000000, ft_itoa(l->coef->rad));
	mlx_string_put(l->coef->mlx, l->coef->win, (W + 45) + 109, 490 + 15 - (OS * 9), 0x00000000, ft_itoa(l->coef->r));
	mlx_string_put(l->coef->mlx, l->coef->win, (W + 45) + 109, 530 + 15 - (OS * 9), 0x00000000, ft_itoa(l->coef->g));
	mlx_string_put(l->coef->mlx, l->coef->win, (W + 45) + 109, 570 + 15 - (OS * 9), 0x00000000, ft_itoa(l->coef->b));
	mlx_string_put(l->coef->mlx, l->coef->win, (W + 45) + 109, 630 + 15 - (OS * 9), 0x00000000, ft_itoa(l->coef->type));
	if (l->coef->shape != 0)
		mlx_string_put(l->coef->mlx, l->coef->win, (W + 45) + 109, 690 + 15 - (OS * 9), 0x00000000, rot);

/*	mlx_string_put(l->coef->mlx, l->coef->win_add, 109, 10, 0x00000000, ft_itoa(l->coef->posx));
	mlx_string_put(l->coef->mlx, l->coef->win_add, 109, 50, 0x00000000, ft_itoa(l->coef->posy));
	mlx_string_put(l->coef->mlx, l->coef->win_add, 109, 90, 0x00000000, ft_itoa(l->coef->posz));
	mlx_string_put(l->coef->mlx, l->coef->win_add, 109, 150, 0x00000000, ft_itoa(l->coef->rad));
	mlx_string_put(l->coef->mlx, l->coef->win_add, 109, 210, 0x00000000, ft_itoa(l->coef->r));
	mlx_string_put(l->coef->mlx, l->coef->win_add, 109, 250, 0x00000000, ft_itoa(l->coef->g));
	mlx_string_put(l->coef->mlx, l->coef->win_add, 109, 290, 0x00000000, ft_itoa(l->coef->b));
	mlx_string_put(l->coef->mlx, l->coef->win_add, 109, 350, 0x00000000, ft_itoa(l->coef->type));
*/
//	mlx_mouse_hook(l->coef->win_add, add_mouse_hook, l);
//	mlx_key_hook(l->coef->win_add, ft_keyhook, l);
	mlx_destroy_image(l->coef->mlx, img);
}

void				trace_info(t_control *c)
{
	if (c->coef->menu_state == 0)
		trace_info_0(c);
	if (c->coef->menu_state == 1)
		trace_info_1(c);
	if (c->coef->menu_state == 2)
		trace_info_2(c);
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
		e->coef->rot_x -= 5;
	else if (e->rotl)
		e->coef->rot_x += 5;
	else if (e->rotu)
		e->coef->rot_y += 5;
	else if (e->rotd)
		e->coef->rot_y -= 5;
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
