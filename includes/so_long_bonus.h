/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 11:31:52 by asebrech          #+#    #+#             */
/*   Updated: 2021/08/05 18:26:33 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct s_P
{
	void	*P;
	void	*P1;
	void	*P2;
	void	*P3;
	void	*P4;
	void	*P5;
}				t_P;

typedef struct s_S
{
	void	*S;
	void	*S1;
	void	*S2;
	void	*S3;
	void	*S4;
	void	*S5;
}				t_S;

typedef struct s_mvP
{
	void	*P0;
	void	*P1;
	void	*P2;
	void	*P3;
	void	*P4;
	void	*P5;
}				t_mvP;

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
	int		nbS;
	int		w;
	int		h;
	void	*W;
	void	*F;
	void	*C;
	void	*E;
	void	*P;
	void	*S;
	int		mv;
	char	*ber;
	t_P		aP;
	t_S		aS;
	t_mvP	mvP;
}				t_var;

typedef struct s_map
{
	int	i;
	int	j;
}				t_map;

int		get_next_line(int fd, char **line);
int		key_hook(int keycode, t_var *var);
t_var	init_var(void);
t_map	found_P(t_var *var);
t_map	found_S(t_var *var);
void	move(t_var *var, int keycode);
void	ft_parsing(t_var *var);
void	ft_exit(char *str);
void	print_map(t_var *var);
void	animation_P(t_var *var);
void	animation_S(t_var *var);
void	animation_mvP(t_var *var);
void	print_img(t_var *var, int i, int j, t_map *map);
void	move_S(t_var *var);
void	move_left_S(t_var *var, t_map *map);
void	move_right_S(t_var *var, t_map *map);
void	move_up_S(t_var *var, t_map *map);
void	move_down_S(t_var *var, t_map *map);
void	init_P(t_var *var);
void	init_mvP(t_var *var);
void	init_S(t_var *var);

#endif
