/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 11:46:21 by asebrech          #+#    #+#             */
/*   Updated: 2021/08/04 12:42:51 by asebrech         ###   ########.fr       */
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

static int	ft_close(int keycode, t_var *var)
{
	keycode = 0;
	var = NULL;
	exit(0);
	return (0);
}

static void	check_arg(char *str, t_var *var)
{
	int	len;

	len = ft_strlen(str);
	if (len <= 4 || !(ft_strnstr(&str[len - 4], ".ber", 4)))
		ft_exit("Wrong argument format");
	if (open(str, O_DIRECTORY) > 0)
		ft_exit(".ber is not a file");
	if (open(str, O_RDONLY) <= 0)
		ft_exit(".ber not found or not valid");
	var->ber = str;
}

int	main(int argc, char **argv)
{
	t_var	var;

	if (argc == 2)
	{
		var = init_var();
		var.x = 1000;
		var.y = 1000;
		check_arg(argv[1], &var);
		ft_parsing(&var);
		var.mlx = mlx_init();
		var.win = mlx_new_window(var.mlx, var.x, var.y, "so_long");
		open_img(&var);
		print_map(&var);
		mlx_hook(var.win, 2, 1L << 0, key_hook, &var);
		mlx_hook(var.win, 17, 1L << 15, ft_close, &var);
		mlx_loop(var.mlx);
	}
	else
		printf("so_long need one argument\n");
}
