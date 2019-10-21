/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:09:07 by jleann            #+#    #+#             */
/*   Updated: 2019/10/21 20:09:09 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

typedef struct	s_canvas
{
	int			bpp;
	int			size_line;
	int			endian;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_data;
	int			height;
	int			width;
}				t_canvas;

t_canvas		*init_canvas(void *mlx, void *window, int width, int height);
void			put_pixel(t_canvas *canv, int x, int y, int color);
void			draw_canvas(t_canvas *canv, int x, int y);

#endif
