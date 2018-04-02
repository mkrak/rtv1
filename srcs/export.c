#include "../includes/rt.h"

void	expand_name(t_control *l, char c)
{
	char	*swap;

	if (!(l->coef->name))
	{
		l->coef->name = malloc(sizeof(char) * 2);
		l->coef->name[0] = c;
		l->coef->name[1] = '\0';
	}
	else
	{
		swap = malloc(sizeof(char) * (ft_strlen(l->coef->name) + 1));
		swap = ft_strdup(l->coef->name);
		swap[ft_strlen(l->coef->name)] = '\0';
		l->coef->name = malloc(sizeof(char) * (ft_strlen(l->coef->name) + 2));
		l->coef->name = ft_strdup(swap);
		l->coef->name[ft_strlen(swap)] = c;
		l->coef->name[ft_strlen(swap) + 1] = '\0';
		free(swap);
	}
	mlx_string_put(l->coef->mlx, l->coef->win_rename, 10, 10, 0x00ffffff, l->coef->name);
}

int		hook_rename(int k, t_control *l)
{
	if (k >= 'a' && k <= 'z')
		expand_name(l, k);
	if (k == 65293)
	{
		l->coef->name = ft_strjoin(l->coef->name, ".bmp");
		ft_putendl(l->coef->name);
		export_file(l);
		ft_strdel(&l->coef->name);
		mlx_destroy_window(l->coef->mlx, l->coef->win_rename);
	}
	return (k);
}

void	rename_win(t_control *l)
{
	l->coef->win_rename = mlx_new_window(l->coef->mlx, 500, 100, "Name");
	mlx_key_hook(l->coef->win_rename, hook_rename, l);
}
