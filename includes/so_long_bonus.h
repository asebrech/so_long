/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 11:31:52 by asebrech          #+#    #+#             */
/*   Updated: 2021/07/29 16:01:51 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define BUFFER_SIZE 500
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_img
{
	void	*mvP0;
	void	*mvP1;
	void	*mvP2;
	void	*mvP3;
	void	*mvP4;
	void	*mvP5;
}				t_img;

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
	void	*S;
	int		mv;
	char	*ber;
	t_img	img;
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
void	move(t_var *var, int keycode);
void	ft_parsing(t_var *var);
void	ft_exit(char *str);
void	print_map(t_var *var);
void	animation_P(t_var *var);
void	animation_mvP(t_var *var);

#endif