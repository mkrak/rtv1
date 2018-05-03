/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:57:40 by clanier           #+#    #+#             */
/*   Updated: 2018/05/03 20:20:25 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	free_object(t_obj *obj)
{
	t_obj	*tmp;

	while (obj)
	{
		tmp = obj;
		obj = obj->next;
		free(tmp);
	}
}

t_obj	*new_object(char *obj_class)
{
	t_obj	*new;
	uint8_t	id;

	if (!(new = malloc(sizeof(t_obj))))
		return (NULL);
	id = 0;
	while (id < N_CLASS)
	{
		if (!ft_strcmp(g_class[id].name, obj_class))
		{
			new->attr.type = id;
			break ;
		}
		id++;
	}
	if (id >= N_CLASS)
		id = 0;
	init_object(new, id);
	return (new);
}

t_obj	*add_object(t_obj **obj, char *obj_class)
{
	t_obj	*tmp;

	tmp = *obj;
	if (!tmp)
		return (*obj = new_object(obj_class));
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->next = new_object(obj_class));
}
