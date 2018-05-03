/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:28:01 by clanier           #+#    #+#             */
/*   Updated: 2018/05/03 20:19:52 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	*get_file(const char *filename)
{
	int32_t		fd;
	uint64_t	ret;
	char		*file;
	char		buf[0x400];

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL);
	file = NULL;
	while ((ret = read(fd, &buf, 0x400)) > 0 && ret != (uint64_t)-1)
	{
		if (!(file = ft_strnjoin(file, buf, ret)))
			exit_error(ERR_UNKNOW);
	}
	close(fd);
	if (ret == (uint64_t)-1)
	{
		free(file);
		return (NULL);
	}
	return (file);
}

void	tokenize_scene(char *file, t_token **token)
{
	uint8_t	block;

	block = 0;
	while (*file)
	{
		if (ft_strchr(CHARS_SPACE, *file) && ++file)
			continue ;
		if (*file == CHAR_DEFINE)
			file = get_basic_token(file, token);
		else if (*file == CHAR_CLASS)
			file = get_basic_token(file, token);
		else if (ft_strchr(CHARS_QUOTE, *file))
			file = get_quote_token(file, token);
		else if (*file == CHAR_OBJECT)
			file = get_basic_token(file, token);
		else if (ft_strchr(CHARS_BLOCK, *file))
		{
			block ^= 1;
			file = get_block_token(file, token);
		}
		else if (block && ft_strchr(CHARS_ATTR, *file))
			file = get_attr_token(file, token);
		++file;
	}
}

int		create_scene(t_obj **obj, t_token *token,
		char *obj_class, char *obj_name)
{
	t_obj	*new;

	if (!(new = add_object(obj, obj_class)))
		return (-1);
	get_attr_from_token(token, obj_class, obj_name, new);
	gen_attr(new);
	return (0);
}

t_obj	*handle_scene(char *file)
{
	t_token	*token;
	t_obj	*obj;

	token = NULL;
	obj = NULL;
	tokenize_scene(file, &token);
	edit_token_types(token);
	if (check_token(token))
	{
		printf("\033[31;1m[RT] \033[0mInvalid scene\n");
		return (NULL);
	}
	if (!handle_token(&obj, token))
	{
		free_token(token);
		return (obj);
	}
	printf("\033[31;1m[RT] \033[0mAn error has occurred\n");
	free_token(token);
	return (NULL);
}
