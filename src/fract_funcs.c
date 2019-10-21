/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:45:12 by jleann            #+#    #+#             */
/*   Updated: 2019/10/21 18:45:14 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int	mandelbrot_func(double x, double y, t_fractstate *fstate)
{
	double	cur_x;
	double	cur_y;
	double	tmp;
	int		cur_iter;

	cur_x = x;
	cur_y = y;
	cur_iter = 0;
	while (cur_iter < fstate->max_iter)
	{
		tmp = cur_x * cur_x - cur_y * cur_y + x;
		cur_y = 2 * cur_x * cur_y + y;
		cur_x = tmp;
		if (cur_x * cur_x + cur_y * cur_y >= 4)
			break ;
		cur_iter++;
	}
	return (get_color(cur_iter, fstate));
}

int	julia_func(double x, double y, t_fractstate *fstate)
{
	double	cur_x;
	double	cur_y;
	double	tmp;
	int		cur_iter;

	cur_x = x;
	cur_y = y;
	cur_iter = 0;
	while (cur_iter < fstate->max_iter)
	{
		tmp = cur_x * cur_x - cur_y * cur_y + fstate->seed_x;
		cur_y = 2 * cur_x * cur_y + fstate->seed_y;
		cur_x = tmp;
		if (cur_x * cur_x + cur_y * cur_y >= 4)
			break ;
		cur_iter++;
	}
	return (get_color(cur_iter, fstate));
}

int	mirrored_julia_func(double x, double y, t_fractstate *fstate)
{
	double	cur_x;
	double	cur_y;
	double	tmp;
	int		cur_iter;

	cur_x = x;
	cur_y = y;
	cur_iter = 0;
	while (cur_iter < fstate->max_iter)
	{
		tmp = fabs(cur_x * cur_x - cur_y * cur_y) + fstate->seed_x;
		cur_y = 2 * cur_x * cur_y + fstate->seed_y;
		cur_x = tmp;
		if (cur_x * cur_x + cur_y * cur_y >= 4)
			break ;
		cur_iter++;
	}
	return (get_color(cur_iter, fstate));
}

int	burning_ship_func(double x, double y, t_fractstate *fstate)
{
	double	cur_x;
	double	cur_y;
	double	tmp;
	int		cur_iter;

	cur_x = x;
	cur_y = y;
	cur_iter = 0;
	while (cur_iter < fstate->max_iter)
	{
		tmp = fabs(cur_x * cur_x - cur_y * cur_y) + x;
		cur_y = 2 * cur_x * cur_y + y;
		cur_x = tmp;
		if (cur_x * cur_x + cur_y * cur_y >= 4)
			break ;
		cur_iter++;
	}
	return (get_color(cur_iter, fstate));
}

int	sin_julia_func(double x, double y, t_fractstate *fstate)
{
	double	cur_x;
	double	cur_y;
	double	tmp;
	int		cur_iter;

	cur_x = x;
	cur_y = y;
	cur_iter = 0;
	while (cur_iter < fstate->max_iter)
	{
		tmp = sin(cur_x * cur_x - cur_y * cur_y) + fstate->seed_x;
		cur_y = 2 * cur_x * cur_y + fstate->seed_y;
		cur_x = tmp;
		if (cur_x * cur_x + cur_y * cur_y >= 4)
			break ;
		cur_iter++;
	}
	return (get_color(cur_iter, fstate));
}
