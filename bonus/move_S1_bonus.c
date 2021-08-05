/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_S1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 12:37:21 by asebrech          #+#    #+#             */
/*   Updated: 2021/08/05 18:18:40 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_left_S(t_var *var, t_map *map)
{
	if (var->map[map->i][map->j - 1] == 'P')
	{
		printf("You lose !..\n");
		key_hook(53, var);
	}
	if (var->map[map->i][map->j - 1] == '0')
	{
		ft_memset(var->map[map->i] + map->j, '0', 1);
		ft_memset(var->map[map->i] + map->j - 1, 'S', 1);
		print_map(var);
	}
}

void	move_right_S(t_var *var, t_map *map)
{
	if (var->map[map->i][map->j + 1] == 'P')
	{
		printf("You lose !..\n");
		key_hook(53, var);
	}
	if (var->map[map->i][map->j + 1] == '0')
	{
		ft_memset(var->map[map->i] + map->j, '0', 1);
		ft_memset(var->map[map->i] + map->j + 1, 'S', 1);
		print_map(var);
	}
}

void	move_down_S(t_var *var, t_map *map)
{
	if (var->map[map->i + 1][map->j] == 'P')
	{
		printf("You lose !..\n");
		key_hook(53, var);
	}
	if (var->map[map->i + 1][map->j] == '0')
	{
		ft_memset(var->map[map->i] + map->j, '0', 1);
		ft_memset(var->map[map->i + 1] + map->j, 'S', 1);
		print_map(var);
	}
}

void	move_up_S(t_var *var, t_map *map)
{
	if (var->map[map->i - 1][map->j] == 'P')
	{
		printf("You lose !..\n");
		key_hook(53, var);
	}
	if (var->map[map->i - 1][map->j] == '0')
	{
		ft_memset(var->map[map->i] + map->j, '0', 1);
		ft_memset(var->map[map->i - 1] + map->j, 'S', 1);
		print_map(var);
	}
}
