#include "rt.h"

gen_obj	*init_gen(void)
{
	static gen_obj	generate[4];

	generate[0] = gen_sphere;
	generate[1] = gen_plane;
	generate[2] = gen_cylinder;
	generate[3] = gen_cone;
	return (generate);
}

t_vec3		get_normal(t_quadric q, t_vec3 p)
{
	t_vec3	normal;

	normal.x = 2 * q.a * p.x + q.e * p.z + q.f * p.y + q.g;
	normal.y = 2 * q.b * p.y + q.d * p.z + q.f * p.x + q.h;
	normal.z = 2 * q.c * p.z + q.d * p.y + q.e * p.x + q.i;
	return (normal);
}

void	gen_quadric(t_quadric *q)
{
	q->d = 0.0;
	q->e = 0.0;
	q->f = 0.0;
	q->g = 0.0;
	q->h = 0.0;
	q->i = 0.0;
}

t_attr	gen_attr(int color, double radius, char axe, int type)
{
	t_attr	attr;

	attr.kd = 0.8;
	attr.ks = 0.8;
	attr.axe = axe;
	attr.radius = radius;
	attr.color = color;
	attr.type = type;
	attr.albedo = vec3((color & 0xff) / 255., (color >> 8 & 0xff) / 255., (color >> 16 & 0xff) / 255.);
	return (attr);
}

void		translation(t_quadric* q, t_vec3 v)
{
	q->j = q->a * pow(v.x, 2) + q->b * pow(v.y, 2) + q->c * pow(v.z, 2) + q->d * v.y * v.z + q->e * v.x * v.z + q->f * v.x * v.y + q->g * v.x + q->h * v.y + q->i * v.z + q->j;
	q->i = - 2 * q->c * v.z - q->d * v.y - q->e * v.x + q->i;
	q->h = - 2 * q->b * v.y - q->d * v.z - q->e * v.x + q->h;
	q->g = - 2 * q->a * v.x - q->e * v.z - q->f * v.y + q->g;
}
