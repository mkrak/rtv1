/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_attr_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:54:50 by clanier           #+#    #+#             */
/*   Updated: 2018/05/03 19:55:17 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	set_double_attr(char *attr_value, void *attr_dst)
{
	double	n;
	double	dec;
	double	*tmp;
	uint8_t	neg;

	neg = 0;
	while (ft_strchr("-+ \t\n\v\f\r", *attr_value))
		if (*(attr_value++) == '-')
			neg = 1;
		else if (*(attr_value) == '+')
			neg = 0;
	n = ft_atoi(attr_value);
	n = neg ? -n : n;
	while (ft_strchr("0123456789", *attr_value))
		attr_value++;
	if (*attr_value == '.' && *(++attr_value) >= '0' && *attr_value <= '9')
	{
		dec = ft_atoi(attr_value);
		while (dec > 1)
			dec /= 10.f;
		n += neg ? -dec : dec;
	}
	tmp = attr_dst;
	*tmp = n;
}

void	set_vec_attr(char *attr_value, void *attr_dst)
{
	set_double_attr(attr_value, &(((t_vec3*)attr_dst)->x));
	set_double_attr((size_t)(attr_value = ft_strchr(attr_value, ',') + 1) > 1
	? attr_value : "0", &(((t_vec3*)attr_dst)->y));
	if ((size_t)attr_value == 1)
		attr_value = NULL;
	set_double_attr((size_t)(attr_value = ft_strchr(attr_value, ',') + 1) > 1
	? attr_value : "0", &(((t_vec3*)attr_dst)->z));
}

void	set_color_attr(char *attr_value, void *attr_dst)
{
	uint32_t	color;
	uint32_t	*tmp;
	uint8_t		n;
	uint8_t		i;

	if (*(attr_value++) != CHAR_COLOR || ft_strlen(attr_value) != COLOR_LEN)
		return ;
	color = 0;
	i = 0;
	while (i < COLOR_LEN)
	{
		if (!ft_strchr(CHARS_COLOR, attr_value[i]))
			return ;
		n = attr_value[i] <= '9' ? attr_value[i] - '0' : attr_value[i] - 0x57;
		color += pow(16, COLOR_LEN - ++i) * n;
	}
	tmp = attr_dst;
	*tmp = color;
}

void	set_surface_attr(char *attr_value, void *attr_dst)
{
	uint8_t	i;
	uint8_t	*tmp;

	i = 0;
	while (i < N_ST)
	{
		if (!ft_strcmp(attr_value, g_surface[i]))
			break ;
		i++;
	}
	if (i >= N_ST)
		return ;
	tmp = attr_dst;
	*tmp = i;
}

void	set_char_attr(char *attr_value, void *attr_dst)
{
	char	*tmp;

	if (ft_strlen(attr_value) != 1 || !ft_strchr(CHARS_AXE, *attr_value))
		return ;
	tmp = attr_dst;
	*tmp = *attr_value;
}
