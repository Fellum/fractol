/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_manipulations.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:09:17 by jleann            #+#    #+#             */
/*   Updated: 2019/10/21 20:09:19 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_MANIPULATIONS_H
# define FRACT_MANIPULATIONS_H

void	zoom(t_fract *data, double value);
void	move_by_mouse(t_fract *data);
void	change_fract(t_fract *data, int value);
void	iter_change(t_fract *data, double value);

#endif
