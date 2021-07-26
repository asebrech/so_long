/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:37:24 by asebrech          #+#    #+#             */
/*   Updated: 2021/07/26 17:53:52 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_E(t_var *var, int i, int j)
{
	mlx_put_image_to_window(var->mlx, var->win, var->E, 16 * j, 16 * i);
}

static void	print_P(t_var *var, int i, int j)
{
	mlx_put_image_to_window(var->mlx, var->win, var->F, 16 * j, 16 * i);
	mlx_put_image_to_window(var->mlx, var->win, var->P, 16 * j, 16 * i);
}

static void	print_C(t_var *var, int i, int j)
{
	mlx_put_image_to_window(var->mlx, var->win, var->F, 16 * j, 16 * i);
	mlx_put_image_to_window(var->mlx, var->win, var->C, 16 * j, 16 * i);
}

void	print_map(t_var *var)
{
	int	i;
	int	j;

	i = 0;
	while (i < var->line)
	{
		j = 0;
		while (var->map[i][j])
		{
			if (var->map[i][j] == '1')
				mlx_put_image_to_window(var->mlx, var->win,
					var->W, 16 * j, 16 * i);
			if (var->map[i][j] == '0')
				mlx_put_image_to_window(var->mlx, var->win,
					var->F, 16 * j, 16 * i);
			if (var->map[i][j] == 'C')
				print_C(var, i, j);
			if (var->map[i][j] == 'E')
				print_E(var, i, j);
			if (var->map[i][j] == 'P')
				print_P(var, i, j);
			j++;
		}
		i++;
	}
}
