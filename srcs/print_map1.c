/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 11:30:21 by asebrech          #+#    #+#             */
/*   Updated: 2021/08/05 16:08:33 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	print_img_1(t_var *var, int i, int j)
{
	mlx_put_image_to_window(var->mlx, var->win, var->F,
		32 * j + var->x / 2, 32 * i + var->y / 2);
	mlx_put_image_to_window(var->mlx, var->win, var->P,
		32 * j + var->x / 2, 32 * i + var->y / 2);
}

void	print_img(t_var *var, int i, int j, t_map *map)
{
	if (32 * j + var->x / 2 <= var->x && 32 * i + var->y / 2 <= var->y
		&& 32 * j + var->x / 2 >= 0 && 32 * i + var->y / 2 >= 0)
	{
		if (var->map[map->i][map->j] == '1')
			mlx_put_image_to_window(var->mlx, var->win,
				var->W, 32 * j + var->x / 2, 32 * i + var->y / 2);
		if (var->map[map->i][map->j] == '0')
			mlx_put_image_to_window(var->mlx, var->win,
				var->F, 32 * j + var->x / 2, 32 * i + var->y / 2);
		if (var->map[map->i][map->j] == 'C')
		{
			mlx_put_image_to_window(var->mlx, var->win,
				var->F, 32 * j + var->x / 2, 32 * i + var->y / 2);
			mlx_put_image_to_window(var->mlx, var->win,
				var->C, 32 * j + var->x / 2, 32 * i + var->y / 2);
		}
		if (var->map[map->i][map->j] == 'E')
			mlx_put_image_to_window(var->mlx, var->win, var->E,
				32 * j + var->x / 2, 32 * i + var->y / 2);
		if (var->map[map->i][map->j] == 'P')
			print_img_1(var, i, j);
	}
}
