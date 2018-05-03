/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:51:07 by clanier           #+#    #+#             */
/*   Updated: 2018/05/03 19:51:37 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		check_foreach_class(char *data)
{
	uint8_t	i;

	i = 0;
	while (i < N_CLASS)
		if (!ft_strcmp(data, g_class[i++].name))
			return (0);
	return (-1);
}

int		check_valid_chars(char *data, const char *valid)
{
	while (*data)
		if (!ft_strchr(valid, *(data++)))
			return (-1);
	return (0);
}

int		check_data_from_type(t_token *token)
{
	if (token->type == TTE_DEF && ft_strcmp(token->data, CST_DEFINE))
		return (-1);
	else if (token->type == TTE_CLASS && check_foreach_class(token->data))
		return (-1);
	else if (token->type == TTE_NAME && check_valid_chars(token->data, \
		CHARS_NAME))
		return (-1);
	else if (token->type == TTE_ATTR && check_valid_chars(token->data, \
		CHARS_ATTR))
		return (-1);
	return (0);
}

int		check_token_loop(t_token *token, uint8_t *expt)
{
	while (token)
	{
		if (!(expt[0] & token->type) || check_data_from_type(token))
			return (-1);
		if (token->type == TTE_DEF)
			expt[0] = TTE_CLASS;
		else if (token->type == TTE_CLASS && expt[1] == TTE_DEF)
			expt[0] = TTE_NAME;
		else if (token->type == TTE_NAME || token->type == TTE_END_BLOCK)
			expt[0] = TTE_CLASS | TTE_DEF | TTE_OBJECT;
		else if (token->type == TTE_OBJECT || token->type == TTE_CLASS)
			expt[0] = TTE_CLASS | TTE_OBJECT | TTE_START_BLOCK;
		else if (token->type == TTE_START_BLOCK)
			expt[0] = TTE_ATTR;
		else if (token->type == TTE_ATTR)
			expt[0] = TTE_ATTR_VALUE;
		else if (token->type == TTE_ATTR_VALUE)
			expt[0] = TT_ATTR | TT_END_BLOCK;
		expt[1] = token->type;
		token = token->next;
	}
	return (expt[0] != (TTE_DEF | TTE_CLASS | TTE_OBJECT) ? -1 : 0);
}

int		check_token(t_token *token)
{
	uint8_t	expt[2];

	expt[0] = TTE_CLASS | TTE_DEF | TTE_OBJECT;
	expt[1] = 0;
	return (check_token_loop(token, expt));
}
