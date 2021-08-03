/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 11:30:36 by asebrech          #+#    #+#             */
/*   Updated: 2021/08/03 14:54:59 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_left(t_var *var, t_map *map)
{
	if (var->map[map->i][map->j - 1] == 'S')
		key_hook(53, var);
	if (var->map[map->i][map->j - 1] == 'C')
		var->nbC -= 1;
	if (var->map[map->i][map->j - 1] == 'E' && var->nbC == 0)
		key_hook(53, var);
	if (var->map[map->i][map->j - 1] != '1' &&
			var->map[map->i][map->j - 1] != 'E')
	{
		ft_memset(var->map[map->i] + map->j, '0', 1);
		ft_memset(var->map[map->i] + map->j - 1, 'P', 1);
		print_map(var);
		var->mv += 1;
	}
}

static void	move_right(t_var *var, t_map *map)
{
	if (var->map[map->i][map->j + 1] == 'S')
		key_hook(53, var);
	if (var->map[map->i][map->j + 1] == 'C')
		var->nbC -= 1;
	if (var->map[map->i][map->j + 1] == 'E' && var->nbC == 0)
		key_hook(53, var);
	if (var->map[map->i][map->j + 1] != '1' &&
		var->map[map->i][map->j + 1] != 'E')
	{
		ft_memset(var->map[map->i] + map->j, '0', 1);
		ft_memset(var->map[map->i] + map->j + 1, 'P', 1);
		print_map(var);
		var->mv += 1;
	}
}

static void	move_down(t_var *var, t_map *map)
{
	if (var->map[map->i + 1][map->j] == 'S')
		key_hook(53, var);
	if (var->map[map->i + 1][map->j] == 'C')
		var->nbC -= 1;
	if (var->map[map->i + 1][map->j] == 'E' && var->nbC == 0)
		key_hook(53, var);
	if (var->map[map->i + 1][map->j] != '1' &&
		var->map[map->i + 1][map->j] != 'E')
	{
		ft_memset(var->map[map->i] + map->j, '0', 1);
		ft_memset(var->map[map->i + 1] + map->j, 'P', 1);
		print_map(var);
		var->mv += 1;
	}
}

static void	move_up(t_var *var, t_map *map)
{
	if (var->map[map->i - 1][map->j] == 'S')
		key_hook(53, var);
	if (var->map[map->i - 1][map->j] == 'C')
		var->nbC -= 1;
	if (var->map[map->i - 1][map->j] == 'E' && var->nbC == 0)
		key_hook(53, var);
	if (var->map[map->i - 1][map->j] != '1' &&
		var->map[map->i - 1][map->j] != 'E')
	{
		ft_memset(var->map[map->i] + map->j, '0', 1);
		ft_memset(var->map[map->i - 1] + map->j, 'P', 1);
		print_map(var);
		var->mv += 1;
	}
}

void	move(t_var *var, int keycode)
{
	t_map	map;

	map = found_P(var);
	animation_mvP(var);
	if (keycode == 126 || keycode == 13)
		move_up(var, &map);
	if (keycode == 125 || keycode == 1)
		move_down(var, &map);
	if (keycode == 123 || keycode == 0)
		move_left(var, &map);
	if (keycode == 124 || keycode == 2)
		move_right(var, &map);
}
