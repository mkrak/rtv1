/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:50:18 by clanier           #+#    #+#             */
/*   Updated: 2018/05/03 19:50:28 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	*get_token(char *file, char *end, uint8_t len, t_token **token)
{
	char		type;
	char		*data;
	uint64_t	sz;
	uint64_t	i;

	sz = 0;
	type = (*file) == CHARS_QUOTE[1] ? CHARS_QUOTE[0] : *file;
	file++;
	while (*file && !ft_memchr(end, *file, len) && ++sz)
		file++;
	if (!(data = malloc(sz + 1)))
		return (file);
	file -= sz;
	i = 0;
	while (i < sz)
		data[i++] = *(file++);
	data[i] = 0;
	add_token(token, data, type);
	free(data);
	return (file);
}

void	*get_basic_token(char *file, t_token **token)
{
	return (get_token(file, CHARS_SPACE, ft_strlen(CHARS_SPACE), token));
}

void	*get_quote_token(char *file, t_token **token)
{
	return (get_token(file, file, 1, token));
}

void	*get_attr_token(char *file, t_token **token)
{
	char	end[2];

	--file;
	*file = CHAR_ATTR_END;
	file = get_token(file, file, 1, token);
	++file;
	while (*file && ft_strchr(CHARS_SPACE, *file))
		++file;
	--file;
	end[0] = CHAR_ATTR_VALUE_END;
	end[1] = CHAR_EOL;
	*file = end[0];
	return (get_token(file, end, 2, token));
}

void	*get_block_token(char *file, t_token **token)
{
	add_token(token, NULL, *(file++));
	return (file);
}
