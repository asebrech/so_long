/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 15:32:06 by asebrech          #+#    #+#             */
/*   Updated: 2021/07/29 10:42:35 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_char(t_var *var, char c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
		ft_exit("Forbidden character in the map\n");
	if (c == 'E')
		var->nbE += 1;
	if (c == 'C')
		var->nbC += 1;
	if (c == 'P')
		var->nbP += 1;
}

static void	parsing_map(t_var *var)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	var->len = ft_strlen(var->map[0]);
	while (i < var->line)
	{
		j = 0;
		len = ft_strlen(var->map[i]);
		if (var->len != len)
			ft_exit("The map must be rectangular\n");
		if (var->map[i][0] != '1' || var->map[i][len - 1] != '1')
			ft_exit("The map must be closed/surrounded by walls\n");
		while (var->map[i][j])
		{
			if (i == 0 || i == var->line - 1)
				if (var->map[i][j] != '1')
					ft_exit("The map must be closed/surrounded by walls\n");
			check_char(var, var->map[i][j]);
			j++;
		}
		i++;
	}
}

static void	get_map(t_var *var)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	fd = open("./srcs/map.ber", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		var->line++;
		free(line);
		line = NULL;
	}
	free(line);
	var->map = malloc(sizeof(char *) * var->line + 1);
	if (!var->map)
		ft_exit("Memory Allocation Error\n");
	fd = open("./srcs/map.ber", O_RDONLY);
	var->map[i] = NULL;
	while (get_next_line(fd, &var->map[i]))
	{
		i++;
		var->map[i] = NULL;
	}
}

void	ft_parsing(t_var *var)
{
	int		i;

	i = 0;
	get_map(var);
	parsing_map(var);
	if (var->nbE <= 0 || var->nbC <= 0 || var->nbP != 1)
		ft_exit("The map must have at least one 'E' one 'C' and ONE 'P'\n");
}
