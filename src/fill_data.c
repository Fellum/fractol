/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:45:07 by jleann            #+#    #+#             */
/*   Updated: 2019/10/21 18:45:10 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "fractol.h"
#include "arg_parser.h"
#include "fract_funcs.h"

t_fract_func	get_ffract_by_id(unsigned char id)
{
	static t_fract_func	funcs[NUM_OF_FRACTS] = {(t_fract_func)julia_func,
			(t_fract_func)mandelbrot_func,
			(t_fract_func)mirrored_julia_func,
			(t_fract_func)burning_ship_func,
			(t_fract_func)sin_julia_func
	};

	id = id % NUM_OF_FRACTS;
	return (funcs[id]);
}

void			recalc_scale(t_fract *fract)
{
	fract->fstate.scale_x = (fract->fstate.max_x - fract->fstate.min_x) /
							fract->wstate.width;
	fract->fstate.scale_y = (fract->fstate.max_y - fract->fstate.min_y) /
							fract->wstate.height;
}

void			fill_data(t_fract *fract, t_args *args)
{
	ft_bzero(fract, sizeof(t_fract));
	fract->wstate.height = DEFAULT_HEIGHT;
	fract->wstate.width = DEFAULT_WIDTH;
	fract->wstate.name = args->wname;
	fract->def_fstate.mouse_seed = 0;
	fract->def_fstate.max_x = DEFAULT_MAXX;
	fract->def_fstate.max_y = DEFAULT_MAXY;
	fract->def_fstate.min_x = DEFAULT_MINX;
	fract->def_fstate.min_y = DEFAULT_MINY;
	fract->def_fstate.max_iter = DEFAULT_MAXITER;
	fract->def_fstate.cur_f_id = args->fid;
	fract->def_fstate.cur_func = get_ffract_by_id(fract->def_fstate.cur_f_id);
	ft_memcpy(&(fract->fstate), &(fract->def_fstate), sizeof(t_fractstate));
	recalc_scale(fract);
}

void			recalc_seed(t_fract *data)
{
	data->fstate.seed_x = (double)(data->instate.mpos[0]) /
			data->wstate.width * 4 - 2;
	data->fstate.seed_y = (double)(data->instate.mpos[1]) /
			data->wstate.height * 4 - 2;
}
