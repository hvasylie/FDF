/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_keys_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:57:41 by hvasylie          #+#    #+#             */
/*   Updated: 2019/08/24 21:19:30 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		move_y_up(t_data_of_coords *data)
{
	data->move_y = data->move_y - 5;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_the_line(data);
}

void		move_y_down(t_data_of_coords *data)
{
	data->move_y = data->move_y + 5;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_the_line(data);
}

void		move_x_right(t_data_of_coords *data)
{
	data->move_x = data->move_x + 5;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_the_line(data);
}

void		move_x_left(t_data_of_coords *data)
{
	data->move_x = data->move_x - 5;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_the_line(data);
}
