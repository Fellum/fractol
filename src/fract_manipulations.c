/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_manipulations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:45:15 by jleann            #+#    #+#             */
/*   Updated: 2019/10/21 18:45:17 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include "fill_data.h"

void	zoom(t_fract *data, double value)
{
	double len;

	len = fabs(data->fstate.min_x - data->fstate.max_x);
	data->fstate.min_x += len * (value - 1);
	data->fstate.max_x -= len * (value - 1);
	len = fabs(data->fstate.min_y - data->fstate.max_y);
	data->fstate.min_y += len * (value - 1);
	data->fstate.max_y -= len * (value - 1);
	recalc_scale(data);
}

void	move_by_mouse(t_fract *data)
{
	double len;
	double value;

	if (data->instate.mpos[0] != data->instate.old_mpos[0])
	{
		value = (double)(data->instate.mpos[0] - data->instate.old_mpos[0]) /
				data->wstate.width;
		len = fabs(data->fstate.min_x - data->fstate.max_x);
		data->fstate.min_x -= len * value;
		data->fstate.max_x -= len * value;
	}
	if (data->instate.mpos[1] != data->instate.old_mpos[1])
	{
		value = (double)(data->instate.mpos[1] - data->instate.old_mpos[1]) /
				data->wstate.height;
		len = fabs(data->fstate.min_y - data->fstate.max_y);
		data->fstate.min_y += len * value;
		data->fstate.max_y += len * value;
		recalc_scale(data);
	}
}

void	change_fract(t_fract *data, int value)
{
	if (data->fstate.cur_f_id + value < 0)
		data->fstate.cur_f_id = NUM_OF_FRACTS;
	else if (data->fstate.cur_f_id + value >= NUM_OF_FRACTS)
		data->fstate.cur_f_id = 0;
	else
		data->fstate.cur_f_id += value;
	data->fstate.cur_func = get_ffract_by_id(data->fstate.cur_f_id);
}

void	iter_change(t_fract *data, double value)
{
	data->fstate.max_iter = data->fstate.max_iter * value + 1;
	if (data->fstate.max_iter > ITER_TRESHOLD)
		data->fstate.max_iter = ITER_TRESHOLD;
}
