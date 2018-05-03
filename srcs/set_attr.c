/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_attr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 20:05:51 by clanier           #+#    #+#             */
/*   Updated: 2018/05/03 20:06:13 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	set_attr(t_obj *obj, char *attr, char *attr_value)
{
	uint8_t	i;

	i = 0;
	while (i < N_ATTR)
	{
		if (!ft_strcmp(g_set_attr[i].attr, attr))
		{
			g_set_attr[i].set_attr(attr_value,
			(void*)obj + g_set_attr[i].struct_offset);
			break ;
		}
		i++;
	}
}

void	get_attr_from_token(t_token *token,
		char *obj_class, char *obj_name, t_obj *new)
{
	bool	attr;

	attr = false;
	while (token)
	{
		if (token->type == TTE_DEF)
		{
			token = token->next->next->next;
			continue ;
		}
		if (!attr
		&& ((token->type == TTE_OBJECT && !ft_strcmp(token->data, obj_name))
		|| (token->type == TTE_CLASS && !ft_strcmp(token->data, obj_class))))
			attr = true;
		else if (attr && token->type == TTE_END_BLOCK)
			attr = false;
		else if (attr && token->type == TTE_ATTR)
		{
			set_attr(new, token->data, token->next->data);
			token = token->next;
		}
		token = token->next;
	}
}
