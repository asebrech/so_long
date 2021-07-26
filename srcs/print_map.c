/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:37:24 by asebrech          #+#    #+#             */
/*   Updated: 2021/07/26 16:34:18 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_E(t_vars *vars, t_img *img, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img->E, 16 * j, 16 * i);
}

static void	print_P(t_vars *vars, t_img *img, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img->F, 16 * j, 16 * i);
	mlx_put_image_to_window(vars->mlx, vars->win, img->P, 16 * j, 16 * i);
}

static void	print_C(t_vars *vars, t_img *img, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img->F, 16 * j, 16 * i);
	mlx_put_image_to_window(vars->mlx, vars->win, img->C, 16 * j, 16 * i);
}

void	print_map(t_vars *vars, t_map *map, t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->line)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win,
					img->W, 16 * j, 16 * i);
			if (map->map[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win,
					img->F, 16 * j, 16 * i);
			if (map->map[i][j] == 'C')
				print_C(vars, img, i, j);
			if (map->map[i][j] == 'E')
				print_E(vars, img, i, j);
			if (map->map[i][j] == 'P')
				print_P(vars, img, i, j);
			j++;
		}
		i++;
	}
}
