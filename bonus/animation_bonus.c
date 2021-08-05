/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 12:54:11 by asebrech          #+#    #+#             */
/*   Updated: 2021/08/05 17:46:29 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animation_P(t_var *var)
{
	static int	i = 0;

	if (i == 10)
		var->P = var->aP.P;
	else if (i == 20)
		var->P = var->aP.P1;
	else if (i == 30)
		var->P = var->aP.P2;
	else if (i == 40)
		var->P = var->aP.P3;
	else if (i == 50)
		var->P = var->aP.P4;
	else if (i == 60)
		var->P = var->aP.P5;
	else if (i == 70)
		i = 0;
	i++;
}

void	animation_S(t_var *var)
{
	static int	i = 0;

	if (i == 10)
		var->S = var->aS.S;
	else if (i == 20)
		var->S = var->aS.S1;
	else if (i == 30)
		var->S = var->aS.S2;
	else if (i == 40)
		var->S = var->aS.S3;
	else if (i == 50)
		var->S = var->aS.S4;
	else if (i == 60)
		var->S = var->aS.S5;
	else if (i == 70)
		i = 0;
	i++;
}

void	animation_mvP(t_var *var)
{
	static int	i = 0;

	if (i == 1)
		var->P = var->mvP.P0;
	else if (i == 2)
		var->P = var->mvP.P1;
	else if (i == 3)
		var->P = var->mvP.P2;
	else if (i == 4)
		var->P = var->mvP.P3;
	else if (i == 5)
		var->P = var->mvP.P4;
	else if (i == 6)
	{
		var->P = var->mvP.P5;
		i = 0;
	}
	i++;
}
