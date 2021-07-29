/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:37:24 by asebrech          #+#    #+#             */
/*   Updated: 2021/07/29 10:38:18 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_img(t_var *var, int i, int j, t_map *map)
{
	if (var->map[map->i][map->j] == '1')
		mlx_put_image_to_window(var->mlx, var->win,
			var->W, 16 * j + var->x / 2, 16 * i + var->y / 2);
	if (var->map[map->i][map->j] == '0')
		mlx_put_image_to_window(var->mlx, var->win,
			var->F, 16 * j + var->x / 2, 16 * i + var->y / 2);
	if (var->map[map->i][map->j] == 'C')
	{
		mlx_put_image_to_window(var->mlx, var->win,
			var->F, 16 * j + var->x / 2, 16 * i + var->y / 2);
		mlx_put_image_to_window(var->mlx, var->win,
			var->C, 16 * j + var->x / 2, 16 * i + var->y / 2);
	}
	if (var->map[map->i][map->j] == 'E')
		mlx_put_image_to_window(var->mlx, var->win, var->E,
			16 * j + var->x / 2, 16 * i + var->y / 2);
	if (var->map[map->i][map->j] == 'P')
	{
		mlx_put_image_to_window(var->mlx, var->win, var->F,
			16 * j + var->x / 2, 16 * i + var->y / 2);
		mlx_put_image_to_window(var->mlx, var->win, var->P,
			16 * j + var->x / 2, 16 * i + var->y / 2);
	}
}

static void	print_right_up(t_var *var)
{
	int		i;
	int		j;
	int		k;
	t_map	map;

	map = found_P(var);
	k = map.j;
	i = 0;
	while (map.i + 1)
	{
		map.j = k;
		j = 0;
		while (map.j < var->len)
		{
			print_img(var, i, j, &map);
			map.j++;
			j++;
		}
		map.i--;
		i--;
	}
}

static void	print_left_down(t_var *var)
{
	int		i;
	int		j;
	int		k;
	t_map	map;

	map = found_P(var);
	k = map.j;
	i = 0;
	while (map.i < var->line)
	{
		map.j = k;
		j = 0;
		while (map.j < var->len)
		{
			print_img(var, i, j, &map);
			map.j++;
			j++;
		}
		map.i++;
		i++;
	}
}

static void	print_right_down(t_var *var)
{
	int		i;
	int		j;
	int		k;
	t_map	map;

	map = found_P(var);
	k = map.j;
	i = 0;
	while (map.i < var->line)
	{
		map.j = k;
		j = 0;
		while (map.j + 1)
		{
			print_img(var, i, j, &map);
			map.j--;
			j--;
		}
		map.i++;
		i++;
	}
}

void	print_map(t_var *var)
{
	int		i;
	int		j;
	int		k;
	t_map	map;

	mlx_clear_window(var->mlx, var->win);
	map = found_P(var);
	k = map.j;
	i = 0;
	while (map.i + 1)
	{
		j = 0;
		map.j = k;
		while (map.j + 1)
		{
			print_img(var, i, j, &map);
			map.j--;
			j--;
		}
		map.i--;
		i--;
	}
	print_right_down(var);
	print_right_up(var);
	print_left_down(var);
}
