/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_funcs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:09:15 by jleann            #+#    #+#             */
/*   Updated: 2019/10/21 20:09:17 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_FUNCS_H
# define FRACT_FUNCS_H

int	mandelbrot_func(double x, double y, t_fractstate *fstate);
int	julia_func(double x, double y, t_fractstate *fstate);
int	mirrored_julia_func(double x, double y, t_fractstate *fstate);
int	burning_ship_func(double x, double y, t_fractstate *fstate);
int	sin_julia_func(double x, double y, t_fractstate *fstate);

#endif
