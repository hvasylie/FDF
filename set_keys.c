/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:50:42 by hvasylie          #+#    #+#             */
/*   Updated: 2019/08/24 23:57:58 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		change_depth_minus(t_data_of_coords *data)
{
	data->depth = data->depth - 1;
	if (data->depth < -15)
		data->depth = -15;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	process_coords(data);
	draw_the_line(data);
}

static void		change_depth_plus(t_data_of_coords *data)
{
	data->depth = data->depth + 1;
	if (data->depth > 20)
		data->depth = 20;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	process_coords(data);
	draw_the_line(data);
}

int				assign_keys(int key, t_data_of_coords *data)
{
	if (key == 27)
		change_depth_minus(data);
	else if (key == 24)
		change_depth_plus(data);
	else if (key == 124)
		move_x_right(data);
	else if (key == 123)
		move_x_left(data);
	else if (key == 126)
		move_y_up(data);
	else if (key == 125)
		move_y_down(data);
	else if (key == 53)
		exit(0);
	return (0);
}
