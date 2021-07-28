/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 10:01:11 by asebrech          #+#    #+#             */
/*   Updated: 2021/07/28 14:13:45 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	found_P(t_var *var)
{
	t_map	map;

	map.i = 0;
	while (map.i < var->line)
	{
		map.j = 0;
		while (var->map[map.i][map.j])
		{
			if (var->map[map.i][map.j] == 'P')
				return (map);
			map.j++;
		}
		map.i++;
	}
	return (map);
}

static void	move_left(t_var *var, t_map *map)
{
	if (var->map[map->i][map->j - 1] == 'C')
		var->b -= 1;
	if (var->map[map->i][map->j - 1] == 'E' && var->b == 0)
		key_hook(53, var);
	if (var->map[map->i][map->j - 1] != '1' &&
			var->map[map->i][map->j - 1] != 'E')
	{
		ft_memset(var->map[map->i] + map->j, '0', 1);
		ft_memset(var->map[map->i] + map->j - 1, 'P', 1);
		print_map(var);
		var->m += 1;
		printf("move :	%d\n", var->m);
	}
}

static void	move_right(t_var *var, t_map *map)
{
	if (var->map[map->i][map->j + 1] == 'C')
		var->b -= 1;
	if (var->map[map->i][map->j + 1] == 'E' && var->b == 0)
		key_hook(53, var);
	if (var->map[map->i][map->j + 1] != '1' &&
		var->map[map->i][map->j + 1] != 'E')
	{
		ft_memset(var->map[map->i] + map->j, '0', 1);
		ft_memset(var->map[map->i] + map->j + 1, 'P', 1);
		print_map(var);
		var->m += 1;
		printf("move :	%d\n", var->m);
	}
}

static void	move_down(t_var *var, t_map *map)
{
	if (var->map[map->i + 1][map->j] == 'C')
		var->b -= 1;
	if (var->map[map->i + 1][map->j] == 'E' && var->b == 0)
		key_hook(53, var);
	if (var->map[map->i + 1][map->j] != '1' &&
		var->map[map->i + 1][map->j] != 'E')
	{
		ft_memset(var->map[map->i] + map->j, '0', 1);
		ft_memset(var->map[map->i + 1] + map->j, 'P', 1);
		print_map(var);
		var->m += 1;
		printf("move :	%d\n", var->m);
	}
}

void	move(t_var *var, int keycode)
{
	t_map	map;

	map = found_P(var);
	if (keycode == 126)
	{
		if (var->map[map.i - 1][map.j] == 'C')
			var->b -= 1;
		if (var->map[map.i - 1][map.j] == 'E' && var->b == 0)
			key_hook(53, var);
		if (var->map[map.i - 1][map.j] != '1' &&
			var->map[map.i - 1][map.j] != 'E')
		{
			ft_memset(var->map[map.i] + map.j, '0', 1);
			ft_memset(var->map[map.i - 1] + map.j, 'P', 1);
			print_map(var);
			var->m += 1;
			printf("move :	%d\n", var->m);
		}
	}
	if (keycode == 125)
		move_down(var, &map);
	if (keycode == 123)
		move_left(var, &map);
	if (keycode == 124)
		move_right(var, &map);
}
