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

void	trunc_name(t_control *l)
{
	char	*swap;
	int		i;

	i = 0;
	if (l->coef->name && ft_strlen(l->coef->name) > 0)
	{
		swap = malloc(sizeof(char) * ft_strlen(l->coef->name));
		while (i < (int)ft_strlen(l->coef->name) - 1)
		{
			swap[i] = l->coef->name[i];
			i++;
		}
		swap[i] = '\0';
		l->coef->name = malloc(sizeof(swap));
		l->coef->name = ft_strdup(swap);
		l->coef->name[i] = '\0';
		free(swap);
		mlx_string_put(l->coef->mlx, l->coef->win_rename, 10, 10, 0x00ffffff, l->coef->name);
	}
}

void	hook_mac_rename(t_control *l, int k)
{
	if (k == K_A)
		expand_name(l, 'a');
	else if (k == K_B)
		expand_name(l, 'b');
	else if (k == K_C)
		expand_name(l, 'c');
	else if (k == K_D)
		expand_name(l, 'd');
	else if (k == K_E)
		expand_name(l, 'e');
	else if (k == K_F)
		expand_name(l, 'f');
	else if (k == K_G)
		expand_name(l, 'g');
	else if (k == K_H)
		expand_name(l, 'h');
	else if (k == K_I)
		expand_name(l, 'i');
	else if (k == K_J)
		expand_name(l, 'j');
	else if (k == K_K)
		expand_name(l, 'k');
	else
		hook_mac_rename2(l, k);
}

void	hook_mac_rename2(t_control *l, int k)
{
	if (k == K_L)
		expand_name(l, 'l');
	else if (k == K_M)
		expand_name(l, 'm');
	else if (k == K_N)
		expand_name(l, 'n');
	else if (k == K_O)
		expand_name(l, 'o');
	else if (k == K_P)
		expand_name(l, 'p');
	else if (k == K_Q)
		expand_name(l, 'q');
	else if (k == K_R)
		expand_name(l, 'r');
	else if (k == K_S)
		expand_name(l, 's');
	else if (k == K_T)
		expand_name(l, 't');
	else if (k == K_U)
		expand_name(l, 'u');
	else if (k == K_V)
		expand_name(l, 'v');
	else
		hook_mac_rename3(l, k);
}

void	hook_mac_rename3(t_control *l, int k)
{
	if (k == K_W)
		expand_name(l, 'w');
	else if (k == K_X)
		expand_name(l, 'x');
	else if (k == K_Y)
		expand_name(l, 'y');
	else if (k == K_Z)
		expand_name(l, 'z');
	else if (k == 51)
		trunc_name(l);
}

void	refresh_name(t_control *l)
{
	t_img	img;

	img.img = mlx_new_image(l->coef->mlx, 500, 100);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win_rename, img.img, 0, 0);
	mlx_destroy_image(l->coef->mlx, img.img);
}

int		hook_rename(int k, t_control *l)
{
	refresh_name(l);
	if ((!OS && (k >= 'a' && k <= 'z')))
		expand_name(l, k);
	if (OS)
		hook_mac_rename(l, k);
	if (k == K_ESC)
	{
		ft_strdel(&l->coef->name);
		mlx_destroy_window(l->coef->mlx, l->coef->win_rename);
	}
	if (k == K_ENTER)
	{
		l->coef->name = ft_strjoin(l->coef->name, ".bmp");
		l->coef->name = ft_strjoin("export/", l->coef->name);
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
