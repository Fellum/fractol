/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:44:30 by jleann            #+#    #+#             */
/*   Updated: 2019/10/21 18:45:47 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fractol.h"
#include "mlx_defs.h"
#include "events.h"
#include "fract_manipulations.h"
#include "fill_data.h"

void	apply_keyboard(t_fract *data)
{
	if (data->instate.kstate[ID_MOUSE_SEED] == 1)
		data->fstate.mouse_seed = 1;
	else
		data->fstate.mouse_seed = 0;
	if (data->instate.kstate[ID_DROP] == 1)
		ft_memcpy(&(data->fstate), &(data->def_fstate), sizeof(t_fractstate));
	if (data->instate.kstate[ID_EXIT] == 1)
		close_event(0);
	if (data->instate.kstate[ID_PCOLOR] == 1)
	{
		data->fstate.cur_color = (char)((data->fstate.cur_color + 1) % 3);
		data->instate.kstate[ID_PCOLOR] = 0;
	}
	if (data->instate.kstate[ID_NCOLOR] == 1)
	{
		data->fstate.cur_color = (char)((data->fstate.cur_color - 1) % 3);
		data->instate.kstate[ID_NCOLOR] = 0;
	}
}

void	apply_keyboard2(t_fract *data)
{
	if (data->instate.kstate[ID_NFRACT] == 1)
	{
		change_fract(data, 1);
		data->instate.kstate[ID_NFRACT] = 0;
	}
	if (data->instate.kstate[ID_PFRACT] == 1)
	{
		change_fract(data, -1);
		data->instate.kstate[ID_PFRACT] = 0;
	}
	if (data->instate.kstate[ID_ITERUP] == 1)
		iter_change(data, 1.1);
	if (data->instate.kstate[ID_ITERDOWN] == 1)
		iter_change(data, 0.9);
}

void	apply_mouse(t_fract *data)
{
	if (data->fstate.mouse_seed)
		recalc_seed(data);
	if (data->instate.mkstate[ID_ZOOM_IN])
	{
		zoom(data, 1.05);
		data->instate.mkstate[ID_ZOOM_IN] = 0;
	}
	else if (data->instate.mkstate[ID_ZOOM_OUT])
	{
		zoom(data, 0.95);
		data->instate.mkstate[ID_ZOOM_OUT] = 0;
	}
	if (data->instate.mkstate[ID_DRAG])
		move_by_mouse(data);
}

void	apply_instate(t_fract *data)
{
	apply_keyboard(data);
	apply_keyboard2(data);
	apply_mouse(data);
}
