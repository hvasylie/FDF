/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_the_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:17:57 by hvasylie          #+#    #+#             */
/*   Updated: 2019/08/25 00:00:28 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void		ft_if(t_drawing *head, t_data_of_coords *data)
{
	head->d = (head->dy << 1) - head->dx;
	head->d1 = head->dy << 1;
	head->d2 = (head->dy - head->dx) << 1;
	mlx_pixel_put(data->mlx_ptr, data->win_ptr,
					head->x0, head->y0, head->color);
	head->x = head->x0 + head->sx;
	head->y = head->y0;
	head->i = 1;
	while (head->i <= head->dx)
	{
		if (head->d > 0)
		{
			head->d += head->d2;
			head->y += head->sy;
		}
		else
			head->d += head->d1;
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
						head->x, head->y, head->color);
		head->i++;
		head->x += head->sx;
	}
}

static	void		ft_else(t_drawing *head, t_data_of_coords *data)
{
	head->d = (head->dx << 1) - head->dy;
	head->d1 = head->dx << 1;
	head->d2 = (head->dx - head->dy) << 1;
	head->y = head->y0 + head->sy;
	head->i = 1;
	head->x = head->x0;
	mlx_pixel_put(data->mlx_ptr, data->win_ptr,
					head->x0, head->y0, head->color);
	while (head->i <= head->dy)
	{
		if (head->d > 0)
		{
			head->d += head->d2;
			head->x += head->sx;
		}
		else
			head->d += head->d1;
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
						head->x, head->y, head->color);
		head->y += head->sy;
		head->i++;
	}
}

static	void		segment(t_data_of_coords *data, int zero, int one)
{
	t_drawing *head;

	head = malloc(sizeof(t_drawing));
	head->x0 = data->coords[zero].x + data->move_x;
	head->x1 = data->coords[one].x + data->move_x;
	head->y0 = data->coords[zero].y + data->move_y;
	head->y1 = data->coords[one].y + data->move_y;
	head->color = 0xDDDDDD;
	head->dx = fabs(head->x1 - head->x0);
	head->dy = fabs(head->y1 - head->y0);
	head->sx = head->x1 >= head->x0 ? 1 : -1;
	head->sy = head->y1 >= head->y0 ? 1 : -1;
	if (head->dy <= head->dx)
		ft_if(head, data);
	else
		ft_else(head, data);
	free(head);
}

void				draw_the_line(t_data_of_coords *data)
{
	int row;
	int line_len;
	int act_len;
	int prev;

	row = 0;
	line_len = 0;
	act_len = 0;
	while (line_len < data->dots_count)
	{
		if (line_len % data->width == 0)
			row++;
		act_len = line_len % data->width;
		prev = act_len + (row * data->width);
		if (row < data->height)
			segment(data, line_len, prev);
		if (act_len != 0 && line_len != 0)
			segment(data, line_len, line_len - 1);
		line_len++;
	}
}
