/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 13:56:26 by hvasylie          #+#    #+#             */
/*   Updated: 2019/08/24 23:54:40 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int ac, char **av)
{
	t_data_of_coords	*head;

	head = malloc(sizeof(t_data_of_coords));
	if (ac != 2)
	{
		ft_error(1);
		return (0);
	}
	window_init(av[1], head);
	if (reader(head) == 1)
		return (0);
	process_coords(head);
	draw_the_line(head);
	mlx_hook(head->win_ptr, 2, 5, assign_keys, head);
	mlx_loop(head->mlx_ptr);
	free(head->coords);
	free(head);
	return (0);
}
