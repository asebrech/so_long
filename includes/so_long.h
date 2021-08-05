/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:51:08 by asebrech          #+#    #+#             */
/*   Updated: 2021/08/05 16:09:29 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 500
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "../libft/libft.h"

typedef struct s_var
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		line;
	int		len;
	char	**map;
	int		nbE;
	int		nbC;
	int		nbP;
	int		w;
	int		h;
	void	*W;
	void	*F;
	void	*C;
	void	*E;
	void	*P;
	int		mv;
	char	*ber;
}				t_var;

typedef struct s_map
{
	int	i;
	int	j;
}				t_map;

int		key_hook(int keycode, t_var *var);
t_var	init_var(void);
t_map	found_P(t_var *var);
void	move(t_var *var, int keycode);
void	ft_parsing(t_var *var);
void	ft_exit(char *str);
void	print_map(t_var *var);
void	print_img(t_var *var, int i, int j, t_map *map);

#endif
