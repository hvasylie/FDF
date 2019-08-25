/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 13:20:22 by hvasylie          #+#    #+#             */
/*   Updated: 2019/08/24 21:13:45 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "stdlib.h"
# include "minilibx_macos/mlx.h"
# include "math.h"

typedef struct			s_coor
{
	double				x;
	double				y;
}						t_coor;

typedef struct			s_drawing
{
	double				x0;
	double				y0;
	double				x1;
	double				y1;
	int					x;
	int					y;
	int					color;
	int					d;
	int					d1;
	int					d2;
	int					dx;
	int					dy;
	int					sx;
	int					sy;
	int					i;

}						t_drawing;

typedef struct			s_data_of_coords
{
	double				c_x;
	double				c_y;
	double				size_x;
	double				size_y;
	int					height;
	int					width;
	int					dots_count;
	int					depth;
	int					move_x;
	int					move_y;
	t_coor				*coords;
	char				*name;
	void				*mlx_ptr;
	void				*win_ptr;
}						t_data_of_coords;

void					window_init(char *name, t_data_of_coords *head);
int						ft_error(int err_code);
int						reader(t_data_of_coords *head);
void					process_coords(t_data_of_coords *head);
void					draw_the_line(t_data_of_coords *data);
int						assign_keys(int key, t_data_of_coords *data);
void					move_y_up(t_data_of_coords *data);
void					move_y_down(t_data_of_coords *data);
void					move_x_right(t_data_of_coords *data);
void					move_x_left(t_data_of_coords *data);

#endif
