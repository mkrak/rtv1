/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:28:01 by clanier           #+#    #+#             */
/*   Updated: 2018/05/03 12:16:29 by lgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	exit_error(const char *err)
{
	printf("\033[31;1m[RT] \033[0m%s\n", err);
	exit(EXIT_FAILURE);
}

void	*strjou1(void *dst, const void *src, uint64_t n)
{
	uint64_t	len;
	char		*tmp;

	if (!dst)
	{
		if (!(dst = malloc(n + 1)))
			return (NULL);
		ft_memcpy(dst, src, n);
		tmp = dst;
		tmp[n] = 0;
		return (dst);
	}
	len = ft_strlen(dst);
	if (!(tmp = malloc(len)))
		return (NULL);
	ft_memcpy(tmp, dst, len);
	free(dst);
	if (!(dst = malloc(n + len + 1)))
		return (NULL);
	ft_memcpy(dst, tmp, len);
	ft_memcpy(dst + len, src, n);
	free(tmp);
	tmp = dst;
	tmp[n + len] = 0;
	return (dst);
}

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
		if (!(file = strjou1(file, buf, ret)))
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

void	dump_token(t_token *token)
{
	while (token)
	{
		if (token->data)
			printf("%c: %s\n", token->type, token->data);
		else
			printf("%c\n", token->type);
		token = token->next;
	}
}

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
	while  (ft_strchr("0123456789", *attr_value))
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
	set_double_attr((size_t)(attr_value = ft_strchr(attr_value, ',') + 1) > 1 ? attr_value : "0", &(((t_vec3*)attr_dst)->y));
	if ((size_t)attr_value == 1)
		attr_value = NULL;
	set_double_attr((size_t)(attr_value = ft_strchr(attr_value, ',') + 1) > 1 ? attr_value : "0", &(((t_vec3*)attr_dst)->z));
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

void	set_attr(t_obj *obj, char *attr, char *attr_value)
{
	uint8_t	i;

	i = 0;
	while (i < N_ATTR)
	{
		if (!ft_strcmp(g_set_attr[i].attr, attr))
		{
			g_set_attr[i].set_attr(attr_value, (void*)obj + g_set_attr[i].struct_offset);
			break ;
		}
		i++;
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

int		create_scene(t_obj **obj, t_token *token, char *obj_class, char *obj_name)
{
	t_obj	*new;
	bool	attr;

	attr = false;
	if (!(new = add_object(obj, obj_class)))
		return (-1);
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
	gen_attr(new);
	return (0);
}

int		handle_token(t_obj **obj, t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp->type == TTE_DEF)
		{
			if (create_scene(obj, token, tmp->next->data, tmp->next->next->data))
				return (-1);
			tmp = tmp->next->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

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

void	dump_obj(t_obj *obj)
{
	while (obj)
	{
		printf("new object : %s %s on %c\n\n",
		g_surface[obj->attr.type], g_class[obj->attr.id].name, obj->attr.axe);
		printf("x : %f\ny : %f\nz : %f\n\n",
		obj->attr.pos.x, obj->attr.pos.y, obj->attr.pos.z);
		printf("rot-x : %f\nrot-y : %f\nrot-z : %f\n\n",
		obj->attr.rot.x, obj->attr.rot.y, obj->attr.rot.z);
		printf("scale-x : %f\nscale-y : %f\nscale-z : %f\n\n",
		obj->attr.scale.x, obj->attr.scale.y, obj->attr.scale.z);
		printf("radius : %f\n\n", obj->attr.radius);
		printf("color  : %#08x\n\n", obj->attr.color);
		printf("albdeo : (%f, %f, %f)\n\n", obj->attr.albedo.x,
		obj->attr.albedo.y, obj->attr.albedo.z);
		printf("d: %f\ns: %f\n", obj->attr.kd, obj->attr.ks);
		obj = obj->next;
		if (obj)
			printf("\n------------------------------\n\n");
	}
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
		return NULL;
	}
	if (!handle_token(&obj, token))
	{
		free_token(token);
		return (obj);
	}
	else
		printf("\033[31;1m[RT] \033[0mAn error has occurred\n");
	free_token(token);
	return (NULL);
}
