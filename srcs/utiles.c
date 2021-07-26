/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:08:07 by asebrech          #+#    #+#             */
/*   Updated: 2021/07/26 17:54:26 by asebrech         ###   ########.fr       */
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
	var.a = 0;
	var.b = 0;
	var.c = 0;
	var.w = 0;
	var.h = 0;
	var.W = NULL;
	var.F = NULL;
	var.C = NULL;
	var.E = NULL;
	var.P = NULL;
	return (var);
}
