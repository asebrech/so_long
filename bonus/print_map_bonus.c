/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 11:30:21 by asebrech          #+#    #+#             */
/*   Updated: 2021/08/03 15:00:15 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

static void	print_left_up(t_var *var)
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
}

void	print_map(t_var *var)
{
	mlx_clear_window(var->mlx, var->win);
	print_right_down(var);
	print_right_up(var);
	print_left_down(var);
	print_left_up(var);
	mlx_string_put(var->mlx, var->win, var->x / 2, 0,
		0X00FF0000, (char *)ft_itoa(var->mv));
}
