/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:45:18 by jleann            #+#    #+#             */
/*   Updated: 2019/10/21 18:45:20 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_defs.h"
#include "fractol.h"

int	key_press(int key, t_inputstate *state)
{
	state->kstate[key] = 1;
	return (0);
}

int	key_release(int key, t_inputstate *state)
{
	state->kstate[key] = 0;
	return (0);
}
