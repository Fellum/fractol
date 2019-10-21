/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:18:18 by jleann            #+#    #+#             */
/*   Updated: 2019/10/21 19:18:19 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int		get_color(int cur_iter, t_fractstate *data)
{
	unsigned char	res[4];
	double			t;

	t = (double)cur_iter / (double)(data->max_iter);
	res[(data->cur_color + 1) % 3] = (int)(9 * (1 - t) * pow(t, 3) * 255);
	res[(data->cur_color + 2) % 3] =
			(int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	res[(data->cur_color + 3) % 3] = (int)(8.5 * pow((1 - t), 3) * t * 255);
	res[data->cur_color % 3] = 0;
	return (*((int *)res));
}
