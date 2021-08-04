/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_S_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 11:14:55 by asebrech          #+#    #+#             */
/*   Updated: 2021/08/04 13:53:41 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_x(t_var *var, t_map *map)
{
	static int	i = 0;

	if (i < 5)
		move_left_S(var, map);
	else
		move_right_S(var, map);
	if (i == 10)
		i = -1;
	i++;
}

static void	move_y(t_var *var, t_map *map)
{
	static int	i = 0;

	if (i < 5)
		move_up_S(var, map);
	else
		move_down_S(var, map);
	if (i == 10)
		i = -1;
	i++;
}

static void	read_map(t_var *var, int i)
{
	t_map	map;

	map.i = 0;
	while (map.i < var->line)
	{
		map.j = 0;
		while (var->map[map.i][map.j])
		{
			if (var->map[map.i][map.j] == 'S')
			{
				if (i % 3 == 1)
					move_x(var, &map);
				else if (i % 3 == 0)
					move_y(var, &map);
				i++;
			}
			map.j++;
		}
		map.i++;
	}
}

void	move_S(t_var *var)
{
	static int	k = 0;
	static int	i = 0;

	if (k == 20)
	{
		if (i < 50)
			read_map(var, 1);
		else
			read_map(var, 3);
	}
	if (k == 20)
		k = -1;
	if (i == 100)
		i = -1;
	k++;
	i++;
}
