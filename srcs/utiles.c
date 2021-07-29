/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:08:07 by asebrech          #+#    #+#             */
/*   Updated: 2021/07/29 10:41:53 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(char *str)
{
	ft_putstr_fd("Error\n", 2);
	if (str)
		ft_putstr_fd(str, 2);
	exit(0);
}

t_map   found_P(t_var *var)
{
    t_map   map;

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

int key_hook(int keycode, t_var *var)
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

t_var	init_var(void)
{
	t_var	var;

	var.mlx = NULL;
	var.win = NULL;
	var.x = 0;
	var.y = 0;
	var.line = 0;
	var.len = 0;
	var.map = NULL;
	var.nbE = 0;
	var.nbC = 0;
	var.nbP = 0;
	var.w = 0;
	var.h = 0;
	var.W = NULL;
	var.F = NULL;
	var.C = NULL;
	var.E = NULL;
	var.P = NULL;
	var.mv = 0;
	return (var);
}
