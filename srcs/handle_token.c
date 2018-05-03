/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:49:29 by clanier           #+#    #+#             */
/*   Updated: 2018/05/03 19:54:05 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	free_token(t_token *token)
{
	t_token	*tmp;

	while (token)
	{
		if (token->data)
			free(token->data);
		tmp = token->next;
		free(token);
		token = tmp;
	}
}

t_token	*new_token(void *data, char type)
{
	t_token	*new;

	if (!(new = malloc(sizeof(t_token))))
		return (NULL);
	new->data = data ? ft_strdup(data) : NULL;
	new->type = type;
	new->next = NULL;
	return (new);
}

void	add_token(t_token **token, void *data, char type)
{
	t_token	*tmp;

	if (!(tmp = *token))
		*token = new_token(data, type);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_token(data, type);
	}
}

void	edit_token_types(t_token *token)
{
	uint8_t	i;

	while (token)
	{
		i = 0;
		while (i < N_TT)
		{
			if (token->type == g_tt[i][0])
			{
				token->type = g_tt[i][1];
				break ;
			}
			i++;
		}
		token = token->next;
	}
}

int		handle_token(t_obj **obj, t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp->type == TTE_DEF)
		{
			if (create_scene(obj, token,
			tmp->next->data, tmp->next->next->data))
				return (-1);
			tmp = tmp->next->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
