/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:45:24 by jleann            #+#    #+#             */
/*   Updated: 2019/10/21 18:45:30 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_defs.h"
#include "fractol.h"

int	mouse_move(int x, int y, t_inputstate *data)
{
	data->old_mpos[0] = data->mpos[0];
	data->old_mpos[1] = data->mpos[1];
	data->mpos[0] = x;
	data->mpos[1] = y;
	return (0);
}

int	mouse_press(int button, int x, int y, t_inputstate *data)
{
	data->old_mpos[0] = data->mpos[0];
	data->old_mpos[1] = data->mpos[1];
	data->mpos[0] = x;
	data->mpos[1] = y;
	data->mkstate[button] = 1;
	return (0);
}

int	mouse_release(int button, int x, int y, t_inputstate *data)
{
	data->old_mpos[0] = data->mpos[0];
	data->old_mpos[1] = data->mpos[1];
	data->mpos[0] = x;
	data->mpos[1] = y;
	data->mkstate[button] = 0;
	return (0);
}
