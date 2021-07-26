/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:51:08 by asebrech          #+#    #+#             */
/*   Updated: 2021/07/26 16:17:57 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
}				t_vars;

typedef struct s_map
{
	int		line;
	int		len;
	char	**map;
	int		E;
	int		C;
	int		P;
}				t_map;

typedef struct s_img
{
	int		x;
	int		y;
	void	*W;
	void	*F;
	void	*C;
	void	*E;
	void	*P;
}				t_img;

t_map	ft_parsing(void);
void	ft_exit(char *str);
void	print_map(t_vars *vars, t_map *map, t_img *img);

#endif
