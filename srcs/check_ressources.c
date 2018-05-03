/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ressources.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 23:24:53 by clanier           #+#    #+#             */
/*   Updated: 2018/05/03 23:25:02 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	check_img_path(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	close(fd);
}

void	check_ressources_2()
{
	check_img_path("ressources/img/menu_1/neg/");
	check_img_path("ressources/img/menu_1/neg/hover_0.XPM");
	check_img_path("ressources/img/menu_1/neg/hover_1.XPM");
	check_img_path("ressources/img/menu_1/neg/norm_0.XPM");
	check_img_path("ressources/img/menu_1/neg/norm_1.XPM");
	check_img_path("ressources/img/menu_1/sat/img.XPM");
	check_img_path("ressources/img/menu_1/sepia/hover_0.XPM");
	check_img_path("ressources/img/menu_1/sepia/hover_1.XPM");
	check_img_path("ressources/img/menu_1/sepia/norm_0.XPM");
	check_img_path("ressources/img/menu_1/sepia/norm_1.XPM");
	check_img_path("ressources/img/menu_1/wtf/hover_0.XPM");
	check_img_path("ressources/img/menu_1/wtf/hover_1.XPM");
	check_img_path("ressources/img/menu_1/wtf/norm_0.XPM");
	check_img_path("ressources/img/menu_1/wtf/norm_1.XPM");
}

void	check_ressources()
{
	check_img_path("ressources/img/add_filter_hover.XPM");
	check_img_path("ressources/img/add_filter_norm.XPM");
	check_img_path("ressources/img/add_obj_hover.XPM");
	check_img_path("ressources/img/add_obj_norm.XPM");
	check_img_path("ressources/img/logo.xpm");
	check_img_path("ressources/img/menu_0/add_filter_hover.XPM");
	check_img_path("ressources/img/menu_0/add_filter_norm.XPM");
	check_img_path("ressources/img/menu_0/add_obj_hover.XPM");
	check_img_path("ressources/img/menu_0/add_obj_norm.XPM");
	check_img_path("ressources/img/menu_1/back.XPM");
	check_img_path("ressources/img/menu_1/title.XPM");
	check_img_path("ressources/img/menu_1/cartoon/hover_0.XPM");
	check_img_path("ressources/img/menu_1/cartoon/hover_1.XPM");
	check_img_path("ressources/img/menu_1/cartoon/norm_0.XPM");
	check_img_path("ressources/img/menu_1/cartoon/norm_1.XPM");
	check_img_path("ressources/img/menu_1/lum/img.XPM");
	check_ressources_2();
}
