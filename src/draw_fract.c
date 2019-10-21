/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:44:56 by jleann            #+#    #+#             */
/*   Updated: 2019/10/21 18:44:57 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <events.h>
#include "fractol.h"
#include "canvas.h"

void	draw_fract_part(t_fract *fract)
{
	double	cur_x;
	double	cur_y;
	int		x;
	int		y;

	y = fract->wstate.start_line;
	while (y < fract->wstate.end_line)
	{
		x = 0;
		cur_y = fract->fstate.max_y - y * fract->fstate.scale_y;
		cur_x = fract->fstate.min_x;
		while (x < fract->wstate.width)
		{
			put_pixel(fract->wstate.canvas, x, y,
	fract->fstate.cur_func(cur_x, cur_y, &(fract->fstate)));
			x++;
			cur_x += fract->fstate.scale_x;
		}
		y++;
	}
}

void	draw_fract(t_fract *fract)
{
	pthread_t	threads[THREADS];
	t_fract		fractols[THREADS];
	int			i;

	i = 0;
	while (i < THREADS)
	{
		fractols[i] = *fract;
		fractols[i].wstate.start_line = i *
				(fractols[i].wstate.height / THREADS);
		fractols[i].wstate.end_line = (i + 1) *
				(fractols[i].wstate.height / THREADS);
		if (pthread_create(&threads[i], NULL,
	(void *(*)(void *))draw_fract_part,
	(void *)&fractols[i]))
			close_event(NULL);
		i++;
	}
	while (i-- > 0)
		if (pthread_join(threads[i], NULL))
			close_event(NULL);
	draw_canvas(fract->wstate.canvas, 0, 0);
}
