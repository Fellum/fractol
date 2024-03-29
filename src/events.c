/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:45:01 by jleann            #+#    #+#             */
/*   Updated: 2019/10/21 18:45:04 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

int	close_event(t_fract *data)
{
	(void)data;
	exit(0);
}

int	draw_tick(t_fract *data)
{
	apply_instate(data);
	draw_fract(data);
	return (0);
}
