#include "../includes/rt.h"

static void		ft_float(float d, float eps)
{
	if (d >= 10)
	{
		ft_float(((int)d / 10) + (d - (int)d), eps);
		ft_float((int)d % 10, eps);
	}
	else if (d - (int)d > eps && d - (int)d < 1 - eps)
		ft_float((int)((d - (int)d) / eps), eps);
	else
		ft_putchar((int)d + '0');
}

void			ft_putfloat(float d, double eps)
{
	if (d < 0)
	{
		ft_putchar('-');
		d *= -1;
	}
	if (d - (int)d < 1 - (float)eps)
		ft_float((int)d, (float)eps);
	ft_putchar('.');
	ft_float(d - (int)d, (float)eps);
}

void	reverse(char *str, int len)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

int		inttostr(int x, char *str, int d)
{
	int		i;

	i = 0;
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x /= 10;
	}
	while (i < d)
		str[i++] = '0';
	reverse(str, i);
	str[i] = '0';
	return (i);
}

void	ftoa(float n, char *res, int p)
{
	int		in;
	int		i;
	float	fl;

	in = (int)n;
	fl = n - (float)in;
	i = inttostr(in, res, 0);
	if (p > 0)
	{
		res[i] = '.';
		fl = fl * pow(10, p);
		inttostr((int)fl, res + 1 + i, p);
	}
}
