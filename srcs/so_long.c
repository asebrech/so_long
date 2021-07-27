/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 11:46:21 by asebrech          #+#    #+#             */
/*   Updated: 2021/07/27 14:15:18 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	open_img(t_var *var)
{
	var->W = mlx_xpm_file_to_image(var->mlx, "./img/W.xpm", &var->w, &var->h);
	var->F = mlx_xpm_file_to_image(var->mlx, "./img/F.xpm", &var->w, &var->h);
	var->C = mlx_xpm_file_to_image(var->mlx, "./img/C.xpm", &var->w, &var->h);
	var->E = mlx_xpm_file_to_image(var->mlx, "./img/E.xpm", &var->w, &var->h);
	var->P = mlx_xpm_file_to_image(var->mlx, "./img/P.xpm", &var->w, &var->h);
}

int	key_hook(int keycode, t_var *var)
{
	if (keycode == 53)
	{
		mlx_destroy_window(var->mlx, var->win);
		exit(0);
	}
	else
		move(var, keycode);
	return (0);
}

static int	ft_close(int keycode, t_var *var)
{
	keycode = 0;
	var = NULL;
	exit(0);
	return (0);
}

int	main(void)
{
	t_var	var;

	var = init_var();
	var.x = 500;
	var.y = 500;
	ft_parsing(&var);
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, var.x, var.y, "so_long");
	open_img(&var);
	print_map(&var);
	mlx_hook(var.win, 2, 1L << 0, key_hook, &var);
	mlx_hook(var.win, 17, 1L << 15, ft_close, &var);
	mlx_loop(var.mlx);
}
