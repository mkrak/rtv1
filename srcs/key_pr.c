#include "../includes/rt.h"

int		main_loop(t_control *e)
{
	int		test;

	test = 0;
	if (ft_key_camtrans(e) || ft_key_camrot(e) || ft_key_aa(e))
	{
		multithread(e);
		trace_info(e);
	}
	return (1);
}

int		key_p(int k, t_control *e)
{
	if (k == KP_SUB)
		e->kalisub = 1;
	if (k == KP_ADD)
		e->kaliadd = 1;
	if (k == K_U)
	{
		e->coef->reflec *= 1.5;
		multithread(e);
				trace_info(e);

	}
	if (k == K_I)
	{
		if (e->coef->reflec != 1)
		{
			e->coef->reflec /=  1.5;
			e->coef->reflec = fmax(e->coef->reflec, 1);
			multithread(e);
			trace_info(e);
		}
	}
	if (k == K_P)
		e->kaa = 1;
	if ((!OS && k == K_A) || (OS && k == K_Q))
		e->roll = 1;
	if (k == K_E)
		e->rolr = 1;
	if (k == K_D)
		e->rotr = 1;
	if ((!OS && k == K_Q) || (OS && k == K_A))
		e->rotl = 1;
	if ((!OS && k == K_Z) || (OS && k == K_W))
		e->rotu = 1;
	if (k == K_S)
		e->rotd = 1;
	if (k == K_AU)
		e->au = 1;
	if (k == K_AD)
		e->ad = 1;
	if (k == K_AL)
		e->al = 1;
	if (k == K_AR)
		e->ar = 1;
	if (k == K_RCTRL)
		e->ctrl = 1;
	if (k == K_RSHIF)
		e->shif = 1;
	if ((!OS && k == K_W) || (OS && k == K_Z))
	{
		usleep(100000);
		rename_win(e);
	}
	if (k == K_C)
	{
		if (e->coef->cartoon == 0)
			e->coef->cartoon = 1;
		else
			e->coef->cartoon = 0;
		multithread(e);
	}
	if (k == K_F)
	{
		if (e->coef->sepia == 0)
			e->coef->sepia = 1;
		else
			e->coef->sepia = 0;
		multithread(e);
	}
	if (k == K_X)
	{
		if (e->coef->wtf == 0)
			e->coef->wtf = 1;
		else
			e->coef->wtf = 0;
		multithread(e);
	}
	if (k == K_B)
	{
		if (e->coef->bnw == 0)
			e->coef->bnw = 1;
		else
			e->coef->bnw = 0;
		multithread(e);
	}if (k == K_N)
	{
		if (e->coef->negatif == 0)
			e->coef->negatif = 1;
		else
			e->coef->negatif = 0;
		multithread(e);
	}
	if (k == K_ESC)
	{
		mlx_destroy_image(e->coef->mlx, e->coef->img);
		free(e->coef);
		free(e->obj);
		free(e->l);
		exit(EXIT_SUCCESS);
	}
	return (k);
}

int		key_r(int k, t_control *e)
{
	if (k == KP_SUB)
		e->kalisub = 0;
	if (k == KP_ADD)
		e->kaliadd = 0;
	if (k == K_P)
		e->kaa = 0;
	if ((!OS && k == K_A) || (OS && k == K_Q))
		e->roll = 0;
	if (k == K_E)
		e->rolr = 0;
	if (k == K_D)
		e->rotr = 0;
	if ((!OS && k == K_Q) || (OS && k == K_A))
		e->rotl = 0;
	if ((!OS && k == K_Z) || (OS && k == K_W))
		e->rotu = 0;
	if (k == K_S)
		e->rotd = 0;
	if (k == K_AU)
		e->au = 0;
	if (k == K_AD)
		e->ad = 0;
	if (k == K_AL)
		e->al = 0;
	if (k == K_AR)
		e->ar = 0;
	if (k == K_RCTRL)
		e->ctrl = 0;
	if (k == K_RSHIF)
		e->shif = 0;
	return (k);
}
