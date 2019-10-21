/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:09:10 by jleann            #+#    #+#             */
/*   Updated: 2019/10/21 20:09:12 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "fractol.h"

int	key_press(int key, t_inputstate *state);
int key_release(int key, t_inputstate *state);
int	close_event(t_fract *data);
int	draw_tick(t_fract *data);
int	mouse_move(int x, int y, t_inputstate *data);
int	mouse_press(int button, int x, int y, t_inputstate *data);
int	mouse_release(int button, int x, int y, t_inputstate *data);

#endif
