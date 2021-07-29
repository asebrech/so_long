/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 12:54:11 by asebrech          #+#    #+#             */
/*   Updated: 2021/07/29 16:53:14 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animation_P(t_var *var)
{
	static int	i = 0;

	if (i == 10)
		var->P = mlx_xpm_file_to_image(var->mlx,
				"./img/P.xpm", &var->w, &var->h);
	else if (i == 20)
		var->P = mlx_xpm_file_to_image(var->mlx,
				"./img/P1.xpm", &var->w, &var->h);
	else if (i == 30)
		var->P = mlx_xpm_file_to_image(var->mlx,
				"./img/P2.xpm", &var->w, &var->h);
	else if (i == 40)
		var->P = mlx_xpm_file_to_image(var->mlx,
				"./img/P3.xpm", &var->w, &var->h);
	else if (i == 50)
		var->P = mlx_xpm_file_to_image(var->mlx,
				"./img/P4.xpm", &var->w, &var->h);
	else if (i == 60)
		var->P = mlx_xpm_file_to_image(var->mlx,
				"./img/P5.xpm", &var->w, &var->h);
	else if (i == 70)
		i = 0;
	print_map(var);
	i++;
}

void	animation_mvP(t_var *var)
{
	static int	i = 0;

	if (i == 0)
		var->P = mlx_xpm_file_to_image(var->mlx,
				"./img/mvP0.xpm", &var->w, &var->h);
	else if (i == 1)
		var->P = mlx_xpm_file_to_image(var->mlx,
				"./img/mvP1.xpm", &var->w, &var->h);
	else if (i == 2)
		var->P = mlx_xpm_file_to_image(var->mlx,
				"./img/mvP2.xpm", &var->w, &var->h);
	else if (i == 3)
		var->P = mlx_xpm_file_to_image(var->mlx,
				"./img/mvP3.xpm", &var->w, &var->h);
	else if (i == 4)
		var->P = mlx_xpm_file_to_image(var->mlx,
				"./img/mvP4.xpm", &var->w, &var->h);
	else if (i == 5)
	{
		var->P = mlx_xpm_file_to_image(var->mlx,
				"./img/mvP5.xpm", &var->w, &var->h);
		i = -1;
	}
	i++;
}