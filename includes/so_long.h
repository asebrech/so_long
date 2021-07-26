/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:51:08 by asebrech          #+#    #+#             */
/*   Updated: 2021/07/26 17:39:59 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct s_var
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		line;
	int		len;
	char	**map;
	int		a;
	int		b;
	int		c;
	int		w;
	int		h;
	void	*W;
	void	*F;
	void	*C;
	void	*E;
	void	*P;
}				t_var;

t_var	init_var(void);
void	ft_parsing(t_var *var);
void	ft_exit(char *str);
void	print_map(t_var *var);

#endif
