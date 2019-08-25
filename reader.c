/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 14:25:33 by hvasylie          #+#    #+#             */
/*   Updated: 2019/08/24 23:55:08 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			window_init(char *name, t_data_of_coords *head)
{
	head->name = name;
	head->coords = (t_coor *)malloc(sizeof(t_coor) * head->dots_count);
	head->move_x = 500;
	head->move_y = 100;
	head->depth = 5;
	head->mlx_ptr = mlx_init();
	head->win_ptr = mlx_new_window(head->mlx_ptr, 1250, 1250, "Rock'n'Roll");
}

int				ft_error(int err_code)
{
	if (err_code == 1)
		ft_putstr("Please add an argument with the map file");
	if (err_code == 2)
		ft_putstr("Make sure the file name is correct\n");
	return (0);
}

int				reader(t_data_of_coords *head)
{
	int			x;
	int			y;
	char		*line;
	int			fd;

	x = 0;
	y = 0;
	fd = open(head->name, O_RDONLY);
	if (fd <= 0)
		if (ft_error(2) == 0)
			return (1);
	while (get_next_line(fd, &line) == 1)
	{
		x = ft_words_count(line, ' ');
		free(line);
		y++;
	}
	close(fd);
	head->width = x;
	head->height = y;
	head->size_x = 700 / head->width;
	head->size_y = 700 / head->height;
	head->dots_count = x * y;
	return (0);
}
