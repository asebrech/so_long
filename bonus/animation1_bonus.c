/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:31:34 by asebrech          #+#    #+#             */
/*   Updated: 2021/08/05 17:43:14 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_P(t_var *var)
{
	{
		var->aP.P = mlx_xpm_file_to_image(var->mlx,
				"./img/P.xpm", &var->w, &var->h);
		var->aP.P1 = mlx_xpm_file_to_image(var->mlx,
				"./img/P1.xpm", &var->w, &var->h);
		var->aP.P2 = mlx_xpm_file_to_image(var->mlx,
				"./img/P2.xpm", &var->w, &var->h);
		var->aP.P3 = mlx_xpm_file_to_image(var->mlx,
				"./img/P3.xpm", &var->w, &var->h);
		var->aP.P4 = mlx_xpm_file_to_image(var->mlx,
				"./img/P4.xpm", &var->w, &var->h);
		var->aP.P5 = mlx_xpm_file_to_image(var->mlx,
				"./img/P5.xpm", &var->w, &var->h);
	}
}

void	init_mvP(t_var *var)
{
	{
		var->mvP.P0 = mlx_xpm_file_to_image(var->mlx,
				"./img/mvP0.xpm", &var->w, &var->h);
		var->mvP.P1 = mlx_xpm_file_to_image(var->mlx,
				"./img/mvP1.xpm", &var->w, &var->h);
		var->mvP.P2 = mlx_xpm_file_to_image(var->mlx,
				"./img/mvP2.xpm", &var->w, &var->h);
		var->mvP.P3 = mlx_xpm_file_to_image(var->mlx,
				"./img/mvP3.xpm", &var->w, &var->h);
		var->mvP.P4 = mlx_xpm_file_to_image(var->mlx,
				"./img/mvP4.xpm", &var->w, &var->h);
		var->mvP.P5 = mlx_xpm_file_to_image(var->mlx,
				"./img/mvP5.xpm", &var->w, &var->h);
	}
}

void	init_S(t_var *var)
{
	{
		var->aS.S = mlx_xpm_file_to_image(var->mlx,
				"./img/S.xpm", &var->w, &var->h);
		var->aS.S1 = mlx_xpm_file_to_image(var->mlx,
				"./img/S1.xpm", &var->w, &var->h);
		var->aS.S2 = mlx_xpm_file_to_image(var->mlx,
				"./img/S2.xpm", &var->w, &var->h);
		var->aS.S3 = mlx_xpm_file_to_image(var->mlx,
				"./img/S3.xpm", &var->w, &var->h);
		var->aS.S4 = mlx_xpm_file_to_image(var->mlx,
				"./img/S4.xpm", &var->w, &var->h);
		var->aS.S5 = mlx_xpm_file_to_image(var->mlx,
				"./img/S5.xpm", &var->w, &var->h);
	}
}
