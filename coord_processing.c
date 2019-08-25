/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 15:28:35 by hvasylie          #+#    #+#             */
/*   Updated: 2019/08/24 23:50:27 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			write_coords(int n, t_data_of_coords *head, int i)
{
	head->coords[i].x = (head->c_x - head->c_y +
			head->size_x) * cos(0.523599);
	head->coords[i].y = -(n * head->depth)
			+ (head->c_x + head->c_y) * sin(0.523599);
	head->c_x += head->size_x;
}

static void			to_coordinates(t_data_of_coords *head, int fd, int row)
{
	int		i;
	int		j;
	char	**pos;
	char	*line;

	i = 0;
	j = 0;
	while (get_next_line(fd, &line) == 1)
	{
		pos = ft_strsplit(line, ' ');
		while (j < head->width)
		{
			write_coords(ft_atoi(pos[j]), head, i);
			i++;
			j++;
		}
		free(line);
		free(pos);
		row++;
		head->c_x = 295;
		head->c_y += (head->size_y);
		j = 0;
	}
}

void				process_coords(t_data_of_coords *head)
{
	int			fd;
	int			row;

	row = 0;
	fd = open(head->name, O_RDONLY);
	head->c_x = 295;
	head->c_y = 200;
	to_coordinates(head, fd, row);
	close(fd);
}
