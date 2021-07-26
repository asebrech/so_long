/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 11:46:21 by asebrech          #+#    #+#             */
/*   Updated: 2021/07/26 16:37:01 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	open_img(t_vars *vars)
{
	t_img	img;

	img.W = mlx_xpm_file_to_image(vars->mlx, "./img/W.xpm", &img.x, &img.y);
	img.F = mlx_xpm_file_to_image(vars->mlx, "./img/F.xpm", &img.x, &img.y);
	img.C = mlx_xpm_file_to_image(vars->mlx, "./img/C.xpm", &img.x, &img.y);
	img.E = mlx_xpm_file_to_image(vars->mlx, "./img/E.xpm", &img.x, &img.y);
	img.P = mlx_xpm_file_to_image(vars->mlx, "./img/P.xpm", &img.x, &img.y);
	return (img);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	ft_close(int keycode, t_vars *vars)
{
	keycode = 0;
	vars = NULL;
	exit(0);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_map	map;
	t_img	img;

	vars.x = 500;
	vars.y = 500;
	map = ft_parsing();
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.x, vars.y, "so_long");
	img = open_img(&vars);
	print_map(&vars, &map, &img);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 15, ft_close, &vars);
	mlx_loop(vars.mlx);
}
